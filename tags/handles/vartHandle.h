#pragma once
#include "../Tag.h"

#include <stdint.h>
#include <vector>

class vartHandle : public Tag{
public:
	void setup() override;
	float getAspectRatio();
	uint32_t getDrawInfoCount();

	struct vertex{
		float x,y;
		uint32_t region;
		uint32_t render_type;
	};

	struct drawInfo{
		uint16_t indexCount;
		uint16_t indexStart;
		uint16_t vertexStart;
	};

	drawInfo getDrawInfo(uint32_t index);

	std::vector<vertex> getVertices();
	std::vector<uint16_t> getIndicies();
};
