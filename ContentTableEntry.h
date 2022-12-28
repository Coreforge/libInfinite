#pragma once

#include <stdint.h>


typedef struct typeGUID{uint64_t data[2];} TypeGUID;

class ContentTableEntry{
public:
	TypeGUID type;
	uint16_t type_id;
	uint32_t ref;
	uint32_t parent;
	uint32_t field_offset;

	ContentTableEntry(TypeGUID type, uint16_t type_id, uint32_t ref, uint32_t parent, uint32_t field_offset){
		this->type = type;
		this->type_id = type_id;
		this->ref = ref;
		this->parent = parent;
		this->field_offset = field_offset;
	};
};
