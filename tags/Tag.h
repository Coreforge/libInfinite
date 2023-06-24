#pragma once

#include "../Item.h"

#include <vector>

class TagResource{
public:
	enum status{
		RESOURCE_FREE,				// nothing is loaded yet, not usable
		RESOURCE_MEMORY_RESERVED,	// the data hasn't been loaded, but at the very least the address space has been reserved
		RESOURCE_LOADED				// the data has been loaded and can be used
	};
	ModuleItem* moduleItem;
	uint32_t offset;
	uint32_t size;
	uint16_t status;
};

class Tag{
public:
	Item* item;
	void* root;
	int uses;

	virtual ~Tag();

	virtual void setup();

	void* getResource(uint32_t offset, uint32_t size);
	void loadAllResources();
	// only valid once the resources have been allocated
	uint32_t getResourceSize();

private:
	std::vector<TagResource> resources;
	void* resourcePointer = nullptr;
	bool resourcesAllocated = false;
	void loadResource(int index);
	void allocResources();
	uint32_t size;
};
