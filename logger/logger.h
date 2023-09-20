#pragma once

// starting with 0 could interfere with terminating null characters
#define LOG_LEVEL_DEBUG 1
#define LOG_LEVEL_INFO 2
#define LOG_LEVEL_WARNING 3
#define LOG_LEVEL_ERROR 4
#define LOG_LEVEL_CRITICAL 5

#define checkedlog(logger, level, ...) if(logger != nullptr) logger->log(level,  __VA_ARGS__);

class Logger{
public:
	//virtual Logger() = 0;
	//virtual ~Logger() = 0;
	virtual void log(int level, const char* fmt, ...) = 0;
};
