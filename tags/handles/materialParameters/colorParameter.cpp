#include "colorParameter.h"

#include <sstream>
#include <iomanip>

colorParameter::colorParameter(float r, float g, float b, float a){
	parameterType = parameterType::TYPE_COLOR;
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;

}

std::string colorParameter::toString(){
	std::stringstream stream;
	stream << "R: " << r << " G: " << g << " B: " << b << " A: " << a;
	return stream.str();
}

std::string colorParameter::getTypeString(){
	return std::string("Color");
}
