#include "rtgoHandle.h"

#include <tags/xml/generated/rtgo.h>

void rtgoHandle::setup(){
	rtgo* str = (rtgo*)root;
	geoHandle.struct_ptr = &str->render_geometry_ent;
	geoHandle.tag = this;
}
