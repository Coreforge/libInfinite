#pragma once
#include "../baseClasses/materialParameterBase.h"

#include <string>
#include <stdint.h>

class boolParameter : public materialParameterBase{
public:


	bool value;

	boolParameter(bool value);
	std::string toString() override;
	std::string getTypeString() override;
};
