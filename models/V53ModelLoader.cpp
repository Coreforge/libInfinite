#include "V53ModelLoader.h"

#include "../tags/xml/generated/mode.h"

#include <sstream>
#include <iomanip>

std::string V53ModelLoader::toHex(uint32_t i){
	std::stringstream s;
	s << std::hex << std::showbase << std::setw(8) << std::setfill('0') << i;
	return s.str();
}

uint16_t V53ModelLoader::convertDataType(uint16_t type){
	switch(type){
	case FORMAT_REAL:
		return DataType::DT_FLOAT32;
	case FORMAT_REALVECTOR2D:
		return DataType::DT_FLOAT32VEC2;
	case FORMAT_REALVECTOR3D:
		return DataType::DT_FLOAT32VEC3;
	case FORMAT_REALVECTOR4D:
		return DataType::DT_FLOAT32VEC4;
	case FORMAT_WORDVECTOR4DNORMALIZED:
		return DataType::DT_UINT16VEC4;
	case FORMAT_WORDVECTOR2DNORMALIZED:
		return DataType::DT_UINT16VEC2;
	case FORMAT_BYTEARGBCOLOR:
		return DataType::DT_UINT8ARGB;
	case FORMAT_10_10_10_2_SIGNEDNORMALIZEDPACKEDASUNORM:
		return DataType::DT_UDECN4;
	case FORMAT_BYTEUNITVECTOR3D:
		return DataType::DT_UINT8VEC3UNIT;
	case FORMAT_BYTEVECTOR4D:
		return DataType::DT_UINT8VEC4;
	default:
		break;
	}
	return -1;
}

void V53ModelLoader::loadModel(RenderModel &model, Tag* tag, StringIDLUT* lut){
	mode* tagData = (mode*)tag->root;
	// this assumes that there is exactly one resource there, but I think that is a safe assumption
	// CAUTION: Check this though if any problems pop up
	mesh_resource* resource = tagData->render_geometry_ent.mesh_package_ent.mesh_resource_groups_ent.block->mesh_resource_res.block;

	model.geoptr = &tagData->render_geometry_ent;
	for(int i = 0; i < tagData->regions_ent.count; i++){
		ModelRegion region;
		int s = sizeof(regions);
		region.name = tagData->regions_ent.block[i].name;
		region.nameStr = lut->lookupID(region.name);
		for(int p = 0; p < tagData->regions_ent.block[i].permutations_ent.count; p++){
			ModelPermutation permutation;
			permutations* perm = &tagData->regions_ent.block[i].permutations_ent.block[p];
			permutation.name = tagData->regions_ent.block[i].permutations_ent.block[p].name;
			permutation.nameStr = lut->lookupID(permutation.name);


			for(int m = perm->mesh_index; m < perm->mesh_index + perm->mesh_count; m++){
				meshes* meshptr = &tagData->render_geometry_ent.meshes_ent.block[m];
				Mesh mesh;
				mesh.meshIndex = m;
				mesh.meshptr = (void*)meshptr;
				for(int lod = 0; lod < meshptr->LOD_render_data_ent.count; lod++){
					LODMesh lodmesh;
					LOD_render_data* lodptr = &meshptr->LOD_render_data_ent.block[lod];
					lodmesh.lodmeshptr = (void*)lodptr;
					for(int part = 0; part < meshptr->LOD_render_data_ent.block[lod].parts_ent.count; part++){
						LODMeshPart lodpart;
						lodpart.indexStart = meshptr->LOD_render_data_ent.block[lod].parts_ent.block[part].index_start;
						lodpart.indexCount = meshptr->LOD_render_data_ent.block[lod].parts_ent.block[part].index_count;
						lodpart.materialIndex = meshptr->LOD_render_data_ent.block[lod].parts_ent.block[part].material_index;
						lodmesh.parts.emplace_back(lodpart);
					}

					// set up the index buffer
					uint16_t index_idx = lodptr->index_buffer_index;
					pc_index_buffers* indexBuf = &resource->pc_index_buffers_ent.block[index_idx];
					lodmesh.IndexBuffer.tag = tag;
					lodmesh.IndexBuffer.count = indexBuf->count;
					lodmesh.IndexBuffer.size = indexBuf->d3dbuffer_ent.byte_width;
					lodmesh.IndexBuffer.offset = indexBuf->offset;
					lodmesh.IndexBuffer.stride = indexBuf->stride;
					lodmesh.IndexBuffer.status = BufferStatus::MDL_BUFFER_INVALID;
					if(indexBuf->stride == 2){
						lodmesh.IndexBuffer.dataType = DataType::DT_UINT16;
					} else {
						lodmesh.IndexBuffer.dataType = DataType::DT_UINT32;
					}
					lodmesh.IndexBuffer.ensureBuffer();
					// and now the vertex buffers. They're basically the same, but the structs are different, so they have to be done separately
					// there are 19 vertex buffers, though usually only a few are actually used
					for(int b = 0; b < 19; b++){
						uint16_t vertex_idx = lodptr->vertex_buffer_index[b];
						if(vertex_idx == 0xffff){
							// no vertex buffer of this type is used
							lodmesh.VertexBuffers[b].status = BufferStatus::MDL_BUFFER_UNAVAILABLE;
							continue;
						}
						pc_vertex_buffers* vertexBuf = &resource->pc_vertex_buffers_ent.block[vertex_idx];
						lodmesh.VertexBuffers[b].tag = tag;
						lodmesh.VertexBuffers[b].count = vertexBuf->count;
						lodmesh.VertexBuffers[b].size = vertexBuf->d3dbuffer_ent.byte_width;
						lodmesh.VertexBuffers[b].offset = vertexBuf->offset;
						lodmesh.VertexBuffers[b].stride = vertexBuf->stride;
						lodmesh.VertexBuffers[b].status = BufferStatus::MDL_BUFFER_INVALID;
						lodmesh.VertexBuffers[b].dataType = convertDataType(vertexBuf->enum_format);
					}

					mesh.lods.emplace_back(lodmesh);
				}
				permutation.meshes.emplace_back(mesh);
			}

			region.permutations.emplace_back(permutation);
		}
		model.regions.emplace_back(region);
	}

	// not ideal for the memory footprint, but whatever, this is just for testing
	tag->loadAllResources();


	/*
	 *  Info for loading resources:
	 *
	 *  The Tag object contains a vector which stores pointers to tag structures which store data about the resource. The resource
	 *  struct contained in tag structs contains the index of the relevant pointer in that vector
	 *
	 */


}
