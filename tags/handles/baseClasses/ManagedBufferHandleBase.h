#pragma once
#include "BufferHandleBase.h"

#include <memory>

template <class t>
class ManagedBufferHandleBase{
public:
	ManagedBufferHandleBase(t* actualHandle, void* userData){
		handle = actualHandle;
	}
	t* handle;


};
