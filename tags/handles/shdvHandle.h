#pragma once

#include "../Tag.h"
#include "baseClasses/materialParameterBase.h"
#include "materialParameters/bitmapParameter.h"
#include "materialParameters/realParameter.h"

#include <memory>
#include <stdint.h>


class shdvHandle : public Tag{
public:

	void setup();
	uint32_t getParameterCount();
	std::shared_ptr<materialParameterBase> getParameter(uint32_t index);
};
