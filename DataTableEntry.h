#pragma once
#include <stdint.h>



class DataTableEntry{
public:
	uint32_t size;
	uint16_t region;
	uint32_t offset;

	DataTableEntry(uint32_t size, uint16_t region, uint32_t offset){
		this->size = size;
		this->region = region;
		this->offset = offset;
	};
};
