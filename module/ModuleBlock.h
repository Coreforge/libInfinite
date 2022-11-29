#pragma once

#include <stdint.h>


class ModuleBlock{
public:
	uint32_t offset;
	uint32_t compressedOffset;
	uint32_t compressedSize;
	uint32_t decompressedOffset;
	uint32_t decompressedSize;
	bool isCompressed;
};
