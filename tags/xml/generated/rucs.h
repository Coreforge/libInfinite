#pragma once
#pragma pack(push,1)
#include "../infiniteStructs.h"
#include <stdint.h>


/** 
  * This file was auto-generated with xml2h.py. DO NOT EDIT!!
  * Edit the XML files instead and regenerate this file.
  * Changes will not persist otherwise!
  */

// Generated from: hirt/rucs.xml

// Flag Definitions



// Enum Definitions



// Structs

struct styles{
    string_id name;
    string_id variantName;
    struct tagReference styleRef;
};


// Root Block

struct rucs{
    struct anon_struct_0{
        uint64_t vtable_space;
        struct internal_struct{
            uint32_t global_tag_ID;
            uint32_t local_tag_handle;
        };
        struct internal_struct internal_struct_ent;
    };
    struct anon_struct_0 anon_struct_0_ent;
    struct tagBlock<styles> styles_ent;
    struct tagReference visorSwatch;
};


#ifdef RUCS_STRUCTURE_IMPL
// Tag Structure (used by the loader)

uint8_t rucs_structure[] {0x38,0x7,0x38,0x6,0x34,0x34,0x34,0x34,0x3B,0x3B,0x40,0x2,0x2,0x41,0x3B,0x41,0x3B};


#else
extern uint8_t rucs_structure[17];
#endif


#pragma pack(pop)

