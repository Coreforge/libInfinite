#pragma once

#include "ContentTableEntry.h"
#include <vector>
#include <stdint.h>

class ContentTable{
public:
	std::vector<ContentTableEntry> entries;

	std::vector<ContentTableEntry*> rootEntries;
	int readTable(uint8_t* data, uint32_t n);

	ContentTableEntry operator[](int idx);
};
