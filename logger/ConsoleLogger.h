#pragma once


#include "logger.h"

class ConsoleLogger : public Logger{
public:
	void log(int level, const char* format, ...);

	ConsoleLogger();
};
