#pragma once

#include <stdint.h>
#include <vector>
#include <string>

class TagRefFieldTableEntry{
public:
	std::string string;
	uint32_t fieldBlockIndex;	// this might not be a type, but idk what it is. Might be interesting though.
	uint32_t fieldBlockOffset;	// unknown purpose
	uint32_t index;	// some have invalid indicies
	uint32_t offset;

	TagRefFieldTableEntry(std::string string, uint32_t fieldBlockIndex, uint32_t fieldBlockOffset, uint32_t index, uint32_t offset){
		this->string = string;
		this->fieldBlockIndex = fieldBlockIndex;
		this->fieldBlockOffset = fieldBlockOffset;
		this->index = index;
		this->offset = offset;
	};
};

class TagRefFieldTable{
public:
	std::vector<TagRefFieldTableEntry> entries;

	// slightly larget memory footprint than necessary, but pointers were getting messed up, so this is easier
	std::vector<TagRefFieldTableEntry> strings;
	std::vector<TagRefFieldTableEntry> invalidStrings;	// strings without valid indicies.
	int readStrings(uint8_t* data, uint32_t count, uint32_t length, uint8_t* stringData, bool readStrings);
};
