#pragma once
#pragma pack(push,1)
#include "../infiniteStructs.h"
#include <stdint.h>


/** 
  * This file was auto-generated with xml2h.py. DO NOT EDIT!!
  * Edit the XML files instead and regenerate this file.
  * Changes will not persist otherwise!
  */

// Generated from: hirt/mat .xml

// Flag Definitions

// Field parameter_flags

#define PARAMETER_FLAGS_TEXTURE_ARRAY (1<<0)
#define PARAMETER_FLAGS_FORCE_BITMAP_CLAMP (1<<1)
#define PARAMETER_FLAGS_DISABLED (1<<2)
#define PARAMETER_FLAGS_HAS_TRANSFORM_FUNCTION (1<<3)
#define PARAMETER_FLAGS_BINDLESS (1<<4)


// Field runtime_flags

#define RUNTIME_FLAGS_BINDLESS_INDICES_ARE_UP_TO_DATE (1<<0)


// Field flags

#define FLAGS_HAS_MATERIAL_CONSTANT_FUNCTIONS (1<<0)
#define FLAGS_HAS_TEXTURE_FRAME_FUNCTIONS (1<<1)
#define FLAGS_DISABLE_ATMOSPHERE_FOG (1<<2)
#define FLAGS_MATERIAL_IS_VARIABLE (1<<3)
#define FLAGS_HAS_VARIABLE_MATERIAL_CONSTANT_FUNCTIONS (1<<4)
#define FLAGS_HAS_AT_LEAST_ONE_EXTERN_TEXTURE_USED (1<<5)
#define FLAGS_IS_ALPHA_CLIP (1<<6)
#define FLAGS_ENABLE_TAA_MASK (1<<7)
#define FLAGS_HAS_DAMAGE_MAP (1<<8)
#define FLAGS_HAS_PER_PLACEMENT_MATERIAL_CONSTANT_FUNCTIONS (1<<9)


// Field flags

#define FLAGS_CONVERTED_FROM_SHADER (1<<0)
#define FLAGS_DECAL_POST_LIGHTING (1<<1)
#define FLAGS_RUNTIME_GENERATED (1<<2)


// Field render_flags

#define RENDER_FLAGS_NO_ATMOSPHERE_FOG (1<<0)
#define RENDER_FLAGS_CULL_SHIELDS (1<<1)
#define RENDER_FLAGS_CULL_ACTIVE_CAMO (1<<2)
#define RENDER_FLAGS_MASK_TAA_FOR_TRANSPARENTS (1<<3)
#define RENDER_FLAGS_FORCE_RENDER_VELOCITY_FOR_TAA (1<<4)
#define RENDER_FLAGS_RENDER_DEPTH_INFO_WHEN_TRANSPARENT (1<<5)
#define RENDER_FLAGS_DISABLE_VRS_ON_PLATFORMS_THAT_SUPPORTS_IT (1<<6)




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

// Enum alpha_blend_mode

