#pragma once

#include <string>
#include "logger.h"

class ConsoleLogger : public Logger{
public:
	void log(int level, const char* format, ...);

	ConsoleLogger(int minimumLevel = LOG_LEVEL_DEBUG,std::string prefix = "", FILE* file = stdout);

private:
	int minLevel;
	std::string prefix;
	FILE* file;
};
