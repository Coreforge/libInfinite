#pragma once

#define STRUCTDEFS_TYPE_STRUCT_END 0x3b
#define STRUCTDEFS_TYPE_TAGBLOCK 0x40
#define STRUCTDEFS_TYPE_EXTERNAL_RESOURCE 0x43
#define STRUCTDEFS_TYPE_TAG_REFERENCE 0x41
#define STRUCTDEFS_TYPE_STRUCT 0x38

// size of each entry by type
// some have a size of 0, these just mark things
// since padding can have various sizes, but the same type, it's always assumed to have a size of 1 byte
int sizes[] = {
		32, 	// 0
		256, 	// 1
		4, 		// 2
		4, 		// 3
		1, 		// 4
		2, 		// 5
		4,		// 6
		8, 		// 7
		4, 		// 8
		4, 		// 9
		1, 		// A
		2, 		// B
		4, 		// C
		4, 		// D
		2, 		// E
		1, 		// F
		4, 		// 10
		4, 		// 11
		4,		// 12
		4,		// 13
		4,		// 14
		4,		// 15
		8,		// 16
		12,		// 17
		8,		// 18
		12,		// 19
		16,		// 1A
		8,		// 1B
		12,		// 1C
		12,		// 1D
		16,		// 1E
		12,		// 1F
		16,		// 20
		4,		// 21
		4,		// 22
		4,		// 23
		8,		// 24
		8,		// 25
		8,		// 26
		4,		// 27
		4,		// 28
		4,		// 29
		4,		// 2A
		4,		// 2B
		1,		// 2C
		1,		// 2D
		2,		// 2E
		2,		// 2F
		4,		// 30
		4,		// 31
		4,		// 32
		4,		// 33
		1,		// 34 This doesn't match other implementations, but it's needed for this one (the python script handles the conversion)
		4,		// 35
		0,		// 36
		0,		// 37
		0,		// 38
		32,		// 39
		4,		// 3A
		0,		// 3B
		1,		// 3C
		2,		// 3D
		4,		// 3E
		8,		// 3F
		20,		// 40
		28,		// 41
		24,		// 42
		16,		// 43
		4,		// 44
		4		// 45
};
