#include "Header.h"

#include "Errors.h"

#include <cstring>

/*
 * Header:
 * Offset	Length	Content
 * 0x00		(0x04) 	Magic
 * 0x18		(0x04)	Tag Table Count
 * 0x1c		(0x04)	Data Table Count
 * 0x20		(0x04)	Content Table Count
 * 0x24		(0x04)	Data Block Table Count	(data reference)
 * 0x28		(0x04)	String Count
 * 0x2c		(0x04)	String Length
 * 0x30		(0x04)	Length of some field (likely has to do with tags)
 *
 * 0x38		(0x04)	Metadata Offset
 * 0x3c		(0x04)	Metadata Length
 * 0x40		(0x04)	Data Length
 * 0x44		(0x04)	Region 3 Length
 *
 *
 */

int Header::parseHeader(uint8_t* data){

	if(memcmp((const void*)data,"ucsh",4)){
		return ERROR_INVALID_HEADER;
	}
	// header matches so hopefully the file is ok

	tagRefTableOffset = 0x50;	// always after the header
	tagRefTableCount = *((uint32_t*) (data + 0x18));

	dataTableOffset = tagRefTableOffset + tagRefTableCount * 0x18;
	dataTableCount = *((uint32_t*) (data + 0x1c));

	contentTableOffset = dataTableOffset + dataTableCount * 0x10;
	contentTableCount = *((uint32_t*) (data + 0x20));

	dataBlockTableOffset = contentTableOffset + contentTableCount * 0x20;
	dataBlockTableCount = *((uint32_t*) (data + 0x24));

	stringTableOffset = dataBlockTableOffset + dataBlockTableCount * 0x14;
	stringCount = *((uint32_t*) (data + 0x28));
	stringLength = *((uint32_t*) (data + 0x2c));
	stringDataOffset = stringTableOffset + (stringCount * 0x10);

	dataOffset = *((uint32_t*) (data + 0x38));
	dataLength = *((uint32_t*) (data + 0x3c));

	data2Offset = dataOffset + dataLength;
	data2Length = *((uint32_t*) (data + 0x40));

	data3Offset = data2Offset + data2Length;
	data3Length = *((uint32_t*) (data + 0x44));

	return ERROR_NONE;
}
