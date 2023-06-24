#pragma once

#include "../Tag.h"
#include "render_geometryHandle.h"

class rtgoHandle : public Tag{
public:
	render_geometryHandle geoHandle;

	void setup();
};
