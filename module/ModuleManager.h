#pragma once
#include "Module.h"
#include "ModuleItem.h"
#include "ModuleNode.h"
#include "../logger/logger.h"

#include <vector>
#include <string>
#include <sstream>
#include <shared_mutex>
#include <map>

class ModuleManager{
public:
	ModuleManager(Logger* logger);

	std::vector<Module*> modules;
	std::pair<uint64_t,uint64_t> getSizes(ModuleNode* node);	// first is uncompressed, second is compressed
	ModuleNode* rootNode;
	Logger* logger;

	std::shared_timed_mutex mutex;

	int addModule(Module* module);
	int addModule(const char* path);
	void buildNodeTree();
	void deleteNodeTree();
	ModuleNode* getNode(std::string path);

	std::map<uint32_t, ModuleItem*> assetIdItems;

private:
	void deleteTreeRecursive(ModuleNode* node);
};
