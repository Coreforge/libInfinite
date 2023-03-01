#pragma once

#include <string>
#include <stdint.h>

#include "ContentTableEntry.h"

std::string pythonByteLiteral(uint8_t byte){
	if(byte >= 32 && byte < 127){
		// printable ASCII-character
		if(byte == 39){
			// single quotes, since I'm putting single quotes around the literal, these have to be escaped
			return std::string("\\'");
		}
		// all other characters can just be used regularly
		return std::string(1,byte);
	}
	// all non-printable characters or invalid ASCII values have to be escaped
	char tmp[5];
	snprintf(tmp,5,"\\x%02x",byte);
	return std::string(tmp);
}

// only pass the characters, like "totallyrealdata!", not like "b'totallyrealdata!'"
bool checkEntryType(ContentTableEntry* entry, std::string pythonLiteralType){
	std::string out = "";
	for(int i = 0; i < 2; i++){
		out += pythonByteLiteral((uint8_t)(entry->type.data[i]));	// byte 0
		out += pythonByteLiteral((uint8_t)(entry->type.data[i] >> 8));	// byte 1
		out += pythonByteLiteral((uint8_t)(entry->type.data[i] >> 16));	// byte 2
		out += pythonByteLiteral((uint8_t)(entry->type.data[i] >> 24));	// byte 3
		out += pythonByteLiteral((uint8_t)(entry->type.data[i] >> 32));	// byte 4
		out += pythonByteLiteral((uint8_t)(entry->type.data[i] >> 40));	// byte 5
		out += pythonByteLiteral((uint8_t)(entry->type.data[i] >> 48));	// byte 6
		out += pythonByteLiteral((uint8_t)(entry->type.data[i] >> 56));	// byte 7
	}
	return out == pythonLiteralType;
}
