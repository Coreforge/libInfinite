#pragma once

#include <stdint.h>


typedef struct typeGUID{uint64_t data[2];} GUID;

class ContentTableEntry{
public:
	GUID type;
	uint32_t ref;
	uint32_t parent;

	ContentTableEntry(GUID type, uint32_t ref, uint32_t parent){
		this->type = type;
		this->ref = ref;
		this->parent = parent;
	};
};
