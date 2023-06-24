#include "TagLoader.h"

#include "../ContentTableEntry.h"

#include "xml/infiniteTypes.h"
#include "xml/infiniteStructs.h"

#include "Tag.h"

#include "TagManager.h"

#include <cstdio>

#define CTE_TYPE_ROOT 0
#define CTE_TYPE_TAGSTRUCT 1
#define CTE_TYPE_EXTERNAL_RESOURCE 3

// this will likely only run on 64bit anyways since the tag structs are made for that, but just to be sure
#define CAST_POINTER_TYPE uint64_t

//#include "xml/generated/vart.h"
int TagLoader::loadTag(Item* item, void* &dest , uint8_t* desc, int descSize, bool loadChildren, TagManager* manager,Tag* tag){
	this->item = item;

	// the first entry is always the root entry
	dest = item->getRefDataBlock(&item->contentTable.entries[0]);
	dst = dest;

	CTEstackptr = 0;
	CTEStack[CTEstackptr] = 0;
	childIndex = &CTEStack[CTEstackptr];

	// first ones are the root entry
	currentContentTableIndex = 0;
	currentDataTableIndex = 0;

	descOffset = 0;
	this->desc = desc;
	this->descSize = descSize;
	this->manager = manager;
	this->loadChildren = loadChildren;
	this->tag = tag;
	// pointers have to be fixed up
	//fixupStruct(dest, false, item->contentTable.rootEntries[0]);

	fixupDataReferences();
	fixupTagStructs();
	fixupTagRefs();

	return 0;
}

void TagLoader::fixupDataReferences(){
	for(int i = 0; i < item->dataRefTable.entries.size(); i++){
		uint32_t fieldIndex = item->dataRefTable.entries[i].fieldBlockIndex;
		uint32_t refIndex = item->dataRefTable.entries[i].refIndex;
		if(refIndex == -1){
			continue;
		}
		dataReference* field = (dataReference*)(item->getDataBlock(&item->dataTable.entries[fieldIndex]) + item->dataRefTable.entries[i].fieldOffset);
		field->data = item->getDataBlock(&item->dataTable.entries[item->dataRefTable.entries[i].refIndex]);
	}
}

void TagLoader::fixupTagRefs(){
	for(int i = 0; i < item->tagRefFieldTable.entries.size(); i++){
		TagRefFieldTableEntry* trefent = &item->tagRefFieldTable.entries[i];
		if(trefent->index == -1){
			// null reference
			continue;
		}
		tagReference* tref =  (tagReference*)(item->getDataBlock(&item->dataTable.entries[trefent->fieldBlockIndex]) + trefent->fieldBlockOffset);
		TagRefTableEntry* tdep = &item->tagRefTable.entries[trefent->index];
		Tag* refTag = manager->getTag(tdep->globalId);
		if(refTag == nullptr){
			// tag not available or something
			continue;
		}
		tref->TypeInfo = refTag->root;
	}
}

void TagLoader::fixupTagStructs(){
	for(int i = 0; i < item->contentTable.entries.size(); i++){
		ContentTableEntry* cte = &item->contentTable.entries[i];
		if(cte->parent == -1){
			continue;
		}
		if(cte->type_id == CTE_TYPE_ROOT || cte->type_id == CTE_TYPE_TAGSTRUCT){
			tagBlock<void>* tref = (tagBlock<void>*)(item->getDataBlock(&item->dataTable.entries[cte->parent]) + cte->field_offset);
			tref->Elements = cte;
			tref->block = item->getRefDataBlock(cte);
		}
		if(cte->type_id == CTE_TYPE_EXTERNAL_RESOURCE){
			externalResource<void>* res = (externalResource<void>*)(item->getDataBlock(&item->dataTable.entries[cte->parent]) + cte->field_offset);
			res->Handle = i;	// just in case the CTE is needed again later.
			res->block = item->getRefDataBlock(cte);
		}
	}

}

void TagLoader::skipAllChildren(ContentTableEntry* cte){
	for(auto it = cte->children.begin(); it != cte->children.end(); it++){
		currentContentTableIndex++;
		skipAllChildren(*it);
	}
}

void TagLoader::pushCTE(){
	if(CTEstackptr < CTE_STACK_SIZE){
		CTEstackptr++;
		CTEStack[CTEstackptr] = 0;
		childIndex = &CTEStack[CTEstackptr];
	} else {
		printf("TagLoader: CTE Stack Overflow!\n");
	}
}

void TagLoader::popCTE(){
	if(CTEstackptr > 0){
		CTEstackptr--;
		childIndex = &CTEStack[CTEstackptr];
	} else {
		printf("TagLoader: CTE Stack Underflow! This should never happen. Something is really wrong. Probably a good idea to check with ASAN (if that worked)\n");
	}
}


