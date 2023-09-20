#include "bitmapParameter.h"

#include <sstream>
#include <iomanip>

bitmapParameter::bitmapParameter(uint32_t globalId, uint32_t registerOffset){
	parameterType = parameterType::TYPE_BITMAP;
	tagClass = 0;
	this->globalId = globalId;
	this->registerOffset = registerOffset;
}

std::string bitmapParameter::toString(){
	std::stringstream stream;
	stream << "Global ID: " << std::hex << std::setw(8) << std::setfill('0') << globalId;
	return stream.str();
}

std::string bitmapParameter::getTypeString(){
	return std::string("Bitmap");
}
