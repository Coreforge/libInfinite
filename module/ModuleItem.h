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
	uint16_t blockCount;
	uint32_t firstBlockIndex;
	uint32_t compressedSize;
	uint32_t decompressedSize;
	uint32_t stringOffset;
	std::string path;

	Module* module;

	unsigned char* extractData();
};
