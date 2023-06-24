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
	if(module->version < 0x34){	// this field isn't useful anymore past this version
		if(dataOffset > module->data_size){
			module->logger->log(LOG_LEVEL_ERROR,"Error: Data for %s is beyond the end of the module\n",path.c_str());
			free(data);
			return nullptr;
		}
	}
	//if(dataOffset > module->hd1_delta && module->hd1Handle){
	//printf("Item offset: 0x%lx\n",this->offset);
	if(module->version >= 0x34){
		// version 52+
		//printf("V52\n");
		if(flags & 1){
			//printf("hd1\n");
			if(!module->hd1Handle){
				module->logger->log(LOG_LEVEL_ERROR, "Error extracting %s, no hd1 file for module %s\n",path.c_str(),module->path.c_str());
				goto err;
			}
			//goto err;
			// item is in the _hd1 file and we have a valid hd1 file handle
			offset -= module->hd1_delta;
			handle = module->hd1Handle;
		} else {
			offset += module->dataOffset;
		}
	} else {
		// up to version 51
		offset += module->dataOffset;
		//printf("V51\n");
		if(flags & 1){
			if(!module->hd1Handle){
				module->logger->log(LOG_LEVEL_ERROR, "Error extracting %s, no hd1 file for module %s\n",path.c_str(),module->path.c_str());
				goto err;
			}
			//goto err;
			// item is in the _hd1 file and we have a valid hd1 file handle
			offset -= module->hd1_delta;
			handle = module->hd1Handle;
		}
	}
	clearerr(handle);
	if(blockCount != 0){
		// there are multiple blocks
		for(int b = firstBlockIndex; b < blockCount + firstBlockIndex; b++){
			if(!module->blockTable.blocks[b]->isCompressed){
				// not compressed, read straight into output buffer
				fseeko64(handle,offset + module->blockTable.blocks[b]->compressedOffset,0);
				size_t i = fread((void*)(data + module->blockTable.blocks[b]->decompressedOffset),1,module->blockTable.blocks[b]->compressedSize,handle);
				if(i != module->blockTable.blocks[b]->compressedSize){
					// something went wrong reading
					if(feof(handle)){
						goto err;
					}
					if(ferror(handle)){
						module->logger->log(LOG_LEVEL_ERROR,"An Error occured reading block data\n");
						goto err;
					}
					module->logger->log(LOG_LEVEL_ERROR,"Could not read enough block data. Weird.\n");
				}
			} else {
				// block is compressed, so it has to be decompressed first
				void* block = malloc(module->blockTable.blocks[b]->compressedSize);
				fseeko64(handle,offset + module->blockTable.blocks[b]->compressedOffset,0);
				size_t i = fread(block,1,module->blockTable.blocks[b]->compressedSize,handle);
				if(i != module->blockTable.blocks[b]->compressedSize){
					// something went wrong reading
					if(feof(handle)){
						free(block);
						goto err;
					}
					if(ferror(handle)){
						module->logger->log(LOG_LEVEL_ERROR,"An Error occured reading block data\n");
						free(block);
						goto err;
					}
					module->logger->log(LOG_LEVEL_ERROR,"Could not read enough block data. Weird.\n");
				}
				decompress(block, module->blockTable.blocks[b]->compressedSize, data + module->blockTable.blocks[b]->decompressedOffset, module->blockTable.blocks[b]->decompressedSize);
				free(block);
			}
		}
	} else {
		// one implied block
		void* block = malloc(compressedSize);
		fseeko64(handle,offset,SEEK_SET);
		size_t i = fread(block,1,compressedSize,handle);
		if(i != compressedSize){
			// something went wrong reading
			if(feof(handle)){
				free(block);
				goto err;
			}
			if(ferror(handle)){
				module->logger->log(LOG_LEVEL_ERROR,"An Error occured reading block data\n");
				free(block);
				goto err;
			}
			module->logger->log(LOG_LEVEL_ERROR,"Could not read enough block data. Weird.\n");
		}
		if(compressedSize == decompressedSize){
			memcpy(data,block,decompressedSize);
		} else {
			decompress(block, compressedSize, data, decompressedSize);
		}
		free(block);
	}
	return data;

	err:
	// error handler, in case something happens that means we can't read this item (like the data not actually being there and pointing beyond eof)
	free(data);
	return nullptr;
}
