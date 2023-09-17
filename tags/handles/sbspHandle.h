#pragma once

#include "../Tag.h"
#include "rtgoHandle.h"
#include "mat_Handle.h"

#include <stdint.h>
#include <vector>

// for vectors
#include <glm/glm.hpp>

#define MESH_FLAGS_OVERRIDE_MESH_IS_CUSTOM_SHADOW_CASTER (1<<3)

struct geoInstanceInfo{
	glm::vec3 scale;
	glm::vec3 position;
	glm::vec3 forward;
	glm::vec3 left;
	glm::vec3 up;
	rtgoHandle* geo;
	uint16_t meshIndex;
	uint16_t mesh_flags_override;
	std::vector<mat_Handle*> materials;
};

class sbspHandle : public Tag{
public:

	uint32_t getGeoInstanceCount();
	geoInstanceInfo getGeoInstanceInfo(uint32_t index);

	void setup();
};
