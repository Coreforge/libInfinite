#include "ModuleC.h"

#include "Module.h"
#include "../logger/ConsoleLogger.h"

#include <string>

void* loadModuleFromPath(const char* path){
	Module* module = new Module();
	ConsoleLogger* logger = new ConsoleLogger();
	module->logger = logger;
	module->loadModule(path);
	module->currentItem = module->items.begin();
	return module;
}

void destroyModule(void* modHandle){
	((Module*)modHandle)->closeModule();
	delete ((Module*)modHandle)->logger;
	delete ((Module*)modHandle);
}

void* getFirstItem(void* modHandle){
	Module* module = (Module*)modHandle;
	module->currentItem = module->items.begin();
	return module->currentItem->second;
}

void* getNextItem(void* modHandle){
	Module* module = (Module*)modHandle;
	if(module->currentItem == module->items.end()){
		// last item was reached
		return nullptr;
	}
	module->currentItem++;
	return module->currentItem->second;
}

void* getItem(void* modHandle, const char* path){
	Module* module = (Module*)modHandle;
	std::string p = std::string(path);
	if(module->items.count(p) == 0){
		// no item with that path
		return nullptr;
	}
	return module->items[p];
}
