#include "pmdfHandle.h"

#include <tags/xml/generated/pmdf.h>

void pmdfHandle::setup(){
	pmdf* str = (pmdf*)root;
	geoHandle.struct_ptr = &str->render_geometry_ent;
	geoHandle.tag = this;
}
