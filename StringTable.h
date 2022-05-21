#include <stdint.h>
#include <vector>
#include <string>

class StringTable{
	std::vector<std::string> strings;
	uint64_t offset;
	uint64_t length;
};