// dpesn't work anymore with the new array code, so this ugly mess is essentially obsolete now
int TagLoader::fixupStruct(void* structStart, bool skipOnly, ContentTableEntry* parentCTE){

	int currentStructOffset = 0;

	// This variable only exists for debugging purposes to make it easier to know what is being processed
	// without stepping through the whole process and counting manually
	int fieldIndex = 0;
	while(descOffset < descSize){

		if(desc[descOffset] == STRUCTDEFS_TYPE_STRUCT_END){
			break;
		}
		if(sizes[desc[descOffset]] != 0){
			fieldIndex++;
		}
		if(desc[descOffset] == STRUCTDEFS_TYPE_TAGBLOCK){
			tagBlock<void>* tblk = (tagBlock<void>*)(structStart + currentStructOffset);
			// Potential bug: if tblk->count is 0 and there is no ref for the CTE, currentDataTableIndex could get messed up, which will cause problems later
			if(tblk == nullptr && !skipOnly){
				return -1;
			}

			descOffset++;
			int currentDescStart = descOffset;
			if(!skipOnly){
				currentContentTableIndex++;
				if((void*)tblk != item->getRefDataBlock(parentCTE) + parentCTE->children[(*childIndex)]->field_offset){
					printf("TagBlocks don't line up! tblk - stack based stuff = 0x%llx\n",( (tblk) - (struct tagBlock<void>*)(item->getRefDataBlock(parentCTE) + parentCTE->children[(*childIndex)]->field_offset)));
					printf("Using offset from the ContentTable! This should be the more reliable source, but ideally, both should match up. Something isn't right!\n");
					printf("Might be the loader implementation (probably), or it could be the tag definitions\n");
					auto old = tblk;
					tblk = (tagBlock<void>*)(item->getRefDataBlock(parentCTE) + parentCTE->children[(*childIndex)]->field_offset);
					if(old > tblk){
						printf("too far by 0x%lx bytes\n", (CAST_POINTER_TYPE)old - (CAST_POINTER_TYPE)tblk);
						currentStructOffset -= ((CAST_POINTER_TYPE)old - (CAST_POINTER_TYPE)tblk);
					} else {
						printf("not far enough by 0x%x bytes\n",(CAST_POINTER_TYPE)tblk - (CAST_POINTER_TYPE)old);
						currentStructOffset += ((CAST_POINTER_TYPE)tblk - (CAST_POINTER_TYPE)old);
					}
				}
				tblk->Elements = &item->contentTable.entries[currentContentTableIndex];
				if(tblk->count > 0){

					//currentDataTableIndex = item->contentTable.entries[currentContentTableIndex].ref;
					currentDataTableIndex++;
					tblk->block = item->getRefDataBlock(&item->contentTable.entries[currentContentTableIndex]);
					//tblk->block = item->getDataBlock(&item->dataTable.entries[currentDataTableIndex]);
					// each child in that block may need to be fixed up as well
					// this function doesn't know the type of that child struct, so the tblk->block pointer cannot be accessed like an array
					// however, fixupStruct returns the size of the struct, and the count is known, so the pointer can simply be advanced each time
					void* childBlockPtr = tblk->block;
					pushCTE();
					for(int childBlock = 0; childBlock < tblk->count; childBlock++){
						// since this struct will be read over and over again, the descriptor will have to be read from the same offset
						// it would otherwise get advanced on subsequent calls, which would mess things up after the first child struct
						// after the last child struct is fixed up, descStart won't be reset again, so it should end up in the correct place
						descOffset = currentDescStart;
						int inc = fixupStruct(childBlockPtr, false, tblk->Elements);
						if(inc == -1){
							return -1;
						}
						childBlockPtr += inc;	// increment the pointer to the next child struct
					}
					popCTE();
				} else {
					// no block to fix up in this case, but the descriptor still has to be read
					fixupStruct(tblk->block, true, parentCTE);
				}
				(*childIndex)++;
			} else {
				fixupStruct(nullptr, true,parentCTE);
			}
			currentStructOffset += sizes[STRUCTDEFS_TYPE_TAGBLOCK];
		}

		if(desc[descOffset] == STRUCTDEFS_TYPE_EXTERNAL_RESOURCE){
			currentContentTableIndex++;
			int oldCTI = currentContentTableIndex;
			ContentTableEntry* cte = &item->contentTable.entries[currentContentTableIndex];
			descOffset++;
			if(!skipOnly){
				externalResource<void>* res = (externalResource<void>*)(structStart + currentStructOffset);
				//res->cte = cte;
				void* resourceMetaData = item->getRefDataBlock(cte);
				if(resourceMetaData != nullptr){
					// there is resource metadata that might need to be fixed up too
					fixupStruct(resourceMetaData, false, cte);
					//res->Handle = tag->resources.size();	// this will be the index of the pointer to the data after it's emplaced into the vector
					//tag->resources.emplace_back(resourceMetaData);
				} else {
					// I guess this means no resource?
					// Whatever, the descriptor still has to be read and skipped, so do that now, just like it's done with tagblocks
					fixupStruct(resourceMetaData, true, cte);
				}
			} else {
				// Skipping, just read the descriptor and move on
				fixupStruct(nullptr, true, cte);
			}
			currentContentTableIndex = oldCTI;
			skipAllChildren(cte);
		}

		if(desc[descOffset] == STRUCTDEFS_TYPE_TAG_REFERENCE){
			if(!skipOnly && loadChildren){
				tagReference* ref = (tagReference*)(structStart + currentStructOffset);
				if(ref->assetId != -1){
					Tag* tag = manager->getTag(ref->globalId);
					if(tag != nullptr){
						ref->TypeInfo = tag->root;
					}
				} else {
					manager->logger->log(LOG_LEVEL_DEBUG,"Null Tag reference\n");
				}
			}
		}

		if(desc[descOffset] == STRUCTDEFS_TYPE_STRUCT){
			/*
			 * So this is kinda annoying
			 * It looks like some structs have a content table entry, while others don't, which messes
			 * with the counter.
			 * mode::render_geometry has one with the type 4, which needs to be skipped
			 * otherwise, the counter is off
			 */
			descOffset++;
			fieldIndex++;
			if(item->contentTable.entries[currentContentTableIndex + 1].type_id == 4){
				currentContentTableIndex++;
				(*childIndex)++;
			}
			int inc = fixupStruct(structStart + currentStructOffset, skipOnly, parentCTE);
			if(inc == -1){
				return -1;
			}
			currentStructOffset += inc;
		}

		currentStructOffset += sizes[desc[descOffset]];
		descOffset++;
	}
	return currentStructOffset;
}
