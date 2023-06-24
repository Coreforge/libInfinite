#pragma once
#include <stdint.h>
#include <vector>

class DataRefTableEntry{
public:
	uint32_t parentCTIndex;
	uint32_t refIndex;	// index of the data block that is referenced
	uint32_t fieldBlockIndex;	// index of the data block where the other block is references
	uint32_t fieldOffset;	// offset in that block
};

class DataRefTable{
public:
	int readTable(uint8_t* data, uint32_t n);
	std::vector<DataRefTableEntry> entries;
};
