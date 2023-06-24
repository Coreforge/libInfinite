#pragma once

#include "Rendermodel.h"
#include "../StringIDLUT.h"

#include <string>

#include "../tags/Tag.h"

struct mode;

class V53ModelLoader{
public:
	void loadModel(RenderModel &model, Tag* tag, StringIDLUT* lut);
private:
	std::string toHex(uint32_t i);
	uint16_t convertDataType(uint16_t type);
};
