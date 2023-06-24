#include "Item.h"

#include <cstdlib>
#include <cstring>

#include "Errors.h"

#include "module/Module.h"

#define DUMP_DATA_TABLE false
#define DUMP_CONTENT_TABLE false
#define DUMP_STRING_TABLE false

Item::Item(uint8_t* data, uint32_t length, Logger* logger, std::string name, std::string path, ModuleItem* moduleItem){


	this->moduleItem = moduleItem;
	// copy the strings. Ideally, we don't want to depend on any data managed by another object
	this->name = std::string(name);
	this->path = std::string(path);
	this->logger = logger;
	this->tagManager = nullptr;
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
	for(int i = 0; i < contentTable.entries.size(); i++){
		if(contentTable.entries[i].ref != -1){
			dataTable.entries[contentTable.entries[i].ref].cte = &contentTable.entries[i];
		}
		if(contentTable.entries[i].parent != -1){
			dataTable.entries[contentTable.entries[i].parent].cte->children.emplace_back(&contentTable.entries[i]);
			contentTable.entries[i].parentEntry = dataTable.entries[contentTable.entries[i].parent].cte;
		} else {
			// no parent -> root entry
			contentTable.rootEntries.emplace_back(&contentTable.entries[i]);
		}
	}
	if(DUMP_CONTENT_TABLE){
		logger->log(LOG_LEVEL_DEBUG,"Type\t\tRef\tParent\n");
		for(int i = 0; i < contentTable.entries.size(); i++){
			logger->log(LOG_LEVEL_DEBUG,"0x%llx %#llx\t%#x\t%#x\n",contentTable.entries[i].type.data[0],contentTable.entries[i].type.data[1],contentTable.entries[i].ref,contentTable.entries[i].parent);
		}
	}
	bool stillHasPaths = moduleItem->module->version < 0x35;
	r = tagRefFieldTable.readStrings(data + header.stringTableOffset, header.stringCount, header.stringLength, data + header.stringDataOffset,stillHasPaths);

	if(DUMP_STRING_TABLE){
		logger->log(LOG_LEVEL_DEBUG,"Valid Strings\n");
		for(int i = 0; i < tagRefFieldTable.strings.size(); i++){
			logger->log(LOG_LEVEL_DEBUG,"%s\n",tagRefFieldTable.strings[i].string.c_str());
		}
		logger->log(LOG_LEVEL_DEBUG,"Invalid Strings\n");
		for(int i = 0; i < tagRefFieldTable.invalidStrings.size(); i++){
			logger->log(LOG_LEVEL_DEBUG,"%s\n",tagRefFieldTable.invalidStrings[i].string.c_str());
		}
	}

	r = tagRefTable.readTable(data + header.tagRefTableOffset, header.tagRefTableCount,(char*) data + header.stringDataOffset);

	r = dataRefTable.readTable(data + header.dataReferenceTableOffset, header.dataReferenceTableCount);

	logger->log(LOG_LEVEL_DEBUG, "Data Offset: 0x%lx, Data2 Offset: 0x%lx\n",this->header.dataOffset,this->header.data2Offset);
}

Item::~Item(){
	free(data);
	printf("deleting Item\n");
}

void* Item::getDataBlock(DataTableEntry* entry){
	// get the full offset in the file. This depends on the region the data block is in
	uint32_t offset = entry->offset;
	if(entry->region == 1){
		offset += header.dataOffset;
	}
	if(entry->region == 2){
		offset += header.data2Offset;
	}
	if(entry->region == 3){
		offset += header.data3Offset;
	}
	//uint32_t full_offset = entry->region == 1 ? header.dataOffset + entry->offset : header.data2Offset + entry->offset;

	return data + offset;
}

void* Item::getRefDataBlock(ContentTableEntry* entry){
	if(entry->ref == -1){
		// no ref
		return nullptr;
	}
	return getDataBlock(&dataTable.entries[entry->ref]);
}

uint32_t Item::getDataBlockOffset(DataTableEntry* entry){
	uint32_t offset = entry->offset;
	if(entry->region == 1){
		offset += header.dataOffset;
	}
	if(entry->region == 2){
		offset += header.data2Offset;
	}
	if(entry->region == 3){
		offset += header.data3Offset;
	}
	return offset;
}
