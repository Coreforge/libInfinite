#include "ModuleItemC.h"
#include "ModuleItem.h"

const char* getPath(void* itemHandle){
	ModuleItem* item = (ModuleItem*) itemHandle;
	return item->path.c_str();
}

uint32_t getDecompressedSize(void* itemHandle){
	ModuleItem* item = (ModuleItem*) itemHandle;
	return item->decompressedSize;
}

uint32_t getCompressedSize(void* itemHandle){
	ModuleItem* item = (ModuleItem*) itemHandle;
	return item->compressedSize;
}

void* getData(void* itemHandle){
	ModuleItem* item = (ModuleItem*) itemHandle;
	return item->extractData();
}
