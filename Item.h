#pragma once

#include "Header.h"
#include "DataTable.h"
#include "ContentTable.h"
#include "StringTable.h"

class Item{

public:
	Header header;
	DataTable dataTable;
	ContentTable contentTable;
	StringTable stringTable;

	// the data will be copied into a new buffer,
	Item(uint8_t* data, uint32_t length);


private:
	uint8_t* data;
};
