#pragma once

#include <vector>
#include <string>
#include "../tags/xml/infiniteStructs.h"

enum DataType{
	DT_UINT8,
	DT_UINT16,
	DT_UINT32,
	DT_UINT64,
	DT_UINT8VEC2,
	DT_UINT8VEC3UNIT,	// unit vector, length of 1
	DT_UINT8VEC4,
	DT_UINT16VEC2,
	DT_UINT16VEC4,
	DT_FLOAT32,
	DT_FLOAT32VEC2,
	DT_FLOAT32VEC3,
	DT_FLOAT32VEC4,
	DT_UINT8ARGB,
	DT_UDECN4
};

enum BufferStatus{
	MDL_BUFFER_INVALID,		// there is a valid buffer, but that pointer isn't valid yet and has to be requested from the tag first
	MDL_BUFFER_VALID,		// the pointer can be used
	MDL_BUFFER_UNAVAILABLE	// there is no valid buffer here, move along
};

class Tag;

class Buffer{
public:
	uint32_t size;
	uint32_t offset;
	uint32_t count;
	uint8_t stride;
	Tag* tag;
	uint8_t status;
	uint16_t dataType;
	void* data = nullptr;
	int ensureBuffer();
};

class LODMesh;

class LODMeshPart{
public:
	uint16_t materialIndex;
	uint32_t indexStart;
	uint32_t indexCount;
	LODMesh* mesh;
};

class LODMesh{
public:
	std::vector<LODMeshPart> parts;
	Buffer IndexBuffer;
	Buffer VertexBuffers[19];
	void* lodmeshptr;
};

class Mesh{
public:
	std::vector<LODMesh> lods;
	int meshIndex;
	void* meshptr;
};

class ModelPermutation{
public:
	string_id name;
	std::string nameStr;
	std::vector<Mesh> meshes;
};

class ModelRegion{
public:
	string_id name;
	std::string nameStr;
	std::vector<ModelPermutation> permutations;

};

class RenderModel{
public:
	void* geoptr;
	std::vector<ModelRegion> regions;
};
