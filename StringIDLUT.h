#pragma once

#include <unordered_map>
#include <string>
#include <stdint.h>

#include "logger/logger.h"

// basically just a std::map, but with some functions for loading as well
class StringIDLUT{
public:
	// either returns the string associated with the hash, or it returns the hash as a hex string if it's not found
	std::string lookupID(uint32_t stringId);
	void setLogger(Logger* logger);
	void loadMap(std::string data);

private:
	Logger* logger;
	std::unordered_map<uint32_t,std::string> hashes;
};
