#include "materialParameterBase.h"

materialParameterBase::materialParameterBase(){
	nameId = 0;
	parameterType = parameterType::TYPE_INVALID;
}

std::string materialParameterBase::toString(){
	return std::string("Invalid Parameter type");
}

std::string materialParameterBase::getTypeString(){
	return std::to_string(typeInt);
}
