#include "realParameter.h"

#include <sstream>
#include <iomanip>

realParameter::realParameter(float value){
	parameterType = parameterType::TYPE_REAL;
	this->value = value;

}

std::string realParameter::toString(){
	return std::to_string(value);
}

std::string realParameter::getTypeString(){
	return std::string("Real");
}
