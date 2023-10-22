#include "render_geometryHandle.h"

#include <cassert>
#include <atomic>

#include <unistd.h>
#include <stdio.h>

// the struct is the same everywhere, so this should work fine
// The include path will have to be changed though once xml2h uses the GUIDs
#include <tags/xml/generated/mode.h>


#define MESH_NO_INDEX_BUFFER (1<<4)

/*
 * reused struct fields:
 * 	pc_vertex_buffers:
 * 		generated_pad9e95: used as the atomic indicator int
 * 		m_resource: actual buffer handle pointer
 *
 *
 */

void render_geometryHandle::positionCompressionScale(float vec[3]){
	mode::render_geometry* str = (mode::render_geometry*) struct_ptr;

	// probably not necessary, but just as a safety measure
	assert(str->compression_info_ent.count != 0 && "No mesh compression info?");

	point3D minP = str->compression_info_ent.block->position_bounds_0;
	point3D maxP = str->compression_info_ent.block->position_bounds_1;

	vec[0] = minP.y - minP.x;	// xmax - xmin
	vec[1] = maxP.x - minP.z;	// ymax - ymin
	vec[2] = maxP.z - maxP.y;	// zmax - zmin
}

void render_geometryHandle::positionCompressionOffset(float vec[3]){
	mode::render_geometry* str = (mode::render_geometry*) struct_ptr;

	// probably not necessary, but just as a safety measure
	assert(str->compression_info_ent.count != 0 && "No mesh compression info?");

	point3D minP = str->compression_info_ent.block->position_bounds_0;
	point3D maxP = str->compression_info_ent.block->position_bounds_1;

	vec[0] = minP.x;	// xmin
	vec[1] = minP.z;	// ymin
	vec[2] = maxP.y;	// zmin
}

void render_geometryHandle::UVCompressionScale(float vec[2], int channel){
	mode::render_geometry* str = (mode::render_geometry*) struct_ptr;

	// probably not necessary, but just as a safety measure
	assert(str->compression_info_ent.count != 0 && "No mesh compression info?");

	point2D minP;
	point2D maxP;

	switch(channel){
	default:
	case 0:
		minP = str->compression_info_ent.block->texcoord_bounds_0;
		maxP = str->compression_info_ent.block->texcoord_bounds_1;
		break;
	case 1:
		minP = str->compression_info_ent.block->texcoord_bounds2_0;
		maxP = str->compression_info_ent.block->texcoord_bounds2_1;
		break;
	case 2:
		minP = str->compression_info_ent.block->texcoord_bounds3_0;
		maxP = str->compression_info_ent.block->texcoord_bounds3_1;
		break;
	}

	vec[0] = minP.y - minP.x;	// xmax - xmin
	vec[1] = maxP.y - maxP.x;	// ymax - ymin
}

void render_geometryHandle::UVCompressionOffset(float vec[2], int channel){
	mode::render_geometry* str = (mode::render_geometry*) struct_ptr;

	// probably not necessary, but just as a safety measure
	assert(str->compression_info_ent.count != 0 && "No mesh compression info?");

	point2D minP;
	point2D maxP;

	switch(channel){
	default:
	case 0:
		minP = str->compression_info_ent.block->texcoord_bounds_0;
		maxP = str->compression_info_ent.block->texcoord_bounds_1;
		break;
	case 1:
		minP = str->compression_info_ent.block->texcoord_bounds2_0;
		maxP = str->compression_info_ent.block->texcoord_bounds2_1;
		break;
	case 2:
		minP = str->compression_info_ent.block->texcoord_bounds3_0;
		maxP = str->compression_info_ent.block->texcoord_bounds3_1;
		break;
	}

	vec[0] = minP.x;	// xmin
	vec[1] = maxP.x;	// ymin
}

uint16_t render_geometryHandle::getIndexBufferIndex(uint32_t meshIndex, uint32_t lod){
	mode::render_geometry* str = (mode::render_geometry*) struct_ptr;

	assert(meshIndex < str->meshes_ent.count && "Invalid mesh index");
	assert(lod < str->meshes_ent.block[meshIndex].LOD_render_data_ent.count && "Invalid LOD");
	return str->meshes_ent.block[meshIndex].LOD_render_data_ent.block[lod].index_buffer_index;

}

