#pragma once
#include "../Tag.h"
#include "baseClasses/materialParameterBase.h"
#include "materialParameters/bitmapParameter.h"
#include "materialParameters/realParameter.h"
#include "materialParameters/intParameter.h"
#include "materialParameters/boolParameter.h"
#include "materialParameters/colorParameter.h"
#include "materialParameters/presetParameter.h"
#include "materialParameters/stringParameter.h"
#include "shdvHandle.h"
#include "../xml/infiniteStructs.h"

#include <stdint.h>
#include <memory>

#include <unordered_map>

class mat_Handle : public Tag{
public:
	uint32_t getParameterCount();
	std::shared_ptr<materialParameterBase> getParameter(uint32_t index);
	uint32_t getShaderGlobalId();
	shdvHandle* getShader();
	uint32_t getStyleInfoCount();


	struct StyleInfo{
		string_id region_name;
		string_id base_intention;
		string_id mask_0_red_channel_intention;
		string_id mask_0_green_channel_intention;
		string_id mask_0_blue_channel_intention;
		string_id mask_1_red_channel_intention;
		string_id mask_1_green_channel_intention;
		string_id mask_1_blue_channel_intention;
		uint32_t styleGlobalId;
		int numSupportedLayers;
	};

	StyleInfo getStyleInfo(uint32_t index);

	std::unordered_map<string_id,std::shared_ptr<materialParameterBase>> getParameters();

};
