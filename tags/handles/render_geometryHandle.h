#pragma once
#include <stdint.h>
#include <tags/Tag.h>
#include <unordered_map>
#include <memory>

#include "baseClasses/ManagedBufferHandleBase.h"
#include "baseClasses/GenericHandle.h"

// just to avoid needing a ton of functions to get all the information
struct partInfo{
	uint32_t indexStart;
	uint32_t indexCount;
	uint16_t materialIndex;
};

struct bufferInfo{
	uint32_t count;
	uint32_t stride;
	uint32_t size;
	void* data;
};

class render_geometryHandle{
private:

	// There's no setter for now, as an object just gets created in the getter if there isn't one. Only one type should be used per index for the lifetime of the tag

	template<class t, typename idx>
	std::shared_ptr<t> getGenericMapEntry(idx elementIndex,  std::unordered_map<idx,std::weak_ptr<GenericHandle>> theMap){
		if(theMap.find(elementIndex) == theMap.end() || theMap[elementIndex].expired()){
			// not present, create a new element
			std::shared_ptr<t> ptr = std::make_shared<t>();
			theMap[elementIndex] = ptr;
			return ptr;
		}
		// there is an existing and valid element
		return std::dynamic_pointer_cast<t>(theMap[elementIndex].lock());
	}

	template<typename idx>
	bool checkGenericMapEntry(idx elementIndex,  std::unordered_map<idx,std::weak_ptr<GenericHandle>> theMap){
		if(theMap.find(elementIndex) == theMap.end() || theMap[elementIndex].expired()){
			return false;
		}
		return true;
	}

public:
	void* struct_ptr;
	Tag* tag;

	void positionCompressionScale(float vec[3]);
	void positionCompressionOffset(float vec[3]);
	uint16_t getIndexBufferIndex(uint32_t meshIndex, uint32_t lod);
	// for all 19 types of vertex buffers
	uint16_t getVertexBufferIndex(uint32_t meshIndex, uint32_t lod, int type);
	uint32_t getPartCount(uint32_t meshIndex, uint32_t lod);
	partInfo getPartInfo(uint32_t meshIndex, uint32_t lod, uint32_t part);

	bool hasMeshInfo(uint32_t meshIndex, uint32_t lod);

	// returns a shared pointer for the mesh info object if one exists, or creates a new one if no object exists
	template<class t>
	std::shared_ptr<t> getMeshInfo(uint32_t meshIndex, uint32_t lod){
		static_assert(std::is_base_of<GenericHandle,t>::value, "Type must be derived from GenericHandle!");
		uint64_t idx = ((uint64_t)meshIndex) << 32 | lod;

		return getGenericMapEntry<t,uint64_t>(idx, meshInfoMap);
		/*if(meshInfoMap.count(idx) != 0 && !meshInfoMap[idx].expired()){
			return meshInfoMap[idx].lock();
		}

		// object needs to be created
		t something;
		std::shared_ptr<t> shrP = std::make_shared(something);
		meshInfoMap[idx] = shrP;
		return shrP;*/
	}


	// for now this just returns a pointer to the pc_vertex_buffer struct
	// This isn't that great, but makes things just a bit easier for now

	// managed: The managed buffer handle type
	// base: The base buffer handle type
	// These are only used if a new buffer gets created, otherwise they are ignored
	bufferInfo getVertexBuffer(uint16_t index);

	template<class t>
	std::shared_ptr<t> getVertexBufferInfo(uint16_t idx){
		static_assert(std::is_base_of<GenericHandle,t>::value, "Type must be derived from GenericHandle!");
		return getGenericMapEntry<t,uint16_t>(idx, vtxWeakPointers);
	}

	bool hasVertexBufferInfo(uint16_t idx);

	// same, but pc_index_buffer this time
	bufferInfo getIndexBuffer(uint16_t index);
	template<class t>
	std::shared_ptr<t> getIndexBufferInfo(uint16_t idx){
		static_assert(std::is_base_of<GenericHandle,t>::value, "Type must be derived from GenericHandle!");
		return getGenericMapEntry<t,uint16_t>(idx, idxWeakPointers);
	}

	bool hasIndexBufferInfo(uint16_t idx);

private:
	std::unordered_map<uint16_t, std::weak_ptr<GenericHandle>> vtxWeakPointers;
	std::unordered_map<uint16_t, std::weak_ptr<GenericHandle>> idxWeakPointers;
	std::unordered_map<uint64_t, std::weak_ptr<GenericHandle>> meshInfoMap;
};
