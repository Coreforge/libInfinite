#include "DataTable.h"

#include "Errors.h"

int DataTable::readTable(uint8_t* data, uint32_t n){

/*
 *	Offset	Size	Function
 *  0x00	0x04	Entry size
 *  0x06	0x02	Region index (metadata (1) or data (2))
 * 	0x08	0x04	Offset in area
 */

	for(int i = 0; i < n; i++){
		uint32_t entryOffset = i * 0x10;
		uint32_t size = *((uint32_t*)(data + entryOffset));
		uint16_t region = *((uint16_t*)(data + entryOffset + 0x6));
		uint32_t offset = *((uint32_t*)(data + entryOffset + 0x8));
		entries.emplace_back(DataTableEntry(size,region,offset));
	}

	return ERROR_NONE;
}
