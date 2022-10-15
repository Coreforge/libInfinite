#include "Module.h"
#include <algorithm>
#include <cstdio>
#include <cstring>

int Module::loadModule(FILE* file, const char* name){
	fileHandle = file;



	if(path.empty()){
		// if path hasn't been set to the file path yet, just set it to the name
		path.assign(name);
	}



	this->name.assign(name);
	unsigned char* header = (unsigned char*)malloc(0x50);

	fseek(file,0x0,0);
	int s = fread(header,1,0x50,file);
	if(s != 0x50){
		logger->log(LOG_LEVEL_ERROR,"Could not read header for module %s!\nRead failed after 0x%x bytes (offset 0x%x)\n",path.c_str(),s,s);
		return -1;
	}

	if(memcmp(header,"mohd",4)){
		// magic doesn't match, don't load
		return -1;
	}

	//for(int i = 0; i < 0x40; i++) printf("%02hhx ",*(header+i));

	fileCount = *(uint32_t*)(header+0x10);	// offset 0x10 from start
	stringsSize = *(uint32_t*)(header + 0x24);
	table3Count = *(uint32_t*)(header + 0x28);
	blockCount = *(uint32_t*)(header + 0x2c);
	hd1_delta = *(uint64_t*)(header + 0x38);
	data_size = *(uint32_t*)(header + 0x40);
	//printf("File count: 0x%x\n",fileCount);
	//printf("Strings size: 0x%x\n",stringsSize);
	//printf("freeing header\n");
	free(header);	// the header isn't needed anymore, as all of the data has been copied
	//logger->log(LOG_LEVEL_DEBUG,"File count: 0x%x\n",fileCount);
	//logger->log(LOG_LEVEL_DEBUG,"Strings size: 0x%x\n",stringsSize);

	// if we have an hd1_delta that isn't 0, we should try to open the _hd1 file. If we can't, some files will be inaccessible
	if(hd1_delta != 0){
		hd1Handle = fopen((path + "_hd1").c_str(),"rb");
		if(!hd1Handle){
			logger->log(LOG_LEVEL_WARNING,"Missing _hd1 file for module %s\n",path.c_str());
		}else{
			logger->log(LOG_LEVEL_INFO,"Found _hd1 file for module %s\n",path.c_str());
		}
	}

	stringOffset = 0x48 + fileCount*0x58 + 0x8;
	blockTableOffset = stringOffset + stringsSize + table3Count*4;
	blockTable.offset = blockTableOffset;
	blockTable.count = blockCount;
	blockTable.module = this;

	// aligned to 0x1000 bytes
	uint64_t tmp = blockTableOffset + blockCount*0x14;
	if((tmp & 0xfff) == 0){
		dataOffset = tmp;
	} else {
		dataOffset = (tmp & 0xfffffffffffff000) + 0x1000;
	}

	// read all of the strings
	char* strings = (char*)malloc(stringsSize);
	fseek(file,stringOffset,0);
	fread(strings,1,stringsSize,file);
	//printf("read strings\n");
	// now that all of the offsets and counts are read, read the item information
	for(unsigned int f = 0; f < fileCount; f++){
		unsigned char* itm = (unsigned char*)malloc(0x58);
		int retry = 0;
		retry:
		uint64_t offset = 0x48 + f * 0x58;
		fseek(file,offset,SEEK_SET);
		int r = fread(itm,1,0x58,file);
		// this retry stuff isn't needed anymore. This issue happened on windows due to opening the files in text mode
		if(r != 0x58){
			retry++;
			logger->log(LOG_LEVEL_WARNING,"Did not read 0x58 bytes (instead 0x%x, stream at offset 0x%x) errno = %d Try %d\n",r,ftell(file));
			if(retry < 3){
				//goto retry;
			} else {
				logger->log(LOG_LEVEL_ERROR,"Tried reading item 3 times, skipping! (something isn't right. This shouldn't happen. It really shouldn't)\n");
				free(itm);
				continue;
			}
		}

		// this needs to be deleted again when this module is unloaded/discarded
		ModuleItem* item = new ModuleItem();
		item->blockCount = *((uint16_t*)(itm + 0xa));
		item->firstBlockIndex = *(uint32_t*)(itm + 0xc);
		item->dataOffset = (*((uint64_t*)(itm + 0x18)) & 0xffffffffffff) + dataOffset;	// only six bytes
		item->compressedSize = *(uint32_t*)(itm + 0x20);
		item->decompressedSize = *(uint32_t*)(itm + 0x24);
		item->stringOffset = *(uint32_t*)(itm + 0x40);
		item->module = this;

		//printf("Reading string length from 0x%x with a maximum of 0x%x bytes (0x%x bytes total) (file offset 0x%lx)\n",item->stringOffset,stringsSize - item->stringOffset, stringsSize,offset);
		// get the path of the item
		size_t len = strnlen(strings + item->stringOffset, stringsSize - item->stringOffset);
		item->path = std::string(strings + item->stringOffset, len);
		std::replace(item->path.begin(), item->path.end(), '\\', '/');

		// replace characters in file names that could cause issues
		std::replace(item->path.begin(), item->path.end(), ' ', '_');
		std::replace(item->path.begin(), item->path.end(), ':', '_');
		//printf("%s\n",strings + item->stringOffset);

		//finally add the item to the list of items
		items.insert(std::pair<std::string, ModuleItem*>(item->path, item));
		free(itm);
	}

	//printf("loaded strings");
	// read the information for all blocks
	for(unsigned int b = 0; b < blockCount; b++){
		uint64_t offset = blockTableOffset + b * 0x14;
		char* block = (char*)malloc(0x14);
		fseek(file,offset,0);
		fread(block,1,0x14,file);
		ModuleBlock* blockptr = new ModuleBlock();
		//memcpy(blockptr,block,0x10);	// just copy over the first 4 values, the layout is the same, and there are no gaps
		blockptr->compressedOffset = *(uint32_t*)(block);
		blockptr->compressedSize = *(uint32_t*)(block + 0x4);
		blockptr->decompressedOffset = *(uint32_t*)(block + 0x8);
		blockptr->decompressedSize = *(uint32_t*)(block+0xc);
		// isCompressed can't just be copied
		if(*(uint32_t*)(block+0x10) == 1){
			blockptr->isCompressed = true;
		} else {
			blockptr->isCompressed = false;
		}
		blockTable.blocks.emplace_back(blockptr);
		free(block);
	}
	free(strings);
	return 0;
}

int Module::loadModule(const char* path){
	FILE* file = fopen(path,"rb");
	this->path.assign(path);
	std::string name = std::string(path);
	std::replace(name.begin(), name.end(), '\\', '/');
	return loadModule(file, name.substr(name.rfind('/'), name.npos).c_str());
}
