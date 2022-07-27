#include "Item.h"

#include <cstdlib>
#include <cstring>

#include "Errors.h"

#define DUMP_DATA_TABLE true
#define DUMP_CONTENT_TABLE true
#define DUMP_STRING_TABLE true

Item::Item(uint8_t* data, uint32_t length, Logger* logger){

	this->logger = logger;
	// create a copy of the file. By doing this I don't need to keep track of which extracted buffer is still needed and which one can be freed
	// and it should only momentarily increase memory usage, unless an item gets opened multiple times without freeing it again first
	this->data = (uint8_t*)malloc(length);
	memcpy(this->data,data,length);

	// read the header

	int r = this->header.parseHeader(this->data);

	if(r != ERROR_NONE){
		logger->log(LOG_LEVEL_ERROR,"Could not parse Header!\n");
		return;
	}

	r = dataTable.readTable(data + header.dataTableOffset, header.dataTableCount);

	if(DUMP_DATA_TABLE){
		logger->log(LOG_LEVEL_DEBUG,"\n\n\n");
		logger->log(LOG_LEVEL_DEBUG,"Data Table:\nSize\tRegion\tOffset\n");
		for(int i = 0; i < dataTable.entries.size(); i++){
			logger->log(LOG_LEVEL_DEBUG,"0x%x\t0x%x\t0x%x\t\n",dataTable.entries[i].size,dataTable.entries[i].region,dataTable.entries[i].offset);
		}
	}

	r = contentTable.readTable(data + header.contentTableOffset, header.contentTableCount);

	if(DUMP_CONTENT_TABLE){
		logger->log(LOG_LEVEL_DEBUG,"Type\t\tRef\tParent\n");
		for(int i = 0; i < contentTable.entries.size(); i++){
			logger->log(LOG_LEVEL_DEBUG,"0x%llx %#llx\t%#x\t%#x\n",contentTable.entries[i].type.data[0],contentTable.entries[i].type.data[1],contentTable.entries[i].ref,contentTable.entries[i].parent);
		}
	}

	r = stringTable.readStrings(data + header.stringTableOffset, header.stringCount, header.stringLength, data + header.stringDataOffset);

	if(DUMP_STRING_TABLE){
		logger->log(LOG_LEVEL_DEBUG,"Valid Strings\n");
		for(int i = 0; i < stringTable.strings.size(); i++){
			logger->log(LOG_LEVEL_DEBUG,"%s\n",stringTable.strings[i].string.c_str());
		}
		logger->log(LOG_LEVEL_DEBUG,"Invalid Strings\n");
		for(int i = 0; i < stringTable.invalidStrings.size(); i++){
			logger->log(LOG_LEVEL_DEBUG,"%s\n",stringTable.invalidStrings[i].string.c_str());
		}
	}
}
