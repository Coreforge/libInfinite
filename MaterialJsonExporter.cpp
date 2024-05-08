#include "MaterialJsonExporter.h"

#include <iomanip>
#include <sstream>
#include <memory>
#include <algorithm>
#include "tags/TagManager.h"

#include "BitmapHandle.h"

MaterialJsonExtractor::MaterialJsonExtractor(StringIDLUT& lut){
	this->idLUT = lut;
}

Json::Value MaterialJsonExtractor::toJson(mat_Handle* mat){
	Json::Value jsonMatNode;

	auto params = mat->getParameters();
	jsonMatNode["Shader"] = mat->getShader()->item->moduleItem->path;
	for(auto& [nameId, parameter] : params){
		std::string paramName = idLUT.lookupID(nameId);
		// used to get the name for bitmaps
		std::stringstream stream;
		/*
		 * Bitmap, Real, Bool, Int, and Color need special treatment, String and Preset are fine with the default toString
		 */
		switch(parameter->typeInt){
		case materialParameterBase::TYPE_BITMAP:
			//usedBitmaps.emplace_back(std::dynamic_pointer_cast<bitmapParameter>(parameter)->globalId);
		{
			int framecnt = 0;
			uint32_t globalId = std::dynamic_pointer_cast<bitmapParameter>(parameter)->globalId;
			if(globalId != 0xffffffff && mat->item->tagManager->man->assetIdItems.contains(globalId)){
				BitmapHandle bhandle(mat->item->tagManager->man->assetIdItems[std::dynamic_pointer_cast<bitmapParameter>(parameter)->globalId],nullptr);
				framecnt = bhandle.frameCount;
			}
			stream << std::hex << std::setw(8) << std::setfill('0') << std::dynamic_pointer_cast<bitmapParameter>(parameter)->globalId;
			Json::Value bitmapNode;
			bitmapNode["name"] = stream.str();
			bitmapNode["frames"] = framecnt;
			jsonMatNode[idLUT.lookupID(nameId)] = bitmapNode;
		}

			break;

		case materialParameterBase::TYPE_REAL:
			jsonMatNode[idLUT.lookupID(nameId)] = std::dynamic_pointer_cast<realParameter>(parameter)->value;
			break;
		case materialParameterBase::TYPE_INT:
			jsonMatNode[idLUT.lookupID(nameId)] = std::dynamic_pointer_cast<intParameter>(parameter)->value;
			break;
		case materialParameterBase::TYPE_BOOL:
			jsonMatNode[idLUT.lookupID(nameId)] = std::dynamic_pointer_cast<boolParameter>(parameter)->value;
			break;
		case materialParameterBase::TYPE_COLOR:
		{
			Json::Value col;
			auto colp = std::dynamic_pointer_cast<colorParameter>(parameter);
			col[0] = colp->r;
			col[1] = colp->g;
			col[2] = colp->b;
			col[3] = colp->a;
			jsonMatNode[idLUT.lookupID(nameId)] = col;
		}
			break;
		default:
			jsonMatNode[idLUT.lookupID(nameId)] = parameter->toString();
			break;
		}
	}
	if(mat->getStyleInfoCount()){
		mat_Handle::StyleInfo si = mat->getStyleInfo(0);
		jsonMatNode["region_name"] = idLUT.lookupID(si.region_name);
		jsonMatNode["base_intention"] = idLUT.lookupID(si.base_intention);
		jsonMatNode["mask_0_red_channel_intention"] = idLUT.lookupID(si.mask_0_red_channel_intention);
		jsonMatNode["mask_0_green_channel_intention"] = idLUT.lookupID(si.mask_0_green_channel_intention);
		jsonMatNode["mask_0_blue_channel_intention"] = idLUT.lookupID(si.mask_0_blue_channel_intention);
		jsonMatNode["mask_1_red_channel_intention"] = idLUT.lookupID(si.mask_1_red_channel_intention);
		jsonMatNode["mask_1_green_channel_intention"] = idLUT.lookupID(si.mask_1_green_channel_intention);
		jsonMatNode["mask_1_blue_channel_intention"] = idLUT.lookupID(si.mask_1_blue_channel_intention);
		jsonMatNode["num_supported_layers"] = si.numSupportedLayers;

	}

	return jsonMatNode;
}

std::unordered_set<uint32_t> MaterialJsonExtractor::getBitmaps(mat_Handle* mat){
	std::unordered_set<uint32_t> bitmaps;

	auto params = mat->getParameters();

	for(auto& [nameId, parameter] : params){
		/*
		 * Bitmap, Real, Bool, Int, and Color need special treatment, String and Preset are fine with the default toString
		 */
		switch(parameter->typeInt){
		case materialParameterBase::TYPE_BITMAP:
			bitmaps.emplace(std::dynamic_pointer_cast<bitmapParameter>(parameter)->globalId);
			break;
		default:
			break;
		}
	}

	return bitmaps;
}

std::unordered_set<uint32_t> MaterialJsonExtractor::getBitmaps(std::vector<mat_Handle*> mats){
	std::unordered_set<uint32_t> bitmaps;

	for(auto handle : mats){
		auto IDs = getBitmaps(handle);
		bitmaps.insert(IDs.begin(), IDs.end());
	}

	return bitmaps;
}

Json::Value MaterialJsonExtractor::toJson(std::vector<mat_Handle*> mats){
	Json::Value root;

	for(auto mat : mats){
		root[mat->item->moduleItem->path] = toJson(mat);
	}

	return root;
}

