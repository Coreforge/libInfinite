#pragma once
#pragma pack(push,1)
#include "../infiniteStructs.h"
#include <stdint.h>


/** 
  * This file was auto-generated with xml2h.py. DO NOT EDIT!!
  * Edit the XML files instead and regenerate this file.
  * Changes will not persist otherwise!
  */

// Generated from: hirt/vart.xml

// Flag Definitions



// Enum Definitions



// Structs

struct m_vectorVertices{
    struct point2D position;
    uint32_t region_index;
    struct point3D texcoord;
    uint32_t render_type;
};


struct m_vectorIndices{
    uint16_t index;
};


struct m_drawInformation{
    uint16_t entry_point;
    uint16_t vertex_start;
    uint16_t index_start;
    uint16_t index_count;
};


// Root Block

struct vart{
    struct anon_struct_0{
        uint64_t vtable_space;
        struct internal_struct{
            uint32_t global_tag_ID;
            uint32_t local_tag_handle;
        };
        struct internal_struct internal_struct_ent;
    };
    struct anon_struct_0 anon_struct_0_ent;
    struct tagBlock<m_vectorVertices> m_vectorVertices_ent;
    struct tagBlock<m_vectorIndices> m_vectorIndices_ent;
    struct tagBlock<m_drawInformation> m_drawInformation_ent;
    uint32_t generated_padc0a6;
    uint64_t vertexBuffer;
    uint64_t indexBuffer;
    float aspectRatio;
    uint32_t m_validDrawIndexCount;
    uint32_t m_validDrawInformationCount;
    uint32_t generated_pad0d5b;
};


#ifdef VART_STRUCTURE_IMPL
// Tag Structure (used by the loader)

uint8_t vart_structure[] {0x38,0x7,0x38,0x6,0x34,0x34,0x34,0x34,0x3B,0x3B,0x40,0x16,0x6,0x17,0x6,0x3B,0x40,0x3D,0x3B,0x40,0x3D,0x3D,0x3D,0x3D,0x3B,0x34,0x34,0x34,0x34,0x7,0x7,0x14,0x6,0x6,0x34,0x34,0x34,0x34,0x3B};


#else
extern uint8_t vart_structure[39];
#endif


#pragma pack(pop)

