#pragma once

#include <jsoncpp/json/json.h>

#include <vector>
#include <unordered_set>

#include "tags/handles/mat_Handle.h"
#include "StringIDLUT.h"

class MaterialJsonExtractor{
public:
	MaterialJsonExtractor(StringIDLUT& lut);
	MaterialJsonExtractor() = default;

	Json::Value toJson(mat_Handle* mat);
	Json::Value toJson(std::vector<mat_Handle*> mats);

	std::unordered_set<uint32_t> getBitmaps(mat_Handle* mat);
	std::unordered_set<uint32_t> getBitmaps(std::vector<mat_Handle*> mats);

private:
	StringIDLUT idLUT;
};
