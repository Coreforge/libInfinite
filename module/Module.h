#pragma once

#include <stdint.h>
#include <cstdio>
#include <string>
#include <map>

#include "BlockTable.h"
#include "ModuleItem.h"

#include "../logger/logger.h"

class Module{

public:

	// file needs to be opened with fopen64 due to the size of some modules
	int loadModule(FILE* file, const char* name);
	int loadModule(const char* path);
	void closeModule();

	Logger* logger;

	FILE* fileHandle;	// this should hopefully always stay opened while this module is loaded, but just in case
	bool handleValid;	// it doesn't this bool indicated that
	FILE* hd1Handle;	// handle to the _hd1 file if it exists. NULL otherwise

	std::string path;
	std::string name;

	uint32_t version;	// at 0x04
	uint32_t fileCount; // at 0x10
	uint32_t stringsSize; // at 0x24
	uint32_t table3Count; // at 0x28
	uint32_t blockCount;  // at 0x2c
	uint64_t hd1_delta;	  // at 0x38
	uint32_t data_size;	  // at 0x40
	uint64_t blockTableOffset;
	uint64_t dataOffset;

	uint64_t stringOffset;


	BlockTable blockTable;
	std::map<std::string, ModuleItem*> items;
	std::map<std::string, ModuleItem*>::iterator currentItem;
};
