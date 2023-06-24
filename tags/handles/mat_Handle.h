#pragma once
#include "../Tag.h"
#include "baseClasses/materialParameterBase.h"
#include "materialParameters/bitmapParameter.h"
#include "materialParameters/realParameter.h"

#include <stdint.h>
#include <memory>

class mat_Handle : public Tag{
public:
	uint32_t getParameterCount();
	std::shared_ptr<materialParameterBase> getParameter(uint32_t index);
	uint32_t getShaderGlobalId();
};
