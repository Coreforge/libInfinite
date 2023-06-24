#include "StringIDLUT.h"

#include <sstream>
#include <iomanip>
#include <algorithm>
#include <bit>

void StringIDLUT::setLogger(Logger* logger){
	this->logger = logger;
}


// because Gamergotten's dumper dumps the bytse as big-endian, they're read in that way here
void StringIDLUT::loadMap(std::string data){
	std::string line;
	data.erase(std::remove(data.begin(), data.end(), '\r'),data.end());
	std::stringstream stream(data);
	while(std::getline(stream, line)){
		auto br1 = line.begin();
		std::advance(br1, 8);
		std::string hexHash(line.begin(),br1);
		std::advance(br1, 1);
		std::string raw(br1,line.end());
		uint32_t hash;
		hash = std::stoul(hexHash, nullptr, 16);
		hash = __builtin_bswap32(hash);
		hashes.insert({hash,raw});
	}
	if(logger != nullptr){
		logger->log(LOG_LEVEL_INFO, "Loaded %d hashes\n",hashes.size());
	}
}

std::string StringIDLUT::lookupID(uint32_t stringId){
	if(hashes.count(stringId) != 0){
		return hashes[stringId];
	}
	std::stringstream s;
	s << std::hex << std::showbase << std::setw(8) << std::setfill('0') << stringId;
	return s.str();
}
