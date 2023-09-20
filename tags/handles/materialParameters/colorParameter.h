#pragma once
#include "../baseClasses/materialParameterBase.h"

#include <string>
#include <stdint.h>

class colorParameter : public materialParameterBase{
public:


	float r, g, b, a;

	colorParameter(float r, float g, float b, float a);
	std::string toString() override;
	std::string getTypeString() override;
};
