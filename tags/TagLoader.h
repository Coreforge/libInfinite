#pragma once

#include "../Item.h"
#include "../module/ModuleItem.h"

#include <stdint.h>

#define CTE_STACK_SIZE 32

class TagManager;
class Tag;

class TagLoader{
public:
	/*
	 * Loads a tag into the appropriate structs, which have been generated based on the XML dumps
	 * Any child data will be malloc'd
	 * Resources will not be loaded
	 *
	 * params:
	 * 		item: Pointer to the Item
	 * 		dest: Pointer to the root struct this tag should be loaded into
	 * 		desc: Pointer to the description array
	 * 		descSize: Size of the description array
	 * 		loadChildren: Wether or not to load tags referenced by this tag
	 * 		manager: TagManager to use. Can be null if loadChildren is disabled
	 */
	int loadTag(Item* item, void* &dest, uint8_t* desc, int descSize, bool loadChildren, TagManager* manager, Tag* tag);

private:
	uint32_t currentContentTableIndex;
	uint32_t currentDataTableIndex;
	bool loadChildren = false;
	TagManager* manager = nullptr;
	Item* item;

	Tag* tag;

	void* dst;

	int descOffset;
	uint8_t* desc;
	int descSize;
	uint32_t* childIndex;
	int CTEstackptr;

	uint32_t CTEStack[CTE_STACK_SIZE];

	int fixupStruct(void* structStart, bool skipOnly, ContentTableEntry* parentCTE);

	void skipAllChildren(ContentTableEntry* cte);
	void pushCTE();
	void popCTE();
	void fixupDataReferences();
	void fixupTagStructs();
	void fixupTagRefs();

};
