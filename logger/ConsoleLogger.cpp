#include "ConsoleLogger.h"

#include <cstdio>
#include <cstdarg>

#define DEMO_OUTPUT_IN_CONSTRUCTOR

void ConsoleLogger::log(int level, const char* format, ...){
	// first set the color
	if(level < minLevel){
		// too low log level
		return;
	}

	switch(level){
	case LOG_LEVEL_DEBUG:
		fprintf(file,"\x1b[0m\x1b[2;37m");	// faint, gray
		break;
	case LOG_LEVEL_INFO:
		fprintf(file,"\x1b[0m");	// just regular text
		break;
	case LOG_LEVEL_WARNING:
		fprintf(file,"\x1b[0m\x1b[33m");	// yellow
		break;
	case LOG_LEVEL_ERROR:
		fprintf(file,"\x1b[0m\x1b[31m");	// red
		break;
	case LOG_LEVEL_CRITICAL:
		fprintf(file,"\x1b[0m\x1b[31;1m");	// red, bold
		break;
	}

	fprintf(file,prefix.c_str());
	// print out the message, formatting has been taking care of
	va_list args;
	va_start(args,format);
	vfprintf(file,format,args);
	va_end(args);

	// reset to not mess up other output
	fprintf(file,"\x1b[0m");
}

ConsoleLogger::ConsoleLogger(int minimumLevel, std::string prefix, FILE* file){

	minLevel = minimumLevel;
	this->prefix = prefix;
	this->file = file;

	// just output something at every log level once
#ifdef DEMO_OUTPUT_IN_CONSTRUCTOR
	log(LOG_LEVEL_DEBUG,"Debug\n");
	log(LOG_LEVEL_INFO,"Info\n");
	log(LOG_LEVEL_WARNING,"Warning\n");
	log(LOG_LEVEL_ERROR,"Error\n");
	log(LOG_LEVEL_CRITICAL,"Critical\n");
#endif

}
