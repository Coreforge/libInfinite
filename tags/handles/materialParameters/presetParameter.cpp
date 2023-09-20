#include "presetParameter.h"

#include <sstream>
#include <iomanip>

presetParameter::presetParameter(uint32_t globalId){
	parameterType = parameterType::TYPE_PRESET;
	tagClass = 0;
	this->globalId = globalId;
}

std::string presetParameter::toString(){
	std::stringstream stream;
	stream << "Global ID: " << std::hex << std::setw(8) << std::setfill('0') << globalId;
	return stream.str();
}

std::string presetParameter::getTypeString(){
	return std::string("Preset");
}
