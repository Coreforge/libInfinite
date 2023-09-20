#pragma once

#include <stdint.h>
#include <string>

class materialParameterBase{
public:
	// basically just the parameter type enum like it's generated, with the invalid option added
	enum parameterType{
		TYPE_BITMAP,
		TYPE_REAL,
		TYPE_INT,
		TYPE_BOOL,
		TYPE_COLOR,
		TYPE_SCALAR_GPU,
		TYPE_COLOR_GPU,
		TYPE_STRING,
		TYPE_PRESET,
		TYPE_INVALID
	} parameterType;
	uint32_t nameId;
	int typeInt = -1;

	materialParameterBase(int type = TYPE_INVALID);
	virtual std::string toString();
	virtual std::string getTypeString();
	virtual ~materialParameterBase() = default;
};
