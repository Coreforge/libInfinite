#pragma once

#define LOG_LEVEL_DEBUG 0
#define LOG_LEVEL_INFO 1
#define LOG_LEVEL_WARNING 2
#define LOG_LEVEL_ERROR 3
#define LOG_LEVEL_CRITICAL 4

class Logger{
public:
	//virtual Logger() = 0;
	//virtual ~Logger() = 0;
	virtual void log(int level, const char* fmt, ...) = 0;
};
