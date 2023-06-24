#pragma once

/*
 * These will hopefully get auto-generated at some point too, since there shouldn't be any reason it couldn't be done
 * The only purpose of these classes is to allow struct names to be the same in two tag types without conflicts
 * Adding the tag class as a prefix to all struct names would work too, but that's kinda ugly
 * If this ends up being even more ugly, that's not that hard to do though
 */

#include "../TagManager.h"


int loadMAT_Tag(Item* item, void* &dest, bool loadChildren, TagManager* manager, Tag* tag);
