#include "materialParameterBase.h"

#include <sstream>

materialParameterBase::materialParameterBase(int type){
	nameId = 0;
	parameterType = TYPE_INVALID;
	typeInt = type;
}

std::string materialParameterBase::toString(){
	std::stringstream sstream;
	sstream << "Invalid Parameter type (" << typeInt << ")";
	return sstream.str();
}

std::string materialParameterBase::getTypeString(){
	return std::to_string(typeInt);
}
