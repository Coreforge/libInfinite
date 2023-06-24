#include "TagRefTable.h"

#include "Errors.h"

#include <stdint.h>

int TagRefTable::readTable(uint8_t* data, uint32_t n, char* stringData){

/*
 *	Offset	Size	Function
 *  0x00	0x04	Tag type (4 chars, reversed)
 *  0x04	0x04	String offset into the string block
 * 	0x08	0x04	Ref ID Sub (?)
 * 	0x0c	0x04	Ref ID Center (?)
 * 	0x10	0x04	Ref ID (?)
 * 	0x14	0x04	Parent (?)
 */

	for(int i = 0; i < n; i++){
		uint32_t entryOffset = i * 0x18;
		uint32_t type = *((uint32_t*)(data + entryOffset));	// reading this as a uint32 since it's just 4 bytes, and this is easier than messing around with chars here
		uint32_t stringOffset = *((uint16_t*)(data + entryOffset + 0x4));
		uint64_t assetId = *((uint64_t*)(data + entryOffset + 0x8));
		uint32_t globalId = *((uint32_t*)(data + entryOffset + 0x10));
		uint32_t parent = *((uint32_t*)(data + entryOffset + 0x14));

		entries.emplace_back(TagRefTableEntry((char*)&type,stringOffset,assetId,globalId,parent,std::string(stringData + stringOffset)));
	}

	return ERROR_NONE;
}
