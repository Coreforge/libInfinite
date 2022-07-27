#pragma once

#include "Header.h"
#include "DataTable.h"
#include "ContentTable.h"
#include "StringTable.h"
#include "logger/logger.h"

class Item{

public:
	Header header;
	DataTable dataTable;
	ContentTable contentTable;
	StringTable stringTable;
	Logger* logger;

	// the data will be copied into a new buffer,
	Item(uint8_t* data, uint32_t length, Logger* logger);


private:
	uint8_t* data;
};
