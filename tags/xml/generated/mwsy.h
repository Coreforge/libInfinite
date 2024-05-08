#pragma once
#pragma pack(push,1)
#include "../infiniteStructs.h"
#include <stdint.h>


/** 
  * This file was auto-generated with xml2h.py. DO NOT EDIT!!
  * Edit the XML files instead and regenerate this file.
  * Changes will not persist otherwise!
  */

// Generated from: hirt3/mwsy.xml

// Flag Definitions

// Field Preload_Swatch_Options

#define PRELOAD_SWATCH_OPTIONS_PRELOAD_ALL_SWATCHES (1<<0)
#define PRELOAD_SWATCH_OPTIONS_DONT_PRELOAD_SWATCHES (1<<1)




// Enum Definitions

// Enum Hero_Reveal

enum Hero_Reveal_enum {
    HERO_REVEAL_DISABLED,
    HERO_REVEAL_ENABLED
};

// Enum Color_Blend

enum Color_Blend_enum {
    COLOR_BLEND_DISABLED,
    COLOR_BLEND_ENABLED
};

// Enum Normal_Blend

enum Normal_Blend_enum {
    NORMAL_BLEND_DISABLED,
    NORMAL_BLEND_ENABLED
};

// Enum Ignore_Texel_Density_Scalar

enum Ignore_Texel_Density_Scalar_enum {
    IGNORE_TEXEL_DENSITY_SCALAR_DISABLED,
    IGNORE_TEXEL_DENSITY_SCALAR_ENABLED
};

// Enum forge_override_metallic

enum forge_override_metallic_enum {
    FORGE_OVERRIDE_METALLIC_DISABLED,
    FORGE_OVERRIDE_METALLIC_ENABLED
};

// Enum forge_metallic

enum forge_metallic_enum {
    FORGE_METALLIC_DISABLED,
    FORGE_METALLIC_ENABLED
};



// Structs

struct intentionConversionList{
    string_id intentionName;
};


struct regions{
    string_id name;
    struct tagBlock<intentionConversionList> intentionConversionList_ent;
};


struct coatingMaterialSets{
    uint64_t elementID;
    struct tagReference coatingMaterialSet;
    uint32_t generated_pad2ed3;
};


struct layers{
    uint64_t elementID;
    string_id name;
    uint8_t enum_Hero_Reveal;
    uint8_t enum_Color_Blend;
    uint8_t enum_Normal_Blend;
    uint8_t enum_Ignore_Texel_Density_Scalar;
    realRGBColor forge_color_top;
    realRGBColor forge_color_mid;
    realRGBColor forge_color_bottom;
    float forge_color_intensity;
    float forge_layer_opacity;
    float forge_max_roughness;
    uint8_t enum_forge_override_metallic;
    uint8_t enum_forge_metallic;
    uint32_t generated_pad910e;
    uint16_t generated_pad910e_2;
};




struct style{
    string_id name;
    struct tagReference palette;
    string_id global_damage;
    string_id hero_damage;
    string_id global_emissive;
    float emissive_amount;
    float scratch_amount;
    string_id grime_type;
    float grime_amount;
    struct tagBlock<regions> regions_ent;
    uint32_t regions_Flags;
    uint32_t regions_Vector1;
    uint32_t regions_Vector2;
};


struct Preloaded_Swatches{
    uint64_t elementID;
    struct tagReference swatch;
    uint32_t generated_pad863f;
};


// Root Block

struct mwsy{
    struct AnyTag{
        uint64_t vtable_space;
        struct internal_struct{
            uint32_t global_tag_ID;
            uint32_t local_tag_handle;
        };
        struct internal_struct internal_struct_ent;
    };
    struct AnyTag AnyTag_ent;
    struct tagBlock<regions> regions_ent;
    uint32_t regions_Flags;
    uint32_t regions_Vector1;
    uint32_t regions_Vector2;
    struct tagBlock<coatingMaterialSets> coatingMaterialSets_ent;
    uint32_t coatingMaterialSets_Flags;
    uint32_t coatingMaterialSets_Vector1;
    uint32_t coatingMaterialSets_Vector2;
    struct tagBlock<style> style_ent;
    uint32_t style_Flags;
    uint32_t style_Vector1;
    uint32_t style_Vector2;
    shortBlockIndex defaultLookIndex;
    uint16_t generated_pad7113;
    struct tagReference visorSwatch;
    uint8_t flags_Preload_Swatch_Options;
    uint8_t generated_pad245e;
    uint16_t generated_pad245e_2;
    struct tagBlock<Preloaded_Swatches> Preloaded_Swatches_ent;
    uint32_t Material_Style_Hash;
    uint32_t generated_padd7a9;
};


#ifdef MWSY_STRUCTURE_IMPL
// Tag Structure (used by the loader)

uint8_t mwsy_structure[] {0x38,0x7,0x38,0x6,0x34,0x34,0x34,0x34,0x3B,0x3B,0x40,0x2,0x40,0x2,0x3B,0x3B,0x6,0x6,0x6,0x40,0x3F,0x41,0x34,0x34,0x34,0x34,0x3B,0x6,0x6,0x6,0x40,0x2,0x41,0x2,0x2,0x2,0x14,0x14,0x2,0x14,0x40,0x2,0x2E,0x34,0x34,0x40,0x3F,0x2,0xA,0xA,0xA,0xA,0x1F,0x1F,0x1F,0x14,0x14,0x14,0xA,0xA,0x34,0x34,0x34,0x34,0x34,0x34,0x3B,0x6,0x6,0x6,0x3B,0x6,0x6,0x6,0x3B,0x6,0x6,0x6,0x2E,0x34,0x34,0x41,0xF,0x34,0x34,0x34,0x40,0x3F,0x41,0x34,0x34,0x34,0x34,0x3B,0x3E,0x34,0x34,0x34,0x34,0x3B};


#else
extern uint8_t mwsy_structure[100];
#endif


#pragma pack(pop)

