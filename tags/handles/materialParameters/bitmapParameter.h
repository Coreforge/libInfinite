#pragma once
#include "../baseClasses/materialParameterBase.h"

#include <string>
#include <stdint.h>

class bitmapParameter : public materialParameterBase{
public:


	uint32_t globalId;
	uint32_t tagClass;
	uint32_t registerOffset;

	bitmapParameter(uint32_t globalId, uint32_t registerOffset = 0);
	std::string toString() override;
	std::string getTypeString() override;
};
