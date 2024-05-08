#include "TagManager.h"

#include "TagLoader.h"
#include "tagClasses.h"

#include <string>

#include "loaders/mode_loader.h"
#include "loaders/mat_loader.h"

#include "handles/modeHandle.h"
#include "handles/mat_Handle.h"
#include "handles/rtgoHandle.h"
#include "handles/pmdfHandle.h"
#include "handles/sbspHandle.h"
#include "handles/shdvHandle.h"
#include "handles/vartHandle.h"
#include "handles/levlHandle.h"
#include "handles/mwsyHandle.h"
#include "handles/cwmsHandle.h"
#include "handles/cmswHandle.h"

TagManager::TagManager(ModuleManager* manager, Logger* logger){
	this->man = manager;
	this->logger = logger;
}

int TagManager::addTag(uint32_t globalId){
	if(man == nullptr){
		return -2;
	}
	if(man->assetIdItems.count(globalId) == 0){
		logger->log(LOG_LEVEL_ERROR, "Error: Could not find the Tag with the Global ID 0x%08x. Maybe some required modules aren't loaded?\n",globalId);
		return -1;
	}

	ModuleItem* itm;
	itm = man->assetIdItems[globalId];
	return addTag(itm);
}

Tag* TagManager::getTag(uint32_t globalId){

	if(loadingTags.contains(globalId)){
		// this can cause crashes, depending on what's being done inside the setup function of the tags (currently unlikely)
		char* tagType = (char*)&loadingTags[globalId]->item->moduleItem->tagType;
		logger->log(LOG_LEVEL_WARNING, "Tag dependency loop detected! Global Id 0x%08x (%c%c%c%c) is still being loaded, but required by another tag.\n",globalId, tagType[3], tagType[2], tagType[1], tagType[0]);
	}

	if(loadedTags.count(globalId) > 0){
		loadedTags[globalId]->uses++;
		//printf("Tag already loaded\n");
		return loadedTags[globalId];
	}

	// Tag not loaded yet, so it has to be loaded first
	if(addTag(globalId) != 0){
		return nullptr;
	}

	return loadedTags[globalId];
}

// This will probably get moved into a separate class, to keep this a bit more clean
Tag* TagManager::getTagObject(uint32_t type){
	switch(type){
	case 'mode':
		return new modeHandle();
	case 'rtgo':
		return new rtgoHandle();
	case 'pmdf':
		return new pmdfHandle();
	case 'sbsp':
		return new sbspHandle();
	case 'shdv':
		return new shdvHandle();
	case 'mat ':
		return new mat_Handle();
	case 'vart':
		return new vartHandle();
	case 'levl':
		return new levlHandle();
	case 'mwsy':
		return new mwsyHandle();
	case 'cwms':
		return new cwmsHandle();
	case 'cmsw':
		return new cmswHandle();
	default:
		return new Tag();
	}
}

int TagManager::addTag(ModuleItem* itm){
	void* rawData = itm->extractData();
	if(rawData == nullptr){
		logger->log(LOG_LEVEL_ERROR, "Failed to get extract data to load Tag\n");
		return -1;
	}
	Item* item = new Item((uint8_t*)rawData,itm->decompressedSize,logger,std::string(""),std::string(""),itm);

	TagLoader loader;

	/*
	 * The Tag object needs to be allocated in a way it won't be moved around during its lifetime as other objects may hold pointers to it which will get broken otherwise and lead to segfaults
	 * There's probably a more elegant way to do it, but this is how I'm doing it
	 *
	 * I could use a unique_ptr, but this works too, as long as the tags get deleted properly (which they currently don't)
	 */
	Tag* tag = getTagObject(itm->tagType);
	//shdv* better;
	//vart* vartptr;
	sbsp* bsp;
	void* struct_ptr;

	// inserting it before loading means that in case of a dependency loop, it can still be referenced by the loader
	tag->item = item;
	loadingTags.insert({item->moduleItem->assetID,tag});
	loadedTags.insert({item->moduleItem->assetID,tag});

	loader.loadTag(item, struct_ptr, nullptr, 0, true, this, tag);
	loadingTags.erase(item->moduleItem->assetID);
	// giant switch for all tag classes
	// this is ugly, but I'm not sure if there really is a better way to do it
	switch(itm->tagType){
	case 'sbsp':
		bsp = (sbsp*) struct_ptr;
	}
	/*switch(itm->tagType){
	case 'shdv':

		loader.loadTag(item, struct_ptr, shdv_structure, sizeof(shdv_structure), false, this, tag);

		better = (shdv*) struct_ptr;
		break;

	case 'vart':
		//void* struct_ptr;
		loader.loadTag(item, struct_ptr, vart_structure, sizeof(vart_structure), false, this, tag);

		vartptr = (vart*) struct_ptr;
		break;

	case 'mode':
		//void* struct_ptr;
		//loader.loadTag(item, struct_ptr, mode_structure, sizeof(mode_structure), false, nullptr);

		//modeptr = (mode*) struct_ptr;
 		loadMODETag(item, struct_ptr, true, this, tag);
		break;

	case 'mat ':
		loadMAT_Tag(item, struct_ptr, true, this, tag);
		break;
	default:
		delete item;
		return -1;
	}*/

	item->tagManager = this;
	tag->root = struct_ptr;
	tag->uses  = 1;
	tag->setup();	// not used by the base tag, but some handles need it

	return 0;
}