uint16_t render_geometryHandle::getVertexBufferIndex(uint32_t meshIndex, uint32_t lod, int type){
	mode::render_geometry* str = (mode::render_geometry*) struct_ptr;

	assert(type < 19 && "Invalid vertex buffer type");
	assert(meshIndex < str->meshes_ent.count && "Invalid mesh index");
	assert(lod < str->meshes_ent.block[meshIndex].LOD_render_data_ent.count && "Invalid LOD");
	return str->meshes_ent.block[meshIndex].LOD_render_data_ent.block[lod].vertex_buffer_index[type];

}

bufferInfo render_geometryHandle::getVertexBuffer(uint16_t index){
	mode::render_geometry* str = (mode::render_geometry*) struct_ptr;

	assert(str->mesh_package_ent.mesh_resource_groups_ent.count != 0 && "No mesh resource!");
	assert(index < str->mesh_package_ent.mesh_resource_groups_ent.block[0].mesh_resource_res.block->pc_vertex_buffers_ent.count && "Vertex buffer index out of range!");

	pc_vertex_buffers* buf = &str->mesh_package_ent.mesh_resource_groups_ent.block[0].mesh_resource_res.block->pc_vertex_buffers_ent.block[index];

	bufferInfo ret;
	ret.count = buf->count;
	ret.stride = buf->stride;
	ret.size = buf->d3dbuffer_ent.byte_width;
	ret.dataType = buf->enum_format;
	if(buf->d3dbuffer_ent.d3d_buffer.size == 0){
		// in a separate resource file (at least mode and rtgo)
		ret.data = tag->getResource(buf->offset, buf->d3dbuffer_ent.byte_width);
	} else {
		// embedded into the tag file (so far seen in pmdf)
		ret.data = buf->d3dbuffer_ent.d3d_buffer.data;
	}

	return ret;

	/*// this just ensures the buffer won't get deleted
	uint8_t desired = 1;
	uint8_t desired2 = 0;

	// Yes, this isn't thread safe, this should be done with atomics too, but idc
	if(buf->generated_pad9e95 == 0xbcbc){
		buf->generated_pad9e95 = 0;
	}

	// since atomic_compare_exchange can only compare with one value, but the indicator might be 2 if another thread is creating a buffer handle too (unlikely), it would fail even if there is a buffer handle. Waiting should fix that
	int d = 0;
	while(d < 10000){
		if(std::atomic_compare_exchange_weak(((std::atomic_uint8_t*)&buf->generated_pad9e95), &desired, 2)){
			// the buffer is locked now
			// the actual handle doesn't have to be created, just check if a managed one exists and return that, or create one and return it

			if(vtxWeakPointers.count(index) == 0 || vtxWeakPointers[index].expired()){
				// no handle
				std::shared_ptr<managed> shrP = std::make_shared((base*)buf->m_resource, userptr);
				vtxWeakPointers[index] = shrP;
				buf->generated_pad9e95 = 1;
				return shrP;
			}

			// there already is a managed handle, just get a new shared_ptr
			return vtxWeakPointers[index].lock();

		} else if(std::atomic_compare_exchange_weak(((std::atomic_uint8_t*)&buf->generated_pad9e95), &desired2, 2)){
			// no buffer handle exists, so it must be created first
			buf->m_resource = new base(tag->getResource(buf->offset, buf->count * buf->stride), buf->count * buf->stride, buf->stride, userptr, &buf->generated_pad9e95);
			// create a managed handle, add that to the map, and return the shared pointer
			std::shared_ptr<managed> shrP = std::make_shared((base*)buf->m_resource, userptr);
			vtxWeakPointers[index] = shrP;
			buf->generated_pad9e95 = 1;
			return shrP;
		}
		usleep(1);
		d++;
	}

	printf("Big Issue: That timeout ran out, and a struct pointer was returned instead of a std::shared_ptr. This is really bad and should never happen! (render_geometryHandle.cpp)\n");
	//return &str->mesh_package_ent.mesh_resource_groups_ent.block[0].mesh_resource_res.block->pc_vertex_buffers_ent.block[index];
	return std::shared_ptr<managed>();*/
}

