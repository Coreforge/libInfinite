#include "mat_loader.h"
#define MAT__STRUCTURE_IMPL
#include "../xml/generated/mat.h"
//#include "../xml/generated/sbsp.h"
#include "../TagLoader.h"

int loadMAT_Tag(Item* item, void* &dest, bool loadChildren, TagManager* manager, Tag* tag){
	TagLoader loader;
	mat_* root;
	int result = loader.loadTag(item, dest, mat__structure, sizeof(mat__structure), loadChildren, manager, tag);
	root = (mat_*)dest;
	return result;
	//return 0;
}
