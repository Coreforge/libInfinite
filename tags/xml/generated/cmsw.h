#pragma once
#pragma pack(push,1)
#include "../infiniteStructs.h"
#include <stdint.h>


/** 
  * This file was auto-generated with xml2h.py. DO NOT EDIT!!
  * Edit the XML files instead and regenerate this file.
  * Changes will not persist otherwise!
  */

// Generated from: hirt3/cmsw.xml

// Flag Definitions



// Enum Definitions



// Structs

// Root Block

struct cmsw{
    struct AnyTag{
        uint64_t vtable_space;
        struct internal_struct{
            uint32_t global_tag_ID;
            uint32_t local_tag_handle;
        };
        struct internal_struct internal_struct_ent;
    };
    struct AnyTag AnyTag_ent;
    struct tagReference Parent;
    // CUSTOM: Base
    struct vector2D colorAndRoughnessTextureTransform;
    struct vector2D normalTextureTransform;
    struct tagReference colorGradientMap;
    realRGBColor gradientTopColor;
    realRGBColor gradientMidColor;
    realRGBColor gradientBottomColor;
    float roughnessWhite;
    float roughnessBlack;
    struct tagReference normalDetailMap;
    float metallic;
    float ior;
    float albedoTintSpec;
    // CUSTOM: unnamed_field_2
    // CUSTOM: Scratches
    realRGBColor scratchColor;
    float scratchBrightness;
    float scratchRoughness;
    float scratchMetallic;
    float scratchIOR;
    float scratchAlbedoTintSpec;
    // CUSTOM: unnamed_field_3
    // CUSTOM: Subsurface
    float sssIntensity;
    // CUSTOM: unnamed_field_4
    // CUSTOM: Emissive
    float emissiveIntensity;
    float emissiveAmount;
    // CUSTOM: unnamed_field_5
};


#ifdef CMSW_STRUCTURE_IMPL
// Tag Structure (used by the loader)

uint8_t cmsw_structure[] {0x38,0x7,0x38,0x6,0x34,0x34,0x34,0x34,0x3B,0x3B,0x41,0x37,0x18,0x18,0x41,0x1F,0x1F,0x1F,0x14,0x14,0x41,0x14,0x14,0x14,0x37,0x37,0x1F,0x14,0x14,0x14,0x14,0x14,0x37,0x37,0x14,0x37,0x37,0x14,0x14,0x37,0x3B};


#else
extern uint8_t cmsw_structure[41];
#endif


#pragma pack(pop)

