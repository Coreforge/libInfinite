#include "DataRefTable.h"

int DataRefTable::readTable(uint8_t* data, uint32_t n){

	for(int i = 0; i < n; i++){
		uint8_t* entryOffset = data + (i * 0x14);

		DataRefTableEntry ent;
		ent.parentCTIndex = *(uint32_t*)(entryOffset);
		ent.refIndex = *(uint32_t*)(entryOffset + 0x08);
		ent.fieldBlockIndex = *(uint32_t*)(entryOffset + 0xc);
		ent.fieldOffset = *(uint32_t*)(entryOffset + 0x10);
		entries.emplace_back(ent);
	}
	return 0;
}
