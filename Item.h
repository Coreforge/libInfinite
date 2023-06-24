#pragma once

#include "Header.h"
#include "DataTable.h"
#include "ContentTable.h"
#include "TagRefTable.h"
#include "DataRefTable.h"
#include "logger/logger.h"
#include "module/ModuleItem.h"

#include <string>
#include "TagRefFieldTable.h"

class TagManager;

class Item{

public:
	ModuleItem* moduleItem;	// this is still needed, as it contains useful information like resource count and references
	Header header;
	DataTable dataTable;
	ContentTable contentTable;
	TagRefFieldTable tagRefFieldTable;
	TagRefTable tagRefTable;
	DataRefTable dataRefTable;
	Logger* logger;

	TagManager* tagManager;

	std::string name;
	std::string path;

	// the data will be copied into a new buffer,
	Item(uint8_t* data, uint32_t length, Logger* logger, std::string name, std::string path, ModuleItem* moduleItem);
	~Item();

	// returns a pointer to the start of this blocks data. The data does not get copied again, so this pointer is only valid as long as this item exists
	void* getDataBlock(DataTableEntry* entry);
	uint32_t getDataBlockOffset(DataTableEntry* entry);
	void* getRefDataBlock(ContentTableEntry* entry);


private:
	uint8_t* data;
};
