#pragma once


extern "C" size_t OodleLZ_Decompress(unsigned char* data, size_t compressedSize, unsigned char* output, size_t decompressedSize, int a, int b, int c, void* d, void* e, void* f, void* g, void* h, void* i, int j);

void decompress(void* data, size_t compressedSize, void* output, size_t decompressedSize ){
	OodleLZ_Decompress((unsigned char*)data, compressedSize, (unsigned char*)output, decompressedSize, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, 0);
};
