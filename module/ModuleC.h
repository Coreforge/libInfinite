#pragma once

#include "../export.h"

// this file is for the C API
extern "C"{

	// creates a new module object and loads a module from the specified path (must be null terminated)
	// path: null terminated string, path to the module
	// returns: module Handle (pointer to the module object)
	EXPORT_FUNC void* loadModuleFromPath(const char* path);

	// deletes the module object and closes the file
	// modHandle: module Handle (pointer returned by loadModuleFromPath)
	EXPORT_FUNC void destroyModule(void* modHandle);

	// returns a handle to first item, similar to windows' getFirstFile
	// modHandle: module Handle (pointer returned by loadModuleFromPath)
	// returns: item Handle
	EXPORT_FUNC void* getFirstItem(void* modHandle);

	// returns a handle to next item, similar to windows' getNextFile, or null if there is no next item
	// modHandle: module Handle (pointer returned by loadModuleFromPath)
	// returns: item Handle or null
	EXPORT_FUNC void* getNextItem(void* modHandle);

	// returns a handle to the item with that path or null
	// modHandle: module Handle (pointer returned by loadModuleFromPath)
	// path: path of the item
	// returns: item Handle or null of no item with that path exists
	EXPORT_FUNC void* getItem(void* modHandle, const char* path);
}
