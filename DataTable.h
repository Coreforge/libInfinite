#include <stdint.h>
#include "DataTableEntry.h"
#include <vector>

class DataTable{
	uint64_t offset;
	std::vector<DataTableEntry> entries;
};
