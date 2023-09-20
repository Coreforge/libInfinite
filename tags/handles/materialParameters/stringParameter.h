#pragma once
#include "../baseClasses/materialParameterBase.h"

#include <string>
#include <stdint.h>

class stringParameter : public materialParameterBase{
public:


	std::string value;

	stringParameter(std::string value);
	std::string toString() override;
	std::string getTypeString() override;
};
