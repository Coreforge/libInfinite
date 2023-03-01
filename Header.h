#pragma once


#include <stdint.h>


#include "TagRefTable.h"

class Header{

public:
	// all of these values are also present in the respective table classes, but since the header contains them, they are also present here
	uint32_t tagRefTableOffset;
	uint32_t tagRefTableCount;

	uint32_t dataTableOffset;
	uint32_t dataTableCount;

	uint32_t contentTableOffset;
	uint32_t contentTableCount;

	uint32_t dataBlockTableOffset;
	uint32_t dataBlockTableCount;

	uint32_t stringTableOffset;
	uint32_t stringDataOffset;
	uint32_t stringCount;
	uint32_t stringLength;

	// data referenced by the content table, area 1, metadata
	uint32_t dataOffset;
	uint32_t dataLength;

	// data typically referenced in other ways, for example by metadata blocks, area 2
	uint32_t data2Offset;
	uint32_t data2Length;

	// even more data (single level textures use this)
	uint32_t data3Offset;
	uint32_t data3Length;

	// this function expects the data to be at least 0x50 bytes long (anything beyond 0x50 is ignored)
	int parseHeader(uint8_t* data);
};
