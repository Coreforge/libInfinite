#pragma once
#pragma pack(push,1)
#include "../infiniteStructs.h"
#include <stdint.h>


/** 
  * This file was auto-generated with xml2h.py. DO NOT EDIT!!
  * Edit the XML files instead and regenerate this file.
  * Changes will not persist otherwise!
  */

// Generated from: hirt3/cwms.xml

// Flag Definitions

// Field Supported_Coating_Features_Flags

#define SUPPORTED_COATING_FEATURES_FLAGS_SUPPORTS_4_LAYERS (1<<0)
#define SUPPORTED_COATING_FEATURES_FLAGS_SUPPORTS_7_LAYERS (1<<1)
#define SUPPORTED_COATING_FEATURES_FLAGS_SUPPORTS_SCRATCHES (1<<2)
#define SUPPORTED_COATING_FEATURES_FLAGS_SUPPORTS_GRIME (1<<3)
#define SUPPORTED_COATING_FEATURES_FLAGS_SUPPORTS_DAMAGE (1<<4)
#define SUPPORTED_COATING_FEATURES_FLAGS_SUPPORTS_GLOBAL_EMISSIVE (1<<5)
#define SUPPORTED_COATING_FEATURES_FLAGS_SUPPORTS_LAYER_EMISSIVE (1<<6)
#define SUPPORTED_COATING_FEATURES_FLAGS_SUPPORTS_FORGE (1<<7)


// Field Supported_Coating_Features_Flags_2

#define SUPPORTED_COATING_FEATURES_FLAGS_2_SUPPORTS_4_LAYERS (1<<0)
#define SUPPORTED_COATING_FEATURES_FLAGS_2_SUPPORTS_7_LAYERS (1<<1)
#define SUPPORTED_COATING_FEATURES_FLAGS_2_SUPPORTS_SCRATCHES (1<<2)
#define SUPPORTED_COATING_FEATURES_FLAGS_2_SUPPORTS_GRIME (1<<3)
#define SUPPORTED_COATING_FEATURES_FLAGS_2_SUPPORTS_DAMAGE (1<<4)
#define SUPPORTED_COATING_FEATURES_FLAGS_2_SUPPORTS_GLOBAL_EMISSIVE (1<<5)
#define SUPPORTED_COATING_FEATURES_FLAGS_2_SUPPORTS_LAYER_EMISSIVE (1<<6)
#define SUPPORTED_COATING_FEATURES_FLAGS_2_SUPPORTS_FORGE (1<<7)




// Enum Definitions



// Structs

struct parameterRegisterInfo{
    uint16_t Register_Offset;
    uint16_t Register_Size;
};


struct defaultMaterial{
    struct tagReference coatingMaterialTemplate;
    uint16_t flags_Supported_Coating_Features_Flags;
    uint16_t generated_pad410b;
    struct tagBlock<parameterRegisterInfo> parameterRegisterInfo_ent;
};




struct perLayerEmissiveMaterial{
    struct tagReference coatingMaterialTemplate;
    uint16_t flags_Supported_Coating_Features_Flags_2;
    uint16_t generated_pad410b;
    struct tagBlock<parameterRegisterInfo> parameterRegisterInfo_ent;
};


// Root Block

struct cwms{
    struct AnyTag{
        uint64_t vtable_space;
        struct internal_struct{
            uint32_t global_tag_ID;
            uint32_t local_tag_handle;
        };
        struct internal_struct internal_struct_ent;
    };
    struct AnyTag AnyTag_ent;
    struct tagBlock<defaultMaterial> defaultMaterial_ent;
    struct tagBlock<perLayerEmissiveMaterial> perLayerEmissiveMaterial_ent;
    uint64_t m_pipelineStates;
};


#ifdef CWMS_STRUCTURE_IMPL
// Tag Structure (used by the loader)

uint8_t cwms_structure[] {0x38,0x7,0x38,0x6,0x34,0x34,0x34,0x34,0x3B,0x3B,0x40,0x41,0xE,0x34,0x34,0x40,0x3D,0x3D,0x3B,0x3B,0x40,0x41,0xE,0x34,0x34,0x40,0x3D,0x3D,0x3B,0x3B,0x7,0x3B};


#else
extern uint8_t cwms_structure[32];
#endif


#pragma pack(pop)