enum alpha_blend_mode_enum {
    ALPHA_BLEND_MODE_OPAQUE,
    ALPHA_BLEND_MODE_ADDITIVE,
    ALPHA_BLEND_MODE_MULTIPLY,
    ALPHA_BLEND_MODE_ALPHA_BLEND,
    ALPHA_BLEND_MODE_DOUBLE_MULTIPLY,
    ALPHA_BLEND_MODE_PRE_MULTIPLIED_ALPHA,
    ALPHA_BLEND_MODE_MAXIMUM,
    ALPHA_BLEND_MODE_MULTIPLY_ADD,
    ALPHA_BLEND_MODE_ADD_SRC_TIMES_DSTALPHA,
    ALPHA_BLEND_MODE_ADD_SRC_TIMES_SRCALPHA,
    ALPHA_BLEND_MODE_INV_ALPHA_BLEND,
    ALPHA_BLEND_MODE_OVERDRAW_APPLY,
    ALPHA_BLEND_MODE_DECAL,
    ALPHA_BLEND_MODE_MINIMUM,
    ALPHA_BLEND_MODE_REVSUBTRACT,
    ALPHA_BLEND_MODE_ALPHA_BLEND_MAX,
    ALPHA_BLEND_MODE_OPAQUE_ALPHA_BLEND,
    ALPHA_BLEND_MODE_ALPHA_BLEND_ADDITIVE_TRANSPARENT,
    ALPHA_BLEND_MODE_UNUSED0,
    ALPHA_BLEND_MODE_DECAL_ALPHA_BLEND,
    ALPHA_BLEND_MODE_DECAL_ADD_SRC_TIMES_SRC_ALPHA,
    ALPHA_BLEND_MODE_DECAL_MULTIPLY_ADD,
    ALPHA_BLEND_MODE_WPF_NO_COLOR_BLEND_MODE,
    ALPHA_BLEND_MODE_DECAL_OPAQUE,
    ALPHA_BLEND_MODE_ACCUMULATE_PRE_MULTIPLIED_ALPHA,
    ALPHA_BLEND_MODE_WPF_BLEND_MODE,
    ALPHA_BLEND_MODE_ACCUMULATE_MULTIPLY_ADD,
    ALPHA_BLEND_MODE_ACCUMULATE_ALPHA_BLEND,
    ALPHA_BLEND_MODE_ACCUMULATE_INVERSE_ALPHA_BLEND,
    ALPHA_BLEND_MODE_ACCUMULATE_ADDITIVE,
    ALPHA_BLEND_MODE_ACCUMULATE_ADDITIVE_TRANSPARENT,
    ALPHA_BLEND_MODE_ACCUMULATE_ADD_SRC_TIMES_SRCALPHA,
    ALPHA_BLEND_MODE_ACCUMULATE_MULTIPLY,
    ALPHA_BLEND_MODE_ALPHA_BLEND_FOR_DISPLAY_PLANES,
    ALPHA_BLEND_MODE_TEXTUREPAINTER_SRCADDDESTMULT,
    ALPHA_BLEND_MODE_TEXTUREPAINTER_DESTMULTSUBSRC,
    ALPHA_BLEND_MODE_LOGICAL_OR,
    ALPHA_BLEND_MODE_LOGICAL_AND,
    ALPHA_BLEND_MODE_DECAL_MULTIPLY,
    ALPHA_BLEND_MODE_DECAL_DOUBLE_MULTIPLY,
    ALPHA_BLEND_MODE_FOURCHANNELADDITIVE,
    ALPHA_BLEND_MODE_WPF_ADDITIVE_BLEND_MODE,
    ALPHA_BLEND_MODE_CLOUD_APPLY,
    ALPHA_BLEND_MODE_SUBSURFACESCATTERING_CONVOLUTION,
    ALPHA_BLEND_MODE_REFLECTIONOCCLUSIONMASK,
    ALPHA_BLEND_MODE_TAA_MASK_ADDITIVE,
    ALPHA_BLEND_MODE_TAA_MASK_REVSUBTRACT,
    ALPHA_BLEND_MODE_TAA_MASK_MULTIPLY,
    ALPHA_BLEND_MODE_TAA_MASK_DOUBLEMULTIPLY,
    ALPHA_BLEND_MODE_TAA_MASK_PREMULTIPLIEDALPHA,
    ALPHA_BLEND_MODE_TAA_MASK_MULTIPLYADD,
    ALPHA_BLEND_MODE_TAA_MASK_ALPHABLEND,
    ALPHA_BLEND_MODE_TAA_MASK_ADDSRCTIMESDSTALPHA,
    ALPHA_BLEND_MODE_TAA_MASK_ADDSRCTIMESSRCALPHA,
    ALPHA_BLEND_MODE_TAA_MASK_ADDITIVETRANSPARENT,
    ALPHA_BLEND_MODE_TAA_MASK_ALPHA_BLEND_FOR_DISPLAY_PLANE,
    ALPHA_BLEND_MODE_TAA_VELOCITY_ADDITIVE,
    ALPHA_BLEND_MODE_TAA_VELOCITY_REVSUBTRACT,
    ALPHA_BLEND_MODE_TAA_VELOCITY_MULTIPLY,
    ALPHA_BLEND_MODE_TAA_VELOCITY_DOUBLEMULTIPLY,
    ALPHA_BLEND_MODE_TAA_VELOCITY_PREMULTIPLIEDALPHA,
    ALPHA_BLEND_MODE_TAA_VELOCITY_MULTIPLYADD,
    ALPHA_BLEND_MODE_TAA_VELOCITY_ALPHABLEND,
    ALPHA_BLEND_MODE_TAA_VELOCITY_ADDSRCTIMESDSTALPHA,
    ALPHA_BLEND_MODE_TAA_VELOCITY_ADDSRCTIMESSRCALPHA,
    ALPHA_BLEND_MODE_TAA_VELOCITY_ADDITIVETRANSPARENT,
    ALPHA_BLEND_MODE_TAA_VELOCITY_ALPHA_BLEND_FOR_DISPLAY_PLANE,
    ALPHA_BLEND_MODE_DEFERREDDECALSRESOLVE,
    ALPHA_BLEND_MODE_DECAL_AO_OPAQUE,
    ALPHA_BLEND_MODE_DECAL_AO_ALPHA_BLEND,
    ALPHA_BLEND_MODE_DECAL_SSS_BLEND,
    ALPHA_BLEND_MODE_HUD_DAMAGE_ALPHA_BLEND
};

