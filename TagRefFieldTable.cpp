#include "Errors.h"

#include <stdint.h>
#include <TagRefFieldTable.h>

int TagRefFieldTable::readStrings(uint8_t* data, uint32_t count, uint32_t length, uint8_t* stringData, bool readStrings){

	/*
	 * Offset	Size	Function
	 * 0x00		0x04	likely type, unsure
	 * 0x04		0x04	some unknown offset probably
	 * 0x08		0x04	Offset in the string block
	 * 0x0c		0x04	Index
	 *
	 *
	 */

	// the length isn't checked for now, I just assume the file is ok
	// if this turns out to cause issues, before constructing the std::string,
	// the c-string first has to be read/copied with one of the strn functions, and then the std::string can be constructed

	for(int i = 0; i < count; i++){
		uint32_t entryOffset = i * 0x10;
		uint32_t fieldBlockIndex = *((uint32_t*)(data + entryOffset));
		uint32_t fieldBlockOffset = *((uint32_t*)(data + entryOffset + 0x04));
		uint32_t offset = *((uint32_t*)(data + entryOffset + 0x08));
		uint32_t index = *((uint32_t*)(data + entryOffset + 0x0c));

		std::string str;
		if(readStrings){
			str = std::string((const char*)(stringData + offset));
		}
		TagRefFieldTableEntry ent(str, fieldBlockIndex, fieldBlockOffset, index,offset);
		entries.emplace_back(ent);

		if(index < count){
			// valid index
			strings.emplace_back(ent);
		} else {
			// invalid index
			// probably not used, but might be interesting
			invalidStrings.emplace_back(ent);
		}
	}
	return ERROR_NONE;
}
