#include "Tag.h"

#include <cstring>
void* Tag::getResource(uint32_t offset, uint32_t size){
	// find which resource that area starts in
	if(!resourcesAllocated){
		allocResources();
	}
	for(int i = 0; i < resources.size(); i++){
		if(resources[i].offset <= offset && resources[i].offset + resources[i].size > offset){
			// this is the resource that block starts in
			uint32_t end = size + offset;
			// load all resources until the resource that contains the end of the specified area is reached
			for(int s = i; s < resources.size(); s++){
				loadResource(s);

				if(resources[s].status != TagResource::RESOURCE_LOADED){
					// this should never happen, but if a resource fails to load, the data isn't going to be very useful
					return nullptr;
				}
				if(end <= resources[s].offset + resources[s].size){
					break;
				}
			}
			// all required resources should now be loaded
			return resourcePointer + offset;
		}
	}
	return nullptr;
}

void Tag::loadAllResources(){
	for(int i = 0; i < item->moduleItem->resources.size(); i++){
		loadResource(i);
	}
}

void Tag::loadResource(int index){
	if(!resourcesAllocated){
		allocResources();
	}
	// it's be possible to decompress right into the destination array, but that would require reworking part of the module interface, which I don't want to do rn
	if(resources[index].status == TagResource::RESOURCE_LOADED){
		// already done
		return;
	}
	if(resources[index].status == TagResource::RESOURCE_FREE){
		allocResources();
		if(resources[index].status == TagResource::RESOURCE_FREE){
			// still not allocated, something isn't right
			return;
		}
	}
	void* data = resources[index].moduleItem->extractData();
	if(data == nullptr){
		return;
	}
	memcpy(resourcePointer + resources[index].offset,data,resources[index].size);
	resources[index].status = TagResource::RESOURCE_LOADED;
	free(data);
}

Tag::~Tag(){
	if(resourcesAllocated){
		free(resourcePointer);
	}
}

void Tag::setup(){

}

uint32_t Tag::getResourceSize(){
	return size;
}

void Tag::allocResources(){
	if(resourcesAllocated) return;	// nothing to do
	size = 0;
	resources.reserve(item->moduleItem->resources.size());
	for(int i = 0; i < item->moduleItem->resources.size(); i++){
		TagResource res;
		res.status = TagResource::RESOURCE_FREE;
		res.offset = size;
		res.size = item->moduleItem->resources[i]->decompressedSize;
		res.moduleItem = item->moduleItem->resources[i];
		resources.emplace_back(res);
		size += item->moduleItem->resources[i]->decompressedSize;
	}
	resourcePointer = malloc(size);
	if(resourcePointer != nullptr){
		resourcesAllocated = true;
		for(int i = 0; i < resources.size(); i++){
			resources[i].status = TagResource::RESOURCE_MEMORY_RESERVED;
		}
	}
}
