#pragma once

#include <stdint.h>
#include <vector>
#include <string>

class StringTableEntry{
public:
	std::string string;
	uint32_t type;	// this might not be a type, but idk what it is. Might be interesting though.
	uint32_t some_offset;	// unknown purpose
	uint32_t index;	// some have invalid indicies
	uint32_t offset;

	StringTableEntry(std::string string, uint32_t type, uint32_t some_offset, uint32_t index, uint32_t offset){
		this->string = string;
		this->type = type;
		this->some_offset = some_offset;
		this->index = index;
		this->offset = offset;
	};
};

class StringTable{
public:
	std::vector<StringTableEntry> strings;
	std::vector<StringTableEntry> invalidStrings;	// strings without valid indicies.
	int readStrings(uint8_t* data, uint32_t count, uint32_t length, uint8_t* stringData);
};
