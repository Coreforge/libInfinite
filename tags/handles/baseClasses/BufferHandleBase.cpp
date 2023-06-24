#include "BufferHandleBase.h"
#include <cassert>

BufferHandleBase::BufferHandleBase(void* data, int size, int stride,  void* userptr, std::atomic_uint8_t* indicator){
	this->indicator = indicator;
	status = BUFFER_DELETED;
}
