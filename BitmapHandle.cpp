#include "BitmapHandle.h"
#include "ContentTableEntry.h"
#include "contentUtils.h"

#include <cstring>

// Types

#define type_handle_root std::string("R\\xab5#hBJ\\xc2}\\x8fr\\x94#\\x19m\\xd3")
#define type_entry_bitmaps std::string("jQ\\xb0\\xde\\x98D\\x1c\\x02\\xcd\\xc6A\\x99i\\xaa\\x94\\xc2")

BitmapHandle::BitmapHandle(ModuleItem* moduleItem, Logger* logger){
	this->logger = logger;
	this->moduleItem = moduleItem;
	void* data = moduleItem->extractData();

	frameCount = 0;

	// name and path aren't needed here
	item = new Item((uint8_t*)data, moduleItem->decompressedSize, logger, std::string(""), std::string(""),moduleItem);
	free(data);
	// root entry (only contains frame count for now)
	ContentTableEntry* root = item->contentTable.rootEntries[0];
	frameCount = *((uint32_t*)(item->getRefDataBlock(root) + 0xe4));
	ContentTableEntry* frameInfoEntry;
	for(int i = 0; i < root->children.size(); i++){
		frameInfoEntry = root->children[i];

		if(checkEntryType(frameInfoEntry, type_entry_bitmaps)){
			// jQ\xb0...
			// contains stuff like size for the largest mipmap
			// unsure about the other stuff in there
			break;
		}
	}

	for(int i = 0; i < frameInfoEntry->children.size(); i++){
		// each of these is one frame with a varying amount of mipmaps
		// these are the *\x80\xeb ones
		ContentTableEntry* frame = frameInfoEntry->children[i];
		Item* frameItem = item;
		if(frame->type_id != 1){
			// this is the case for multi frame ones. The data has to be loaded from the resource files
			ModuleItem* frameModuleItem = moduleItem->resources[i];
			void* frameData = frameModuleItem->extractData();
			frameItem = new Item((uint8_t*)frameData,frameModuleItem->decompressedSize,logger,std::string(""),std::string(""),frameModuleItem);
			free(frameData);
			frame = frameItem->contentTable.rootEntries[0];
			//return;
		}
		void* frameMetaData = frameItem->getRefDataBlock(frame);
		Frame fr;
		fr.item = frameItem;
		fr.format = *(uint16_t*)(frameMetaData+0x1d);
		fr.mipmapCount = *(uint32_t*)(frameMetaData+0x40);

		// width/height plus some other data (that's not needed) is in the parent block
		fr.width = *(uint16_t*)(item->getRefDataBlock(frameInfoEntry) + i * 0x28 + 0x00);
		fr.height = *(uint16_t*)(item->getRefDataBlock(frameInfoEntry) + i * 0x28 + 0x02);

		if(fr.mipmapCount != 0){
			// grab mipmap info for each frame
			fr.mipMaps.resize(fr.mipmapCount);
			ContentTableEntry* mip = frame->children[0];
			void* mipMetaData = frameItem->getRefDataBlock(mip);
			for(int m = 0; m < fr.mipmapCount; m++){
				MipMap mipmap;
				mipmap.level = *(uint8_t*)(mipMetaData + m * 0x10 + 0xa);
				mipmap.width = *(uint16_t*)(mipMetaData + m * 0x10 + 0xc);
				mipmap.height = *(uint16_t*)(mipMetaData + m * 0x10 + 0xe);
				fr.mipMaps[mipmap.level] = mipmap;
			}
		} else {
			// single level bitmap, these don't use resource files
			// Create one Mipmap entry though, for consistency
			MipMap mipmap;
			mipmap.level = 0;
			mipmap.width = fr.width;
			mipmap.height = fr.height;
			fr.mipmapCount = 1;		// this isn't staying true to the files, but is more consistent with the meaning of this field
			fr.mipMaps.emplace_back(mipmap);
			//return;
		}
		frames.emplace_back(fr);
		logger->log(LOG_LEVEL_DEBUG, "%d Mipmaps, Max %dx%d\n",fr.mipmapCount,fr.width,fr.height);
	}

	logger->log(LOG_LEVEL_DEBUG, "Frame count: %d\n",frameCount);
}

BitmapHandle::~BitmapHandle(){
	for(auto iter = frames.begin(); iter != frames.end(); iter++){
		if(iter->item != item){
			delete iter->item;
		}
	}
	delete item;
}

void* Frame::getData(uint8_t level){
	if(level > mipmapCount){
		return nullptr;
	}
	if(mipmapCount != 1){
		// resource files
		int resourceIndex = item->moduleItem->resources.size() - level;
		return item->moduleItem->resources[resourceIndex]->extractData();
	}
	// single mipmap
	for(int i = 0; i < item->dataTable.entries.size(); i++){
		if(item->dataTable.entries[i].region == 3){
			// this is the one (probably, haven't seen anything else yet)
			// the data has to be copied to get the same behaviour as with the other bitmaps (the buffer can be freed)
			void* data = item->getDataBlock(&item->dataTable.entries[i]);
			void* cpy = malloc(item->dataTable.entries[i].size);
			memcpy(cpy,data,item->dataTable.entries[i].size);
			return cpy;
		}
	}
	return nullptr;
}
