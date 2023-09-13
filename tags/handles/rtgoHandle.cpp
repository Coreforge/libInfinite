#include "rtgoHandle.h"

#include <tags/xml/generated/rtgo.h>

#include <cassert>

void rtgoHandle::setup(){
	rtgo* str = (rtgo*)root;
	geoHandle.struct_ptr = &str->render_geometry_ent;
	geoHandle.tag = this;
}

meshData rtgoHandle::getMeshData(uint32_t index){
	rtgo* str = (rtgo*)root;
	assert(index < str->Per_Mesh_Data_ent.count && "Mesh index out of bounds");

	auto inst = str->Per_Mesh_Data_ent.block[index];

	meshData meshdata;

	meshdata.position = glm::vec3(inst.Position.x,inst.Position.y,inst.Position.z);
	meshdata.scale = glm::vec3(inst.Scale.x,inst.Scale.y,inst.Scale.z);

	meshdata.left = glm::vec3(inst.Left.x,inst.Left.y,inst.Left.z);
	meshdata.forward = glm::vec3(inst.Forward.x,inst.Forward.y,inst.Forward.z);
	meshdata.up = glm::vec3(inst.Up.x,inst.Up.y,inst.Up.z);
	return meshdata;
}
