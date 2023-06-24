#pragma once
#include <tags/Tag.h>
#include <stdint.h>

#include "render_geometryHandle.h"
#include "mat_Handle.h"


class modeHandle : public Tag{
public:
	render_geometryHandle geoHandle;

	void setup();

	uint16_t getMeshIndex(uint32_t region, uint32_t permutation);
	uint16_t getMeshCount(uint32_t region, uint32_t permutation);

	mat_Handle* getMaterial(uint32_t index);
};
