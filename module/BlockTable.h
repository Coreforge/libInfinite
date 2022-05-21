#pragma once

#include <stdint.h>
#include "ModuleBlock.h"
#include <vector>

class Module;

class BlockTable{
public:
	uint64_t offset;
	uint32_t count;
	Module* module;
	std::vector<ModuleBlock*> blocks;
};
