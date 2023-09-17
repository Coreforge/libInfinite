#pragma once
#pragma pack(push,1)
#include "../infiniteStructs.h"
#include <stdint.h>


/** 
  * This file was auto-generated with xml2h.py. DO NOT EDIT!!
  * Edit the XML files instead and regenerate this file.
  * Changes will not persist otherwise!
  */

// Generated from: hirt2/shdv.xml

// Flag Definitions

// Field flags

#define FLAGS_IS_DISTORTION (1<<0)
#define FLAGS_IS_DECAL (1<<1)
#define FLAGS_IS_WATER (1<<2)
#define FLAGS_IS_HOLOGRAM (1<<3)
#define FLAGS_IS_WIREFRAME_HOLOGRAM (1<<4)
#define FLAGS_SUPPORTSFORGECOATINGCUSTOMIZATION (1<<5)
#define FLAGS_IS_ALPHA_CLIP (1<<6)
#define FLAGS_IS_EXPLICIT_SHADER (1<<7)
#define FLAGS_USES_FADE_TIME (1<<8)
#define FLAGS_IS_HOLOGRAM_LOFI (1<<9)
#define FLAGS_CUSTOM_DEFORMER (1<<10)
#define FLAGS_HAS_COMPUTE (1<<11)
#define FLAGS_IS_SHIELD_GENERATOR (1<<12)
#define FLAGS_IS_OLYMPUS_EFFECT_LIGHTING (1<<13)
#define FLAGS_IS_SKINNED_TREE (1<<14)
#define FLAGS_IS_STATIC_BRANCHING_SHADER (1<<15)
#define FLAGS_GENERATOR_USES_DEPTH_BUFFER (1<<16)
#define FLAGS_HAS_SUBSURFACE_SCATTERING (1<<17)
#define FLAGS_TRANSPARENT_REQUIRES_SCENE_COLOR (1<<18)
#define FLAGS_USES_POINT_INPUT_PATCH (1<<19)
#define FLAGS_SUPPORTS_PACKED_OVT (1<<20)
#define FLAGS_USES_DEFERRED_SHADING (1<<21)
#define FLAGS_IS_DECORATOR (1<<22)
#define FLAGS_IS_FOLIAGE (1<<23)
#define FLAGS_IS_COMPOSITED_CARD (1<<24)
#define FLAGS_IS_LOW_RES_LIGHTING_ELIGIBLE (1<<25)
#define FLAGS_IS_HIGH_RES_LIGHTING_ELIGIBLE (1<<26)
#define FLAGS_IS_TWO_SIDED_SHADER (1<<27)
#define FLAGS_DECORATOR_REQUIRES_ZPP (1<<28)
#define FLAGS_USES_TERRAIN_SAMPLING (1<<29)
#define FLAGS_DECAL_USE_UAV_NORMAL (1<<30)


// Field compiler_flags

#define COMPILER_FLAGS_VALIDATION (1<<0)
#define COMPILER_FLAGS_DEBUG (1<<1)
#define COMPILER_FLAGS_DEOPTIMIZE (1<<2)
#define COMPILER_FLAGS_GENERATE_PDBS (1<<3)
#define COMPILER_FLAGS_ITERATION (1<<4)


// Field parameter_flags

#define PARAMETER_FLAGS_TEXTURE_ARRAY (1<<0)
#define PARAMETER_FLAGS_FORCE_BITMAP_CLAMP (1<<1)
#define PARAMETER_FLAGS_DISABLED (1<<2)
#define PARAMETER_FLAGS_HAS_TRANSFORM_FUNCTION (1<<3)
#define PARAMETER_FLAGS_BINDLESS (1<<4)




// Enum Definitions

// Enum parameter_type

enum parameter_type_enum {
    PARAMETER_TYPE_BITMAP,
    PARAMETER_TYPE_REAL,
    PARAMETER_TYPE_INT,
    PARAMETER_TYPE_BOOL,
    PARAMETER_TYPE_COLOR,
    PARAMETER_TYPE_SCALAR_GPU_PROPERTY,
    PARAMETER_TYPE_COLOR_GPU_PROPERTY,
    PARAMETER_TYPE_STRING,
    PARAMETER_TYPE_PRESET
};

// Enum type

enum type_enum {
    TYPE_VALUE,
    TYPE_COLOR,
    TYPE_SCALE_UNIFORM,
    TYPE_SCALE_U,
    TYPE_SCALE_V,
    TYPE_OFFSET_U,
    TYPE_OFFSET_V,
    TYPE_FRAME_INDEX,
    TYPE_ALPHA
};

// Enum Output_Modifier

