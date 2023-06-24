#pragma once
#include "../baseClasses/materialParameterBase.h"

#include <string>
#include <stdint.h>

class realParameter : public materialParameterBase{
public:


	float value;

	realParameter(float value);
	std::string toString() override;
	std::string getTypeString() override;
};