// Enum sort_layer

enum sort_layer_enum {
    SORT_LAYER_INVALID,
    SORT_LAYER_PRE_PASS,
    SORT_LAYER_NORMAL,
    SORT_LAYER_POST_PASS
};

// Enum Number_of_Supported_Layers_For_Material_Shader

enum Number_of_Supported_Layers_For_Material_Shader_enum {
    NUMBER_OF_SUPPORTED_LAYERS_FOR_MATERIAL_SHADER_SUPPORTS1LAYER,
    NUMBER_OF_SUPPORTED_LAYERS_FOR_MATERIAL_SHADER_SUPPORTS4LAYERS,
    NUMBER_OF_SUPPORTED_LAYERS_FOR_MATERIAL_SHADER_SUPPORTS7LAYERS,
    NUMBER_OF_SUPPORTED_LAYERS_FOR_MATERIAL_SHADER_SUPPORTS0LAYERS
};



// Structs

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


struct textures{
    struct tagReference bitmap_reference;
    uint32_t render_phase_mask;
    uint32_t shader_stage_mask;
    uint16_t frame_index_parameter;
    uint16_t sampler_index;
    uint16_t transform_register_index;
    uint16_t bindless_parameter_register_offset;
    uint8_t extern_texture_mode;
    uint8_t extern_texture_index;
    uint16_t generated_pad0c27;
    uint64_t m_samplerStateView;
};


