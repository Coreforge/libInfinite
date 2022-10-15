#include "ModuleItem.h"
#include <stdint.h>
#include "Module.h"
#include "oodle.h"
#include <cstring>

unsigned char* ModuleItem::extractData(){
	unsigned char* data = (unsigned char*)malloc(decompressedSize);
	uint64_t offset = dataOffset;
	FILE* handle = module->fileHandle;
	// this assumes that a single item is either is the base module or the _hd1 and never split across the two files
	if(dataOffset > module->data_size){
		module->logger->log(LOG_LEVEL_ERROR,"Error: Data for %s is beyond the end of the module\n",path.c_str());
		free(data);
		return nullptr;
	}
	if(dataOffset > module->hd1_delta && module->hd1Handle){
		if(!module->hd1Handle){
			module->logger->log(LOG_LEVEL_ERROR, "Error extracting %s, no hd1 file for module %s\n",path.c_str(),module->path.c_str());
			free(data);
			return nullptr;
		}
		// item is in the _hd1 file and we have a valid hd1 file handle
		offset -= module->hd1_delta;
		handle = module->hd1Handle;
	}
	if(blockCount != 0){
		// there are multiple blocks
		for(int b = firstBlockIndex; b < blockCount + firstBlockIndex; b++){
			if(!module->blockTable.blocks[b]->isCompressed){
				// not compressed, read straight into output buffer
				fseek(handle,offset + module->blockTable.blocks[b]->compressedOffset,0);
				fread((void*)data + module->blockTable.blocks[b]->decompressedOffset,1,module->blockTable.blocks[b]->compressedSize,handle);
			} else {
				// block is compressed, so it has to be decompressed first
				void* block = malloc(module->blockTable.blocks[b]->compressedSize);
				fseek(handle,offset + module->blockTable.blocks[b]->compressedOffset,0);
				fread(block,1,module->blockTable.blocks[b]->compressedSize,handle);
				decompress(block, module->blockTable.blocks[b]->compressedSize, data + module->blockTable.blocks[b]->decompressedOffset, module->blockTable.blocks[b]->decompressedSize);
				free(block);
			}
		}
	} else {
		// one implied block
		void* block = malloc(compressedSize);
		fseek(handle,offset,0);
		fread(block,1,compressedSize,handle);
		if(compressedSize == decompressedSize){
			memcpy(data,block,decompressedSize);
		} else {
			decompress(block, compressedSize, data, decompressedSize);
		}
		free(block);
	}
	return data;
}
