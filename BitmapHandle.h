#pragma once

#include "module/ModuleItem.h"
#include "Item.h"

#include <memory>
#include <vector>
#include <stdint.h>

#include "logger/logger.h"

//NOTE: the mipmap level runs opposite to the resource index. MipMap 0 is the largest, but it uses the resource chunk with the highest index
class MipMap{
public:
	uint8_t level;
	uint16_t width;
	uint16_t height;
};

class Frame{
public:
	uint32_t width;
	uint32_t height;

	uint16_t format;
	uint32_t mipmapCount;
	Item* item;
	std::vector<MipMap> mipMaps;

	// get the raw data of this bitmap. Will need to be converted/decompressed for most usecases
	// the returned buffer is allocated, so it has to be freed
	void* getData(uint8_t level);	// level: Mipmap level, starting at 0

	// get the data of this bitmap in R8G8B8A8 format. This could lead to precision loss, but is the most useful for general applications
	// the returned buffer is allocated, so it has to be freed
	void* getR8G8B8A8Data(uint8_t level);
};

class BitmapHandle{
public:
	BitmapHandle(ModuleItem* moduleItem, Logger* logger);
	~BitmapHandle();

	uint32_t frameCount;
	std::vector<Frame> frames;

private:
	ModuleItem* moduleItem;
	Item* item;
	Logger* logger;
};