struct functions{
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




struct extern_parameters{
    uint8_t extern_index;
    uint8_t extern_offset;
    uint8_t parameter_group;
    uint8_t generated_paddcf2;
    uint16_t bindless_parameter_register_offset;
    uint16_t generated_pad29a7;
    uint32_t render_phase_mask;
};


struct material_constants{
    realQuaternion register_field;
};


struct alternate_constants{
    realQuaternion register_field;
};


struct postprocess_definition{
    struct tagBlock<textures> textures_ent;
    uint32_t textures_to_clear;
    struct tagBlock<functions> functions_ent;
    struct tagBlock<function_parameters> function_parameters_ent;
    struct tagBlock<extern_parameters> extern_parameters_ent;
    uint8_t enum_alpha_blend_mode;
    uint8_t flags_runtime_flags;
    uint16_t flags_flags;
    struct tagBlock<material_constants> material_constants_ent;
    struct tagBlock<alternate_constants> alternate_constants_ent;
    uint64_t materialConstantBuffer;
    uint64_t alternateConstantBuffer;
    uint32_t material_constant_shader_stage_mask;
// Array with 4 elements
    uint8_t index[4];
    struct alpha_clip_descriptor{
        uint8_t textureIndex;
        uint8_t textureChannel;
        uint16_t generated_pad14ce;
        uint32_t thresholdIndex;
    };
    struct alpha_clip_descriptor alpha_clip_descriptor_ent;
};


struct style_info{
    struct tagReference material_style;
    struct tagReference material_style_tag;
    string_id region_name;
    string_id base_intention;
    string_id mask_0_red_channel_intention;
    string_id mask_0_green_channel_intention;
    string_id mask_0_blue_channel_intention;
    string_id mask_1_red_channel_intention;
    string_id mask_1_green_channel_intention;
    string_id mask_1_blue_channel_intention;
    uint8_t enum_Number_of_Supported_Layers_For_Material_Shader;
    uint8_t generated_pada41a;
    uint16_t generated_pada41a_2;
};


// Root Block

struct mat_{
    struct anon_struct_0{
        uint64_t vtable_space;
        struct internal_struct{
            uint32_t global_tag_ID;
            uint32_t local_tag_handle;
        };
        struct internal_struct internal_struct_ent;
    };
    struct anon_struct_0 anon_struct_0_ent;
    struct tagReference material_shader;
    struct tagBlock<material_parameters> material_parameters_ent;
    struct tagBlock<postprocess_definition> postprocess_definition_ent;
    string_id physics_material_name;
    string_id physics_material_name_2;
    string_id physics_material_name_3;
    string_id physics_material_name_4;
    float sort_offset;
    uint8_t enum_alpha_blend_mode;
    uint8_t enum_sort_layer;
    uint8_t flags_flags;
    uint8_t flags_render_flags;
    float taa_mask_threshold_start;
    float taa_mask_threshold_end;
    struct tagBlock<style_info> style_info_ent;
};


#ifdef MAT__STRUCTURE_IMPL
// Tag Structure (used by the loader)

uint8_t mat__structure[] {0x38,0x7,0x38,0x6,0x34,0x34,0x34,0x34,0x3B,0x3B,0x41,0x40,0x2,0xC,0x41,0x20,0x14,0x19,0x6,0x42,0x3D,0x3D,0x3D,0x3D,0x3D,0x3C,0x3C,0x3C,0x34,0x34,0x34,0x14,0xF,0x34,0x34,0x34,0x3E,0x3E,0x40,0xC,0x2,0x2,0xA,0x34,0x34,0x34,0x2,0x14,0x36,0x37,0x38,0x37,0x42,0x37,0x3B,0x3B,0x3D,0x3D,0x3C,0x34,0x34,0x34,0x3B,0x40,0x40,0x41,0x3E,0x3E,0x3D,0x3D,0x3D,0x3D,0x3C,0x3C,0x34,0x34,0x7,0x3B,0x6,0x40,0xC,0x2,0x2,0xA,0x34,0x34,0x34,0x2,0x14,0x36,0x37,0x38,0x37,0x42,0x37,0x3B,0x3B,0x40,0x3C,0x3C,0x3C,0x34,0x3E,0x3B,0x40,0x3C,0x3C,0x3C,0x34,0x3D,0x34,0x34,0x3E,0x3B,0xA,0xF,0xE,0x40,0x1A,0x3B,0x40,0x1A,0x3B,0x7,0x7,0x3E,0x39,0x0004,0x3C,0x38,0x3C,0x3C,0x34,0x34,0x6,0x3B,0x3B,0x2,0x2,0x2,0x2,0x14,0xA,0xA,0xF,0xF,0x14,0x14,0x40,0x41,0x41,0x2,0x2,0x2,0x2,0x2,0x2,0x2,0x2,0xA,0x34,0x34,0x34,0x3B,0x3B};


#else
extern uint8_t mat__structure[166];
#endif


#pragma pack(pop)

