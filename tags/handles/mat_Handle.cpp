#include "mat_Handle.h"
#include "../xml/generated/mat.h"
#include "tags/TagManager.h"

#include <cassert>


uint32_t mat_Handle::getParameterCount(){
	mat_* str = (mat_*)root;
	return str->material_parameters_ent.count;
}

shdvHandle* mat_Handle::getShader(){
	mat_* str = (mat_*)root;
	Tag* tmptag = this->item->tagManager->getTag(str->material_shader.globalId);
	shdvHandle* tag = dynamic_cast<shdvHandle*>(tmptag);
	return tag;
}

std::unordered_map<string_id,std::shared_ptr<materialParameterBase>> mat_Handle::getParameters(){
	mat_* str = (mat_*)root;
	std::unordered_map<string_id,std::shared_ptr<materialParameterBase>> mergedParams;

	// first add the params from the shader, then apply any specified by the material

	auto shader = getShader();
	for(int i = 0; i < shader->getParameterCount(); i++){
		auto param = shader->getParameter(i);
		if(param->typeInt == materialParameterBase::TYPE_BITMAP){
			// fix up the bitmap global ID
			auto bitmparam = std::dynamic_pointer_cast<bitmapParameter>(param);
			if(bitmparam.get() != nullptr && str->postprocess_definition_ent.count != 0){
				if(bitmparam->registerOffset < str->postprocess_definition_ent.block[0].textures_ent.count){
					bitmparam->globalId = str->postprocess_definition_ent.block[0].textures_ent.block[bitmparam->registerOffset].bitmap_reference.globalId;
				}
			}
		}
		mergedParams[param->nameId] = param;
	}

	// go through the material's parameters
	for(int i = 0; i < getParameterCount(); i++){
		auto param = getParameter(i);
		mergedParams[param->nameId] = param;	// this will overwrite any parameters already specified by the shader
	}

	return mergedParams;
}

std::shared_ptr<materialParameterBase> mat_Handle::getParameter(uint32_t index){
	mat_* str = (mat_*)root;
	assert(index < str->material_parameters_ent.count && "Parameter index out of bounds!");

	material_parameters* paramStr = &str->material_parameters_ent.block[index];

	std::shared_ptr<materialParameterBase> param;
	switch(paramStr->enum_parameter_type){
	case PARAMETER_TYPE_BITMAP:
	{
		std::shared_ptr<bitmapParameter> btmParam = std::make_shared<bitmapParameter>(paramStr->bitmap.globalId, paramStr->register_offset);
		param = btmParam;
	}
		break;
	case PARAMETER_TYPE_REAL:
	{
		std::shared_ptr<realParameter> realParam = std::make_shared<realParameter>(paramStr->real);
		param = realParam;
	}
		break;
	case PARAMETER_TYPE_INT:
	{
		std::shared_ptr<intParameter> intParam = std::make_shared<intParameter>(paramStr->int_bool);
		param = intParam;
	}
		break;
	case PARAMETER_TYPE_BOOL:
	{
		std::shared_ptr<boolParameter> boolParam = std::make_shared<boolParameter>(paramStr->int_bool);
		param = boolParam;
	}
		break;
	case PARAMETER_TYPE_STRING:
	{
		int count = paramStr->string.size;
		if(count != 0) count -= 1;	// otherwise, null terminator gets included
		std::shared_ptr<stringParameter> stringParam = std::make_shared<stringParameter>(std::string((const char*)paramStr->string.data, count));
		param = stringParam;
	}
		break;
	case PARAMETER_TYPE_PRESET:
	{
		std::shared_ptr<presetParameter> presetParam = std::make_shared<presetParameter>(paramStr->bitmap.globalId);
		param = presetParam;
	}
		break;
	case PARAMETER_TYPE_COLOR:
	{
		std::shared_ptr<colorParameter> colorParam = std::make_shared<colorParameter>(paramStr->color.r, paramStr->color.g, paramStr->color.b, paramStr->color.a);
		param = colorParam;
	}
		break;
	default:
		param = std::make_shared<materialParameterBase>(paramStr->enum_parameter_type);
		break;
	}
	param->nameId = paramStr->parameter_name;
	param->typeInt = paramStr->enum_parameter_type;
	return param;
}

uint32_t mat_Handle::getStyleInfoCount(){
	mat_* str = (mat_*)root;
	return str->style_info_ent.count;
}

mat_Handle::StyleInfo mat_Handle::getStyleInfo(uint32_t index){
	mat_* str = (mat_*)root;
	assert(index < str->style_info_ent.count && "Style info index out of bounds!");
	StyleInfo info;
	style_info* si = &str->style_info_ent.block[index];
	info.region_name = si->region_name;
	info.base_intention = si->base_intention;
	info.mask_0_red_channel_intention = si->mask_0_red_channel_intention;
	info.mask_0_green_channel_intention = si->mask_0_green_channel_intention;
	info.mask_0_blue_channel_intention = si->mask_0_blue_channel_intention;
	info.mask_1_red_channel_intention = si->mask_1_red_channel_intention;
	info.mask_1_green_channel_intention = si->mask_1_green_channel_intention;
	info.mask_1_blue_channel_intention = si->mask_1_blue_channel_intention;
	info.styleGlobalId = si->material_style.globalId;
	switch(si->enum_Number_of_Supported_Layers_For_Material_Shader){
	case NUMBER_OF_SUPPORTED_LAYERS_FOR_MATERIAL_SHADER_SUPPORTS1LAYER:
		info.numSupportedLayers = 1;
		break;
	case NUMBER_OF_SUPPORTED_LAYERS_FOR_MATERIAL_SHADER_SUPPORTS4LAYERS:
		info.numSupportedLayers = 4;
		break;
	case NUMBER_OF_SUPPORTED_LAYERS_FOR_MATERIAL_SHADER_SUPPORTS7LAYERS:
		info.numSupportedLayers = 7;
		break;
	case NUMBER_OF_SUPPORTED_LAYERS_FOR_MATERIAL_SHADER_SUPPORTS0LAYERS:
		info.numSupportedLayers = 0;
		break;
	default:
		info.numSupportedLayers = -1;
	}

	return info;
}

uint32_t mat_Handle::getShaderGlobalId(){
	mat_* str = (mat_*)root;
	return str->material_shader.globalId;
}
