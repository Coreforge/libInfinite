#include <stdint.h>
#include "DataTableEntry.h"
#include <vector>

class DataTable{
	uint64_t offset;
public:
	std::vector<DataTableEntry> entries;

	int readTable(uint8_t* data, uint32_t n);
};
