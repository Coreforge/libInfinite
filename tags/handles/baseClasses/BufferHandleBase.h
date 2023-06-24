#pragma once

#include <atomic>



class BufferHandleBase{
public:

	// The last one might not be used, idk yet, but that should probably be stored outside of this class
	enum {
		BUFFER_IN_USE,		// normal status, also used if a buffer gets reused after being marked for deletion
		BUFFER_MARKED_FOR_DELETION,		// buffer was submitted to the GC, but can still be reused
		BUFFER_DELETED		// The GC is processing this buffer now, too late
	} status;

	// indicator is used to indicate whether or not this object is still usable.
	// The constructor should set it to 1, and the GC to 0 in the check if it should actually delete the buffer
	BufferHandleBase(void* data, int size, int stride, void* userptr, std::atomic_uint8_t* indicator);

	std::atomic_uint8_t* indicator;

};
