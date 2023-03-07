#pragma once

#include <stdint.h>
#include "ModuleBlock.h"
#include <vector>
#include <string>


class Module;

class ModuleItem{
public:
	uint64_t offset;
	uint64_t dataOffset;
	uint16_t flags;
	uint16_t blockCount;
	uint32_t firstBlockIndex;
	uint32_t compressedSize;
	uint32_t decompressedSize;
	uint32_t stringOffset;
	uint32_t assetID;
	uint32_t parentIndex;
	uint32_t tagType;
	std::string path;
	ModuleItem* parent;

	// debugging/research stuff, not needed for normal operation
	uint32_t idx;

	std::vector<ModuleItem*> resources;


	Module* module;

	unsigned char* extractData();
};
