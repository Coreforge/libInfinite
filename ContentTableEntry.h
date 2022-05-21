#include <stdint.h>
#include "DataTableEntry.h"

typedef struct typeHash{uint64_t hash[2];} BlockTypeHash;

class ContentTableEntry{
	uint64_t offset;
	BlockTypeHash hash;
	DataTableEntry* ref;
	DataTableEntry* parent;
};
