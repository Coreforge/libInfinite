#include "mat_Handle.h"
#include "../xml/generated/mat.h"

#include <cassert>


uint32_t mat_Handle::getParameterCount(){
	mat_* str = (mat_*)root;
	return str->material_parameters_ent.count;
}

std::shared_ptr<materialParameterBase> mat_Handle::getParameter(uint32_t index){
	mat_* str = (mat_*)root;
	assert(index < str->material_parameters_ent.count && "Parameter index out of bounds!");

	material_parameters* paramStr = &str->material_parameters_ent.block[index];

	std::shared_ptr<materialParameterBase> param;
	switch(paramStr->enum_parameter_type){
	case PARAMETER_TYPE_BITMAP:
	{
		std::shared_ptr<bitmapParameter> btmParam = std::make_shared<bitmapParameter>(paramStr->bitmap.globalId);
		param = btmParam;
	}
		break;
	case PARAMETER_TYPE_REAL:
	{
		std::shared_ptr<realParameter> realParam = std::make_shared<realParameter>(paramStr->real);
		param = realParam;
	}
		break;
	default:
		param = std::make_shared<materialParameterBase>();
		break;
	}
	param->nameId = paramStr->parameter_name;
	param->typeInt = paramStr->enum_parameter_type;
	return param;
}

uint32_t mat_Handle::getShaderGlobalId(){
	mat_* str = (mat_*)root;
	return str->material_shader.globalId;
}
