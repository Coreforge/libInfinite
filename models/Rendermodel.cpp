#include "Rendermodel.h"

#include "../tags/Tag.h"

int Buffer::ensureBuffer(){
	if(status == BufferStatus::MDL_BUFFER_UNAVAILABLE){
		// cannot be loaded
		return -1;
	}
	if(status == BufferStatus::MDL_BUFFER_VALID){
		// already loaded
		return 0;
	}
	data = tag->getResource(offset, size);
	if(data == nullptr){
		// failed to load
		return -1;
	}
	return 0;
}
