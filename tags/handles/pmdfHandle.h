#pragma once

#include "../Tag.h"
#include "render_geometryHandle.h"

class pmdfHandle : public Tag{
public:
	render_geometryHandle geoHandle;

	void setup();
};
