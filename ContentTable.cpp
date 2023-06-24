#include "ContentTable.h"

#include "Errors.h"

#include <stdint.h>

int ContentTable::readTable(uint8_t* data, uint32_t n){

	/*
	 * Offset	Size	Function
	 * 0x0		0x10	Type (GUID)
	 *
	 * 0x10		0x02	type id
	 * 0x14		0x04	ref data index
	 * 0x18		0x04	parent data index
	 * 0x1c		0x04	field offset ;unknown (seems to increase, but sometimes resets to 0. Maybe some size?)
	 */

	for(int i = 0; i < n; i++){
		uint32_t entryOffset = i * 0x20;
		TypeGUID type;
		type.data[0] = *((uint64_t*)(data+entryOffset));
		type.data[1] = *((uint64_t*)(data+entryOffset+0x08));
		uint16_t type_id = *((uint16_t*)(data+entryOffset+0x10));
		uint16_t is_external = *((uint16_t*)(data+entryOffset+0x12));
		uint32_t ref = *((uint32_t*)(data + entryOffset + 0x14));
		uint32_t parent = *((uint32_t*)(data + entryOffset + 0x18));
		uint32_t field_offset = *((uint32_t*)(data + entryOffset + 0x1c));
		entries.emplace_back(ContentTableEntry(type,type_id, is_external, ref,parent,field_offset,i));
	}
	return ERROR_NONE;
}

ContentTableEntry ContentTable::operator[](int idx){
	return entries[idx];
}
