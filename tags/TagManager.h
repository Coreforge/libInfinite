#pragma once

#include "../module/ModuleManager.h"
#include "Tag.h"
#include "../logger/logger.h"

#include <stdint.h>
#include <map>

class TagManager{
public:

	TagManager(ModuleManager* manager, Logger* logger);

	Tag* getTag(uint32_t globalId);
	int addTag(ModuleItem* itm);
	int addTag(uint32_t globalId);

	Logger* logger;
	ModuleManager* man;

	std::map<uint32_t,Tag*> loadedTags;

private:
	Tag* getTagObject(uint32_t type);

};
