#pragma once

#include <stdint.h>
#include <vector>
#include <string>

// https://github.com/ElDewrito/AusarDocs/blob/master/FileFormats/CachedTag.md


class TagRefTableEntry{
public:
	char type[4];
	uint32_t stringOffset;
	uint32_t assetId;
	uint32_t globalId;
	uint32_t parent;
	std::string string;


	TagRefTableEntry(char type[4],uint32_t stringOffset, uint64_t assetId, uint32_t globalId, uint32_t parent, std::string string){
		this->type[0] = type[0];
		this->type[1] = type[1];
		this->type[2] = type[2];
		this->type[3] = type[3];
		this->stringOffset = stringOffset;
		this->assetId = assetId;
		this->globalId = globalId;
		this->parent = parent;
		this->string = string;
	}
};


class TagRefTable{

public:

	std::vector<TagRefTableEntry> entries;

	int readTable(uint8_t* data, uint32_t count, char* stringData);
};

