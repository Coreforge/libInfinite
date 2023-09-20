#include "stringParameter.h"

#include <sstream>
#include <iomanip>

stringParameter::stringParameter(std::string value){
	parameterType = parameterType::TYPE_STRING;
	this->value = value;

}

std::string stringParameter::toString(){
	return value;
}

std::string stringParameter::getTypeString(){
	return std::string("String");
}
