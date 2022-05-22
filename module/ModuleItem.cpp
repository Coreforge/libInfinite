#include "ModuleItem.h"
#include <stdint.h>
#include "Module.h"
#include "oodle.h"

unsigned char* ModuleItem::extractData(){
	unsigned char* data = (unsigned char*)malloc(decompressedSize);
	uint64_t offset = dataOffset;
	FILE* handle = module->fileHandle;
	// this assumes that a single item is either is the base module or the _hd1 and never split across the two files
	if(dataOffset > module->hd1_delta && module->hd1Handle){
		// item is in the _hd1 file and we have a valid hd1 file handle
		offset -= module->hd1_delta;
		handle = module->hd1Handle;
	}

	if(blockCount != 0){
		// there are multiple blocks
		for(int b = firstBlockIndex; b < blockCount + firstBlockIndex; b++){
			if(!module->blockTable.blocks[b]->isCompressed){
				// not compressed, read straight into output buffer
				fseeko64(handle,offset + module->blockTable.blocks[b]->compressedOffset,0);
				fread((void*)data,1,module->blockTable.blocks[b]->compressedSize,handle);
			} else {
				// block is compressed, so it has to be decompressed first
				void* block = malloc(module->blockTable.blocks[b]->compressedSize);
				fseeko64(handle,offset + module->blockTable.blocks[b]->compressedOffset,0);
				fread(block,1,module->blockTable.blocks[b]->compressedSize,handle);
				decompress(block, module->blockTable.blocks[b]->compressedSize, data + module->blockTable.blocks[b]->decompressedOffset, module->blockTable.blocks[b]->decompressedSize);
				free(block);
			}
		}
	} else {
		// one implied block
		void* block = malloc(compressedSize);
		fseeko64(handle,offset,0);
		fread(block,1,compressedSize,handle);
		decompress(block, compressedSize, data, decompressedSize);
		free(block);
	}
	return data;
}
