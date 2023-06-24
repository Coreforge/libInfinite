#pragma once

#include "../Tag.h"
#include "rtgoHandle.h"

#include <stdint.h>

// for vectors
#include <glm/glm.hpp>

struct geoInstanceInfo{
	glm::vec3 scale;
	glm::vec3 position;
	glm::vec3 forward;
	glm::vec3 left;
	glm::vec3 up;
	rtgoHandle* geo;
	uint16_t meshIndex;
};

class sbspHandle : public Tag{
public:

	uint32_t getGeoInstanceCount();
	geoInstanceInfo getGeoInstanceInfo(uint32_t index);

	void setup();
};
