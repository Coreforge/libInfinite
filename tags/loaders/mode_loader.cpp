#include "mode_loader.h"
#include "../TagLoader.h"

#define MODE_STRUCTURE_IMPL
#include "../xml/generated/mode.h"

int loadMODETag(Item* item, void* &dest, bool loadChildren, TagManager* manager, Tag* tag){
	TagLoader loader;
	mode* root;
	int result = loader.loadTag(item, dest, mode_structure, sizeof(mode_structure), loadChildren, manager, tag);
	root = (mode*)dest;
	return result;

}