enum Output_Modifier_enum {
    OUTPUT_MODIFIER__,
    OUTPUT_MODIFIER_ADD,
    OUTPUT_MODIFIER_MULTIPLY
};



// Structs

struct shaders{
    struct tagReference shader_bytecode;
};


struct shader_groups{
    struct tagBlock<shaders> shaders_ent;
    struct tagReference root_signature;
    uint8_t entrypoint_index;
    uint8_t vertex_type;
    uint8_t platform_marker;
    uint8_t generated_pad3c24;
    uint32_t shader_reference_type_offsets;
    string_id entrypoint_name;
    uint32_t generated_pad5605;
    uint64_t m_shaderPipeline;
};


struct function_parameters{
    uint32_t enum_type;
    string_id input_name;
    string_id range_name;
    uint8_t enum_Output_Modifier;
    uint8_t generated_pad8305;
    uint16_t generated_pad8305_2;
    string_id Output_Modifier_Input;
    float time_period;
    // EXPLANATION: FUNCTION
    // CUSTOM: function
    struct function{
        // CUSTOM: 
        struct dataReference data;
        // CUSTOM: 
    };
    struct function function_ent;
};


struct material_parameters{
    string_id parameter_name;
    uint32_t enum_parameter_type;
    struct tagReference bitmap;
    realARGBColor color;
    float real;
    struct vector3D vector;
    uint32_t int_bool;
    struct dataReference string;
    uint16_t bitmap_flags;
    uint16_t bitmap_filter_mode;
    uint16_t bitmap_address_mode;
    uint16_t bitmap_address_mode_x;
    uint16_t bitmap_address_mode_y;
    uint8_t bitmap_extern_mode;
    uint8_t bitmap_min_mipmap;
    uint8_t bitmap_max_mipmap;
    uint8_t generated_padea44;
    uint16_t generated_padea44_2;
    float bitmap_blur_and_sharpen;
    uint8_t flags_parameter_flags;
    uint8_t generated_pad0425;
    uint16_t generated_pad0425_2;
    uint32_t render_phases_used;
    uint32_t shader_types_used;
    struct tagBlock<function_parameters> function_parameters_ent;
    uint16_t register_offset;
    uint16_t register_size;
    uint8_t bitmap_extern_index;
    uint8_t generated_pad50da;
    uint16_t generated_pad50da_2;
};


struct emitter_property_names{
    string_id name;
};


struct renderer_property_names{
    string_id name;
};


struct simulator_property_names{
    string_id name;
};


// Root Block

struct shdv{
    struct AnyTag{
        uint64_t vtable_space;
        struct internal_struct{
            uint32_t global_tag_ID;
            uint32_t local_tag_handle;
        };
        struct internal_struct internal_struct_ent;
    };
    struct AnyTag AnyTag_ent;
    uint32_t flags_flags;
    uint32_t flags_compiler_flags;
    struct tagBlock<shader_groups> shader_groups_ent;
    struct tagBlock<material_parameters> material_parameters_ent;
    struct dataReference parameter_binding_data;
    struct tagBlock<emitter_property_names> emitter_property_names_ent;
    struct tagBlock<renderer_property_names> renderer_property_names_ent;
    struct tagBlock<simulator_property_names> simulator_property_names_ent;
    uint32_t generated_pad13ee;
    uint64_t runtime_pointer;
    uint32_t pad;
    uint32_t generated_pad60a3;
};


#ifdef SHDV_STRUCTURE_IMPL
// Tag Structure (used by the loader)

uint8_t shdv_structure[] {0x38,0x7,0x38,0x6,0x34,0x34,0x34,0x34,0x3B,0x3B,0xD,0xD,0x40,0x40,0x41,0x3B,0x41,0x3C,0x3C,0x3C,0x34,0x3E,0x2,0x34,0x34,0x34,0x34,0x7,0x3B,0x40,0x2,0xC,0x41,0x20,0x14,0x19,0x6,0x42,0x3D,0x3D,0x3D,0x3D,0x3D,0x3C,0x3C,0x3C,0x34,0x34,0x34,0x14,0xF,0x34,0x34,0x34,0x3E,0x3E,0x40,0xC,0x2,0x2,0xA,0x34,0x34,0x34,0x2,0x14,0x36,0x37,0x38,0x37,0x42,0x37,0x3B,0x3B,0x3D,0x3D,0x3C,0x34,0x34,0x34,0x3B,0x42,0x40,0x2,0x3B,0x40,0x2,0x3B,0x40,0x2,0x3B,0x34,0x34,0x34,0x34,0x7,0x34,0x34,0x34,0x34,0x34,0x34,0x34,0x34,0x3B};


#else
extern uint8_t shdv_structure[105];
#endif


#pragma pack(pop)

