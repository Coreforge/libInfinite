#pragma once
#include <stdint.h>



class ContentTableEntry;

class DataTableEntry{
public:
	uint32_t size;
	uint16_t region;
	uint32_t offset;
	ContentTableEntry* cte;

	DataTableEntry(uint32_t size, uint16_t region, uint32_t offset){
		this->size = size;
		this->region = region;
		this->offset = offset;
		cte = nullptr;
	};
};
