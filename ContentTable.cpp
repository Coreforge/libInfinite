#include "ContentTable.h"

#include "Errors.h"

#include <stdint.h>

int ContentTable::readTable(uint8_t* data, uint32_t n){

	/*
	 * Offset	Size	Function
	 * 0x0		0x10	Type (GUID)
	 *
	 * 0x14		0x04	ref data index
	 * 0x18		0x04	parent data index
	 * 0x1c		0x04	unknown (seems to increase, but sometimes resets to 0. Maybe some size?)
	 */

	for(int i = 0; i < n; i++){
		uint32_t entryOffset = i * 0x20;
		TypeGUID type;
		type.data[0] = *((uint64_t*)(data+entryOffset));
		type.data[1] = *((uint64_t*)(data+entryOffset+0x08));
		uint32_t ref = *((uint32_t*)(data + entryOffset + 0x14));
		uint32_t parent = *((uint32_t*)(data + entryOffset + 0x18));
		entries.emplace_back(ContentTableEntry(type,ref,parent));
	}
	return ERROR_NONE;
}
