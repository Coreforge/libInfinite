#include "boolParameter.h"

#include <sstream>
#include <iomanip>

boolParameter::boolParameter(bool value){
	parameterType = parameterType::TYPE_BOOL;
	this->value = value;

}

std::string boolParameter::toString(){
	return value ? "True" : "False";
}

std::string boolParameter::getTypeString(){
	return std::string("Bool");
}
