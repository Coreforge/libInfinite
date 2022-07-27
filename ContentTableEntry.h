#pragma once

#include <stdint.h>


typedef struct typeGUID{uint64_t data[2];} TypeGUID;

class ContentTableEntry{
public:
	TypeGUID type;
	uint32_t ref;
	uint32_t parent;

	ContentTableEntry(TypeGUID type, uint32_t ref, uint32_t parent){
		this->type = type;
		this->ref = ref;
		this->parent = parent;
	};
};
