#pragma once

#include <stdint.h>

#include "../export.h"

extern "C"{
	// names should be self-explanatory
	// itemHandle is a pointer to the ModuleItem object, obtained from the module

	EXPORT_FUNC const char* getPath(void* itemHandle);
	EXPORT_FUNC uint32_t getDecompressedSize(void* itemHandle);
	EXPORT_FUNC uint32_t getCompressedSize(void* itemHandle);

	// returns: pointer to the decompressed data or null if an error occurred
	// data needs to be freed once it's not needed anymore (otherwise this can cause a memory leak)
	EXPORT_FUNC void* getData(void* itemHandle);
}
