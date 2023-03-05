#pragma once

#include <string>
#include <stdint.h>

#include "ContentTableEntry.h"

std::string pythonByteLiteral(uint8_t byte);

// only pass the characters, like "totallyrealdata!", not like "b'totallyrealdata!'"
bool checkEntryType(ContentTableEntry* entry, std::string pythonLiteralType);
