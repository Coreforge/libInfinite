#pragma once
#include "Module.h"
#include "ModuleItem.h"
#include "ModuleNode.h"
#include "../logger/logger.h"

#include <vector>
#include <string>
#include <sstream>

class ModuleManager{
public:
	std::vector<Module*> modules;
	std::pair<uint64_t,uint64_t> getSizes(ModuleNode* node);	// first is uncompressed, second is compressed
	ModuleNode* rootNode;
	Logger* logger;

	int addModule(Module* module);
	int addModule(const char* path);
	void buildNodeTree();
	void deleteNodeTree();

private:
	void deleteTreeRecursive(ModuleNode* node);
};
