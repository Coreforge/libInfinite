#pragma once

#include "../Tag.h"
#include "render_geometryHandle.h"
#include <glm/glm.hpp>

struct meshData{
	glm::vec3 scale;
	glm::vec3 position;
	glm::vec3 forward;
	glm::vec3 left;
	glm::vec3 up;
};

class rtgoHandle : public Tag{
public:
	render_geometryHandle geoHandle;
	meshData getMeshData(uint32_t index);

	void setup();
};
