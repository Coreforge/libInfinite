#include "sbspHandle.h"

#include <tags/xml/generated/sbsp.h>

#include <cassert>
#include "../TagManager.h"

void sbspHandle::setup(){
	sbsp* str = (sbsp*)root;
}

uint32_t sbspHandle::getGeoInstanceCount(){
	sbsp* str = (sbsp*)root;
	return str->instanced_geometry_instances_ent.count;
}

geoInstanceInfo sbspHandle::getGeoInstanceInfo(uint32_t index){
	sbsp* str = (sbsp*)root;
	assert(index < str->instanced_geometry_instances_ent.count && "Geo Instance index out of bounds");
	instanced_geometry_instances* inst = &str->instanced_geometry_instances_ent.block[index];

	geoInstanceInfo info;
	info.meshIndex = inst->Runtime_geo_mesh_index;

	info.position = glm::vec3(inst->position.x,inst->position.y,inst->position.z);
	info.scale = glm::vec3(inst->scale.x,inst->scale.y,inst->scale.z);

	info.left = glm::vec3(inst->left.x,inst->left.y,inst->left.z);
	info.forward = glm::vec3(inst->forward.x,inst->forward.y,inst->forward.z);
	info.up = glm::vec3(inst->up.x,inst->up.y,inst->up.z);

	if(item->tagManager != nullptr){
		Tag* tmptag = this->item->tagManager->getTag(inst->Runtime_geo_mesh_reference.globalId);
		info.geo = dynamic_cast<rtgoHandle*>(tmptag);
	} else {
		info.geo = nullptr;
	}
	return info;
}
