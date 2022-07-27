#include "ConsoleLogger.h"

#include <cstdio>
#include <cstdarg>

#define DEMO_OUTPUT_IN_CONSTRUCTOR

void ConsoleLogger::log(int level, const char* format, ...){
	// first set the color
	switch(level){
	case LOG_LEVEL_DEBUG:
		printf("\x1b[0m\x1b[2;37m");	// faint, gray
		break;
	case LOG_LEVEL_INFO:
		printf("\x1b[0m");	// just regular text
		break;
	case LOG_LEVEL_WARNING:
		printf("\x1b[0m\x1b[33m");	// yellow
		break;
	case LOG_LEVEL_ERROR:
		printf("\x1b[0m\x1b[31m");	// red
		break;
	case LOG_LEVEL_CRITICAL:
		printf("\x1b[0m\x1b[31;1m");	// red, bold
		break;
	}

	// print out the message, formatting has been taking care of
	va_list args;
	va_start(args,format);
	vprintf(format,args);
	va_end(args);

	// reset to not mess up other output
	printf("\x1b[0m");
}

ConsoleLogger::ConsoleLogger(){
	// just output something at every log level once
#ifdef DEMO_OUTPUT_IN_CONSTRUCTOR
	log(LOG_LEVEL_DEBUG,"Debug\n");
	log(LOG_LEVEL_INFO,"Info\n");
	log(LOG_LEVEL_WARNING,"Warning\n");
	log(LOG_LEVEL_ERROR,"Error\n");
	log(LOG_LEVEL_CRITICAL,"Critical\n");
#endif

}
