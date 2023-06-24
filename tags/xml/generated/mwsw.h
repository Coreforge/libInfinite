#pragma once
#pragma pack(push,1)
#include "../infiniteStructs.h"
#include <stdint.h>


/** 
  * This file was auto-generated with xml2h.py. DO NOT EDIT!!
  * Edit the XML files instead and regenerate this file.
  * Changes will not persist otherwise!
  */

// Generated from: hirt/mwsw.xml

// Flag Definitions



// Enum Definitions



// Structs

struct color_variants{
    string_id name;
    realRGBColor gradient_top_color;
    realRGBColor gradient_mid_color;
    realRGBColor gradient_bottom_color;
    string_id notes;
    string_id groupName;
};


// Root Block

struct mwsw{
    struct anon_struct_0{
        uint64_t vtable_space;
        struct internal_struct{
            uint32_t global_tag_ID;
            uint32_t local_tag_handle;
        };
        struct internal_struct internal_struct_ent;
    };
    struct anon_struct_0 anon_struct_0_ent;
    // CUSTOM: Base
    struct vector2D colorAndRoughnessTextureTransform;
    struct vector2D normalTextureTransform;
    struct tagReference color_gradient_map;
    float roughness_white;
    float roughness_black;
    struct tagReference normal_detail_map;
    float metallic;
    float ior;
    float albedo_tint_spec;
    float sss_strength;
    // CUSTOM: 
    // CUSTOM: Scratches
    realRGBColor scratch_color;
    float scratch_brightness;
    float scratch_roughness;
    float scratch_metallic;
    float scratch_ior;
    float scratch_albedo_tint_spec;
    // CUSTOM: 
    // CUSTOM: Subsurface
    float sss_intensity;
    // CUSTOM: 
    struct tagBlock<color_variants> color_variants_ent;
};


#ifdef MWSW_STRUCTURE_IMPL
// Tag Structure (used by the loader)

uint8_t mwsw_structure[] {0x38,0x7,0x38,0x6,0x34,0x34,0x34,0x34,0x3B,0x3B,0x37,0x18,0x18,0x41,0x14,0x14,0x41,0x14,0x14,0x14,0x14,0x37,0x37,0x1F,0x14,0x14,0x14,0x14,0x14,0x37,0x37,0x14,0x37,0x40,0x2,0x1F,0x1F,0x1F,0x2,0x2,0x3B,0x3B};


#else
extern uint8_t mwsw_structure[42];
#endif


#pragma pack(pop)

