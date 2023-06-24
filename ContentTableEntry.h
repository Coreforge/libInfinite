#pragma once

#include <stdint.h>

#include <vector>


typedef struct typeGUID{uint64_t data[2];} TypeGUID;

class ContentTableEntry{
public:
	TypeGUID type;
	uint16_t type_id;
	uint16_t is_external;
	uint32_t ref;
	uint32_t parent;
	uint32_t field_offset;

	uint32_t idx;

	ContentTableEntry* parentEntry;
	std::vector<ContentTableEntry*> children;

	ContentTableEntry(TypeGUID type, uint16_t type_id, uint16_t is_external, uint32_t ref, uint32_t parent, uint32_t field_offset, uint32_t idx){
		this->type = type;
		this->type_id = type_id;
		this->is_external = is_external;
		this->ref = ref;
		this->parent = parent;
		this->field_offset = field_offset;
		this->idx = idx;
		parentEntry = nullptr;
	};
};