bool render_geometryHandle::hasMeshInfo(uint32_t meshIndex, uint16_t lod, uint16_t channel){
	uint64_t idx = ((uint64_t)meshIndex) << 32 | lod << 16 | channel;
	return checkGenericMapEntry(idx, meshInfoMap);
}

bool render_geometryHandle::hasVertexBufferInfo(uint16_t idx, uint16_t channel){
	uint64_t nidx = idx | channel << 16;
	return checkGenericMapEntry(nidx, vtxWeakPointers);
}

uint16_t render_geometryHandle::getMeshFlags(uint32_t meshIndex){
	mode::render_geometry* str = (mode::render_geometry*) struct_ptr;
	assert(meshIndex < str->meshes_ent.count && "Invalid mesh index");
	return str->meshes_ent.block[meshIndex].flags_mesh_flags;
}

uint8_t render_geometryHandle::getIndexBufferType(uint32_t meshIndex){
	mode::render_geometry* str = (mode::render_geometry*) struct_ptr;
	assert(meshIndex < str->meshes_ent.count && "Invalid mesh index");
	return str->meshes_ent.block[meshIndex].enum_index_buffer_type;
}

bufferInfo render_geometryHandle::getIndexBuffer(uint16_t index){
	mode::render_geometry* str = (mode::render_geometry*) struct_ptr;

	assert(str->mesh_package_ent.mesh_resource_groups_ent.count != 0 && "No mesh resource!");
	assert(index < str->mesh_package_ent.mesh_resource_groups_ent.block[0].mesh_resource_res.block->pc_index_buffers_ent.count && "Index buffer index out of range!");

	pc_index_buffers* buf = &str->mesh_package_ent.mesh_resource_groups_ent.block[0].mesh_resource_res.block->pc_index_buffers_ent.block[index];

	bufferInfo ret;
	ret.count = buf->count;
	ret.stride = buf->stride;
	ret.size = buf->d3dbuffer_ent.byte_width;
	ret.data = tag->getResource(buf->offset, buf->d3dbuffer_ent.byte_width);

	return ret;
}

bool render_geometryHandle::hasIndexBufferInfo(uint16_t idx, uint16_t channel){
	uint64_t nidx = idx | channel << 16;
	return checkGenericMapEntry(nidx, idxWeakPointers);
}

partInfo render_geometryHandle::getPartInfo(uint32_t meshIndex, uint32_t lod, uint32_t part){
	mode::render_geometry* str = (mode::render_geometry*) struct_ptr;

	assert(meshIndex < str->meshes_ent.count && "Invalid mesh index");
	assert(lod < str->meshes_ent.block[meshIndex].LOD_render_data_ent.count && "Invalid LOD");
	assert(part < str->meshes_ent.block[meshIndex].LOD_render_data_ent.block[lod].parts_ent.count && "Part index out of range!");

	partInfo info;

	info.indexStart = str->meshes_ent.block[meshIndex].LOD_render_data_ent.block[lod].parts_ent.block[part].index_start;
	info.indexCount = str->meshes_ent.block[meshIndex].LOD_render_data_ent.block[lod].parts_ent.block[part].index_count;
	info.materialIndex = str->meshes_ent.block[meshIndex].LOD_render_data_ent.block[lod].parts_ent.block[part].material_index;

	return info;
}

uint32_t render_geometryHandle::getPartCount(uint32_t meshIndex, uint32_t lod){
	mode::render_geometry* str = (mode::render_geometry*) struct_ptr;

	assert(meshIndex < str->meshes_ent.count && "Invalid mesh index");
	assert(lod < str->meshes_ent.block[meshIndex].LOD_render_data_ent.count && "Invalid LOD");

	return str->meshes_ent.block[meshIndex].LOD_render_data_ent.block[lod].parts_ent.count;
}


/*template<class t>
	std::shared_ptr<t> render_geometryHandle::getMeshInfo(uint32_t meshIndex, uint32_t lod){
	uint64_t idx = ((uint64_t)meshIndex) << 32 | lod;
	if(meshInfoMap.count(idx) != 0 && !meshInfoMap[idx].expired()){
		return meshInfoMap[idx].lock();
	}

	// object needs to be created
	t something;
	std::shared_ptr<t> shrP = std::make_shared(something);
	meshInfoMap[idx] = shrP;
	return shrP;
}*/

