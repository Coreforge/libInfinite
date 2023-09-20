#pragma once
#include "../baseClasses/materialParameterBase.h"

#include <string>
#include <stdint.h>

class intParameter : public materialParameterBase{
public:


	uint32_t value;

	intParameter(uint32_t value);
	std::string toString() override;
	std::string getTypeString() override;
};
