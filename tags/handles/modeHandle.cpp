#include "modeHandle.h"

#include <tags/xml/generated/mode.h>

#include <cassert>
#include <tags/TagManager.h>

void modeHandle::setup(){
	mode* str = (mode*)root;
	geoHandle.struct_ptr = &str->render_geometry_ent;
	geoHandle.tag = this;
}

uint16_t modeHandle::getMeshIndex(uint32_t region, uint32_t permutation){
	mode* str = (mode*)root;

	for(int r = 0; r < str->regions_ent.count; r++){
		if(str->regions_ent.block[r].name == region){
			for(int p = 0; p < str->regions_ent.block[r].permutations_ent.count; p++){
				if(str->regions_ent.block[r].permutations_ent.block[p].name == permutation){
					return str->regions_ent.block[r].permutations_ent.block[p].mesh_index;
				}
			}
		}
	}
	return 0;
}

uint16_t modeHandle::getMeshCount(uint32_t region, uint32_t permutation){
	mode* str = (mode*)root;

	for(int r = 0; r < str->regions_ent.count; r++){
		if(str->regions_ent.block[r].name == region){
			for(int p = 0; p < str->regions_ent.block[r].permutations_ent.count; p++){
				if(str->regions_ent.block[r].permutations_ent.block[p].name == permutation){
					return str->regions_ent.block[r].permutations_ent.block[p].mesh_count;
				}
			}
		}
	}
	return 0;
}

mat_Handle* modeHandle::getMaterial(uint32_t index){
	mode* str = (mode*)root;
	assert(index < str->materials_ent.count && "Material index out of range!");
 	Tag* tag = item->tagManager->getTag(str->materials_ent.block[index].material.globalId);
 	return dynamic_cast<mat_Handle*>(tag);

}

std::vector<mat_Handle*> modeHandle::getMaterials(){
	mode* str = (mode*)root;
	std::vector<mat_Handle*> mats;
	mats.resize(str->materials_ent.count);
	for(int i = 0; i < str->materials_ent.count; i++){
		mats[i] = getMaterial(i);
	}
	return mats;
}
