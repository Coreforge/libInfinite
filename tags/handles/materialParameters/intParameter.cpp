#include "intParameter.h"

#include <sstream>
#include <iomanip>

intParameter::intParameter(uint32_t value){
	parameterType = parameterType::TYPE_INT;
	this->value = value;

}

std::string intParameter::toString(){
	return std::to_string(value);
}

std::string intParameter::getTypeString(){
	return std::string("Int");
}
