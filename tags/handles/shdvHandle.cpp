#include "shdvHandle.h"

#include <tags/xml/generated/shdv.h>
#include "baseClasses/materialParameterBase.h"
#include "materialParameters/bitmapParameter.h"
#include "materialParameters/realParameter.h"
#include "materialParameters/intParameter.h"
#include "materialParameters/boolParameter.h"
#include "materialParameters/colorParameter.h"
#include "materialParameters/stringParameter.h"
#include "materialParameters/presetParameter.h"

#include <cassert>

void shdvHandle::setup(){
	shdv* str = (shdv*)root;

}

uint32_t shdvHandle::getParameterCount(){
	shdv* str = (shdv*)root;
	return str->material_parameters_ent.count;
}

std::shared_ptr<materialParameterBase> shdvHandle::getParameter(uint32_t index){
	shdv* str = (shdv*)root;
	assert(index < str->material_parameters_ent.count && "Parameter index out of bounds!");

	material_parameters* paramStr = &str->material_parameters_ent.block[index];

	std::shared_ptr<materialParameterBase> param;
	switch(paramStr->enum_parameter_type){
	case PARAMETER_TYPE_BITMAP:
	{
		// register offset == sampler index (which mostly also equals the index in the array) in the materials post-processing textures
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
