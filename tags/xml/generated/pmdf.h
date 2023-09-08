#pragma once
#pragma pack(push,1)
#include "../infiniteStructs.h"
#include <stdint.h>


/** 
  * This file was auto-generated with xml2h.py. DO NOT EDIT!!
  * Edit the XML files instead and regenerate this file.
  * Changes will not persist otherwise!
  */

// Generated from: hirt2/pmdf.xml

// Flag Definitions

// Field runtime_flags

#define RUNTIME_FLAGS_PROCESSED (1<<0)
#define RUNTIME_FLAGS_AVAILABLE (1<<1)
#define RUNTIME_FLAGS_HAS_VALID_BUDGETS_REALLY (1<<2)
#define RUNTIME_FLAGS_MANUAL_RESOURCE_CREATION (1<<3)
#define RUNTIME_FLAGS_KEEP_RAW_GEOMETRY (1<<4)
#define RUNTIME_FLAGS_DONT_USE_COMPRESSED_VERTEX_POSITIONS (1<<5)
#define RUNTIME_FLAGS_PCA_ANIMATION_TABLE_SORTED (1<<6)
#define RUNTIME_FLAGS_HAS_DUAL_QUAT (1<<7)
#define RUNTIME_FLAGS_MESH_STREAMING (1<<8)


// Field flags

#define FLAGS_INDICES_ARE_TRIANGLE_STRIPS (1<<0)
#define FLAGS_INDICES_ARE_TRIANGLE_LISTS (1<<1)
#define FLAGS_INDICES_ARE_QUAD_LISTS (1<<2)


// Field part_flags

#define PART_FLAGS_DRAW_CULL_RENDERING_SHIELDS (1<<0)
#define PART_FLAGS_BLENDSHAPE (1<<1)
#define PART_FLAGS_COLORMASK_CONTROL_NORMALBLEND (1<<2)
#define PART_FLAGS_DRAW_CULL_RENDERING_ACTIVE_CAMO (1<<3)
#define PART_FLAGS_DONT_USE_VIRTUAL_TEXTURING (1<<4)
#define PART_FLAGS_VIRTUAL_TEXTURING_UV_SHELL_SKIRT (1<<5)


// Field lod_flags

#define LOD_FLAGS_LOD_0 (1<<0)
#define LOD_FLAGS_LOD_1 (1<<1)
#define LOD_FLAGS_LOD_2 (1<<2)
#define LOD_FLAGS_LOD_3 (1<<3)
#define LOD_FLAGS_LOD_4 (1<<4)
#define LOD_FLAGS_LOD_5 (1<<5)
#define LOD_FLAGS_LOD_6 (1<<6)
#define LOD_FLAGS_LOD_7 (1<<7)
#define LOD_FLAGS_LOD_8 (1<<8)
#define LOD_FLAGS_LOD_9 (1<<9)
#define LOD_FLAGS_LOD_10 (1<<10)
#define LOD_FLAGS_LOD_11 (1<<11)
#define LOD_FLAGS_LOD_12 (1<<12)
#define LOD_FLAGS_LOD_13 (1<<13)
#define LOD_FLAGS_LOD_14 (1<<14)
#define LOD_FLAGS_LOD_15 (1<<15)


// Field lod_render_flags

#define LOD_RENDER_FLAGS_LOD_HAS_SHADOW_PROXIES (1<<0)


// Field mesh_flags

#define MESH_FLAGS_MESH_HAS_VERTEX_COLOR (1<<0)
#define MESH_FLAGS_USE_REGION_INDEX_FOR_SORTING (1<<1)
#define MESH_FLAGS_CAN_BE_RENDERED_IN_DRAW_BUNDLES (1<<2)
#define MESH_FLAGS_MESH_IS_CUSTOM_SHADOW_CASTER (1<<3)
#define MESH_FLAGS_MESH_IS_UNINDEXED_DO_NOT_MODIFY (1<<4)
#define MESH_FLAGS_MASH_SHOULD_RENDER_IN_Z_PREPASS (1<<5)
#define MESH_FLAGS_USE_UNCOMPRESSED_VERTEX_FORMAT (1<<6)
#define MESH_FLAGS_MESH_IS_PCA (1<<7)
#define MESH_FLAGS_MESH_HAS_A_USEFUL_SET_OF_SECOND_TEXTURE_COORDS (1<<8)
#define MESH_FLAGS_MESH_HAS_A_USEFUL_SET_OF_THIRD_TEXTURE_COORDS (1<<9)
#define MESH_FLAGS_USE_UV3_TANGENT_ROTATION (1<<10)


// Field compression_flags

#define COMPRESSION_FLAGS_COMPRESSED_POSITION (1<<0)
#define COMPRESSION_FLAGS_COMPRESSED_TEXCOORD (1<<1)
#define COMPRESSION_FLAGS_COMPRESSION_OPTIMIZED (1<<2)


// Field meta_data_flags

#define META_DATA_FLAGS_HAS_BLENDSHAPE (1<<0)




// Enum Definitions

// Enum vertex_type

enum vertex_type_enum {
    VERTEX_TYPE_WORLD,
    VERTEX_TYPE_RIGID,
    VERTEX_TYPE_SKINNED,
    VERTEX_TYPE_PARTICLE_MODEL,
    VERTEX_TYPE_SCREEN,
    VERTEX_TYPE_DEBUG,
    VERTEX_TYPE_TRANSPARENT,
    VERTEX_TYPE_PARTICLE,
    VERTEX_TYPE_REMOVED08,
    VERTEX_TYPE_REMOVED09,
    VERTEX_TYPE_CHUD_SIMPLE,
    VERTEX_TYPE_DECORATOR,
    VERTEX_TYPE_POSITION_ONLY,
    VERTEX_TYPE_REMOVED13,
    VERTEX_TYPE_RIPPLE,
    VERTEX_TYPE_REMOVED15,
    VERTEX_TYPE_TESSELLATEDTERRAIN,
    VERTEX_TYPE_EMPTY,
    VERTEX_TYPE_DECAL,
    VERTEX_TYPE_REMOVED19,
    VERTEX_TYPE_REMOVED20,
    VERTEX_TYPE_POSITION_ONLY_2,
    VERTEX_TYPE_TRACER,
    VERTEX_TYPE_RIGID_BONED,
    VERTEX_TYPE_REMOVED24,
    VERTEX_TYPE_CHEAPPARTICLE,
    VERTEX_TYPE_DQ_SKINNED,
    VERTEX_TYPE_SKINNED_8_WEIGHTS,
    VERTEX_TYPE_TESSELLATED_VECTOR,
    VERTEX_TYPE_INTERACTION,
    VERTEX_TYPE_NUMBER_OF_STANDARD_VERTEX_TYPES
};

// Enum index_buffer_type

enum index_buffer_type_enum {
    INDEX_BUFFER_TYPE_DEFAULT,
    INDEX_BUFFER_TYPE_LINE_LIST,
    INDEX_BUFFER_TYPE_LINE_STRIP,
    INDEX_BUFFER_TYPE_TRIANGLE_LIST,
    INDEX_BUFFER_TYPE_TRIANGLE_PATCH,
    INDEX_BUFFER_TYPE_TRIANGLE_STRIP,
    INDEX_BUFFER_TYPE_QUAD_LIST
};

// Enum mesh_resource_packing_policy

enum mesh_resource_packing_policy_enum {
    MESH_RESOURCE_PACKING_POLICY_SINGLE_RESOURCE,
    MESH_RESOURCE_PACKING_POLICY_N_MESHES_PER_RESOURCE
};

// Enum usage

enum usage_enum {
    USAGE_POSITION,
    USAGE_UV0,
    USAGE_UV1,
    USAGE_UV2,
    USAGE_COLOR,
    USAGE_NORMAL,
    USAGE_TANGENT,
    USAGE_BLENDINDICES0,
    USAGE_BLENDWEIGHTS0,
    USAGE_BLENDINDICES1,
    USAGE_BLENDWEIGHTS1,
    USAGE_PREVPOSITION,
    USAGE_INSTANCEDATA,
    USAGE_BLENDSHAPEPOSITION,
    USAGE_BLENDSHAPENORMAL,
    USAGE_BLENDSHAPEINDEX,
    USAGE_EDGE,
    USAGE_EDGEINDEX,
    USAGE_EDGEINDEXINFO
};

// Enum format

enum format_enum {
    FORMAT_REAL,
    FORMAT_REALVECTOR2D,
    FORMAT_REALVECTOR3D,
    FORMAT_REALVECTOR4D,
    FORMAT_BYTEVECTOR4D,
    FORMAT_BYTEARGBCOLOR,
    FORMAT_SHORTVECTOR2D,
    FORMAT_SHORTVECTOR2DNORMALIZED,
    FORMAT_SHORTVECTOR4DNORMALIZED,
    FORMAT_WORDVECTOR2DNORMALIZED,
    FORMAT_WORDVECTOR4DNORMALIZED,
    FORMAT_REAL16VECTOR2D,
    FORMAT_REAL16VECTOR4D,
    FORMAT_10_10_10_NORMALIZED,
    FORMAT_10_10_10_2,
    FORMAT_10_10_10_2_SIGNEDNORMALIZEDPACKEDASUNORM,
    FORMAT_DWORD,
    FORMAT_DWORDVECTOR2D,
    FORMAT_11_11_10_FLOAT,
    FORMAT_BYTEUNITVECTOR3D,
    FORMAT_WORDVECTOR3DNORMALIZEDWITH4WORD
};

// Enum vertex_format

enum vertex_format_enum {
    VERTEX_FORMAT_REAL,
    VERTEX_FORMAT_REALVECTOR2D,
    VERTEX_FORMAT_REALVECTOR3D,
    VERTEX_FORMAT_REALVECTOR4D,
    VERTEX_FORMAT_BYTEVECTOR4D,
    VERTEX_FORMAT_BYTEARGBCOLOR,
    VERTEX_FORMAT_SHORTVECTOR2D,
    VERTEX_FORMAT_SHORTVECTOR2DNORMALIZED,
    VERTEX_FORMAT_SHORTVECTOR4DNORMALIZED,
    VERTEX_FORMAT_WORDVECTOR2DNORMALIZED,
    VERTEX_FORMAT_WORDVECTOR4DNORMALIZED,
    VERTEX_FORMAT_REAL16VECTOR2D,
    VERTEX_FORMAT_REAL16VECTOR4D,
    VERTEX_FORMAT_10_10_10_NORMALIZED,
    VERTEX_FORMAT_10_10_10_2,
    VERTEX_FORMAT_10_10_10_2_SIGNEDNORMALIZEDPACKEDASUNORM,
    VERTEX_FORMAT_DWORD,
    VERTEX_FORMAT_DWORDVECTOR2D,
    VERTEX_FORMAT_11_11_10_FLOAT,
    VERTEX_FORMAT_BYTEUNITVECTOR3D,
    VERTEX_FORMAT_WORDVECTOR3DNORMALIZEDWITH4WORD
};



// Structs

struct meshes_import_info{
    uint32_t CRC;
    struct point3D position_bounds_0;
    struct point3D position_bounds_1;
    struct point2D texcoord_bounds_0;
    struct point2D texcoord_bounds_1;
};


struct raw_vertices{
    struct point3D position;
    struct point2D texcoord;
    struct point3D normal;
    struct point3D binormal;
    struct point3D tangent;
    struct point2D lightmap_texcoord;
// Array with 8 elements
    uint8_t node_index[8];
// Array with 8 elements
    float node_weight[8];
    struct point3D vertex_color;
    struct point2D texcoord1;
    float dual_quat_weight;
    float vertex_alpha;
    struct point3D tangent_UV2;
    struct point2D texcoord2;
    struct point3D tangent_UV3;
};


struct raw_indices{
    uint16_t word;
};


struct raw_indices32{
    uint32_t dword;
};


struct raw_water_indices{
    uint16_t word;
};


struct raw_water_vertices{
    struct point2D base_texcoord;
};


struct raw_water_data{
    struct tagBlock<raw_water_indices> raw_water_indices_ent;
    struct tagBlock<raw_water_vertices> raw_water_vertices_ent;
};


struct raw_blendshapes{
    struct vector3D position;
    struct vector3D normal;
    realARGBColor tension_and_ambient_occlusion;
    uint32_t target_Id;
};


struct raw_blendshapes_indices{
    uint32_t dword;
};


struct raw_tension_edges{
    uint32_t start_vertex_index;
    uint32_t end_vertex_index;
    float edge_rest_length;
};


struct raw_blendshapes_triangle_and_edge_Indices{
    uint32_t dword;
};


struct raw_blendshapes_triangle_and_edge_index_info{
    uint32_t triangle_and_edge_index_pos;
    uint32_t encoded_triangle_and_edge_size;
};


struct Asset_variants{
    string_id Variant_name;
    struct tagReference Runtime_Geo;
    struct tagReference Static_Collision_Geo;
};


struct level_breakdown_data{
    struct tagReference Asset_tag;
    string_id Default_variant_name;
    struct tagReference LOD_settings_tag;
    string_id LOD_settings_name;
    uint32_t Convert_Collision_to_Shadow_Geometry;
    struct tagBlock<Asset_variants> Asset_variants_ent;
};


struct per_mesh_temporary{
    struct tagBlock<raw_vertices> raw_vertices_ent;
    struct tagBlock<raw_indices> raw_indices_ent;
    struct tagBlock<raw_indices32> raw_indices32_ent;
    struct tagBlock<raw_water_data> raw_water_data_ent;
    struct tagBlock<raw_blendshapes> raw_blendshapes_ent;
    struct tagBlock<raw_blendshapes_indices> raw_blendshapes_indices_ent;
    struct tagBlock<raw_tension_edges> raw_tension_edges_ent;
    struct tagBlock<raw_blendshapes_triangle_and_edge_Indices> raw_blendshapes_triangle_and_edge_Indices_ent;
    struct tagBlock<raw_blendshapes_triangle_and_edge_index_info> raw_blendshapes_triangle_and_edge_index_info_ent;
    uint32_t flags_flags;
    struct tagBlock<level_breakdown_data> level_breakdown_data_ent;
};


struct part_sorting_position{
    realPlane3D plane;
    struct point3D position;
    float radius;
// Array with 8 elements
    uint8_t node_index[8];
// Array with 7 elements
    float node_weight[7];
};


struct parts{
    shortBlockIndex material_index;
    shortBlockIndex transparent_sorting_index;
    uint32_t index_start;
    uint32_t index_count;
    uint32_t perMeshPartConstantsOffset;
    uint8_t part_type;
    uint8_t generated_pad5c53;
    uint16_t flags_part_flags;
    uint16_t budget_vertex_count;
    uint16_t generated_pad0f9e;
};


struct subparts{
    uint32_t index_start;
    uint32_t index_count;
    shortBlockIndex part_index;
    uint16_t budget_vertex_count;
};


struct material_streaming_scale{
    uint32_t material_index;
    float material_scale;
};


struct LOD_render_data{
    struct tagBlock<per_mesh_temporary> per_mesh_temporary_ent;
    struct tagBlock<part_sorting_position> part_sorting_position_ent;
    struct tagBlock<parts> parts_ent;
    struct tagBlock<subparts> subparts_ent;
    struct tagBlock<material_streaming_scale> material_streaming_scale_ent;
// Array with 19 elements
    uint16_t vertex_buffer_index[19];
    uint16_t index_buffer_index;
    uint16_t flags_lod_flags;
    uint16_t flags_lod_render_flags;
    uint16_t raytracing_metadata_index;
    uint16_t generated_paddaed;
};


struct vertex_keys{
    uint32_t key1;
    uint32_t key2;
};


struct meshes{
    struct tagBlock<LOD_render_data> LOD_render_data_ent;
    uint16_t flags_mesh_flags;
    uint8_t rigid_node_index;
    uint8_t enum_vertex_type;
    uint8_t use_dual_quat;
    uint8_t enum_index_buffer_type;
    uint16_t pca_mesh_index;
    struct tagBlock<vertex_keys> vertex_keys_ent;
    shortBlockIndex clone_index;
    uint16_t optional_LOD_volume_index;
    uint16_t Procedural_Deformation_Remap_Table;
    uint16_t generated_pad8fb3;
    uint32_t lod_state_cache_slot;
};


struct PCA_Mesh_Indices{
    longBlockIndex mesh_index;
};


struct compression_info{
    uint16_t flags_compression_flags;
    uint16_t generated_pad1711;
    // EXPLANATION: WARNING
    struct point3D position_bounds_0;
    struct point3D position_bounds_1;
    struct point2D texcoord_bounds_0;
    struct point2D texcoord_bounds_1;
    struct point2D texcoord_bounds2_0;
    struct point2D texcoord_bounds2_1;
    struct point2D texcoord_bounds3_0;
    struct point2D texcoord_bounds3_1;
    float unused0;
    float unused1;
};


struct node_map{
    uint16_t node_index;
};


struct per_mesh_node_map{
    struct tagBlock<node_map> node_map_ent;
};


struct Optional_animated_mesh_tag_references{
    struct tagReference Animated_mesh_tag_reference;
    string_id Name;
};


struct position_data{
    realPlane3D plane;
    struct point3D position;
    float radius;
// Array with 8 elements
    uint8_t node_index[8];
// Array with 7 elements
    float node_weight[7];
};


struct Optional_LOD_volumes_data{
    struct point3D position_bounds_0;
    struct point3D position_bounds_1;
    struct tagBlock<position_data> position_data_ent;
};


struct pc_vertex_buffers{
    uint32_t enum_usage;
    uint32_t enum_format;
    uint8_t stride;
    uint8_t ownsD3DResource;
    uint16_t generated_pad9e95;
    uint32_t count;
    uint32_t offset;
    struct d3dbuffer{
        uint32_t byte_width;
        uint32_t bind_flags;
        uint32_t misc_flags;
        uint32_t stride;
        struct dataReference d3d_buffer;
        uint16_t usage;
        uint16_t cpu_flags;
    };
    struct d3dbuffer d3dbuffer_ent;
    uint64_t m_resource;
    uint64_t m_resourceView;
};


struct pc_index_buffers{
    uint8_t declaration_type;
    uint8_t stride;
    uint8_t ownsD3DResource;
    uint8_t generated_pad8bf7;
    uint32_t count;
    uint32_t offset;
    struct d3dbuffer{
        uint32_t byte_width;
        uint32_t bind_flags;
        uint32_t misc_flags;
        uint32_t stride;
        struct dataReference d3d_buffer;
        uint16_t usage;
        uint16_t cpu_flags;
    };
    struct d3dbuffer d3dbuffer_ent;
    uint64_t m_resource;
    uint64_t m_resourceView;
};


struct mesh_part_metadata{
    uint32_t index_count;
    uint32_t index_offset;
    uint8_t geo_type;
    uint8_t generated_padf9a7;
    uint16_t generated_padf9a7_2;
};


struct raytracing_metadata{
    uint16_t index_buffer_index;
    uint16_t vertex_buffer_index;
    uint32_t enum_vertex_format;
    uint8_t enum_vertex_type;
    uint8_t generated_pad35fb;
    uint16_t generated_pad35fb_2;
    struct vector3D decompression_Scale;
    struct vector3D decompression_Translation;
    struct tagBlock<mesh_part_metadata> mesh_part_metadata_ent;
    uint16_t flags_meta_data_flags;
    uint32_t generated_pade946;
    uint16_t generated_pade946_2;
    struct blas_offline_data{
        struct dataReference Temp_BLAS_buffer;
        uint32_t PostbuildCurrentSize;
        uint32_t PostbuildSerializedSize;
        uint32_t offset;
        uint32_t generated_pad707f;
        uint64_t m_resource;
    };
    struct blas_offline_data blas_offline_data_ent;
};


struct mesh_lod_chunks{
    struct dataReference chunks;
};


struct Streaming_Meshes{
    uint32_t lod_state_cache_slot;
    uint8_t required_lod;
    uint8_t generated_pad413f;
    uint16_t generated_pad413f_2;
    struct dataReference lod_raytracing_meta_data;
    struct tagBlock<mesh_lod_chunks> mesh_lod_chunks_ent;
};


struct Streaming_Chunks{
    uint16_t buffer_index;
    uint16_t allocation_priority;
    uint32_t buffer_start;
    uint32_t buffer_end;
};


struct Streaming_Buffers{
    uint32_t buffer_size;
    uint32_t bind_flags;
    struct dataReference Temp_buffer_for_pipeline;
};


struct mesh_resource{
    struct tagBlock<pc_vertex_buffers> pc_vertex_buffers_ent;
    struct tagBlock<pc_index_buffers> pc_index_buffers_ent;
    struct tagBlock<raytracing_metadata> raytracing_metadata_ent;
    struct tagBlock<Streaming_Meshes> Streaming_Meshes_ent;
    struct tagBlock<Streaming_Chunks> Streaming_Chunks_ent;
    struct tagBlock<Streaming_Buffers> Streaming_Buffers_ent;
    uint64_t m_sharedDXResources;
    uint64_t m_sharedDXResourceRawView;
// Array with 21 elements
    uint64_t IResourceView[21];
    uint64_t Runtime_Data;
};


struct mesh_resource_groups{
    struct externalResource<mesh_resource> mesh_resource_res;
};


struct index_resource_look_up{
    uint16_t resource_group_index;
    uint16_t group_item_index;
};


struct vertex_resource_look_up{
    uint16_t resource_group_index;
    uint16_t group_item_index;
};


struct raytracing_resource_look_up{
    uint16_t resource_group_index;
    uint16_t group_item_index;
};


struct raw_target_hash_name{
    uint32_t dword;
};


struct blendshape_compression_info{
    struct point3D position_scale;
    struct point3D position_offset;
    struct point3D normal_scale;
    struct point3D normal_offset;
    struct tagBlock<raw_target_hash_name> raw_target_hash_name_ent;
};


struct parameter_list{
    string_id parameter_name;
    uint8_t parameter_mode;
    uint8_t generated_pad8065;
    uint16_t generated_pad8065_2;
    float constant_input;
};


struct blendshape_Procedural_Deformation_function_list{
    struct tagBlock<parameter_list> parameter_list_ent;
    string_id Procedural_deformation_function_name;
};


struct Procedural_Remap_Table{
    uint16_t word;
};


struct Procedural_Deformation_function_Remap_Table_List{
    struct tagBlock<Procedural_Remap_Table> Procedural_Remap_Table_ent;
};


struct Deformation_parameter_default_value_table_from_skeleton{
    string_id parameter_name;
    float parameter_default_value;
};


struct m_variants{
// Array with 4 elements
    float runtime_gpu_real[4];
};


// Root Block

struct pmdf{
    struct AnyTag{
        uint64_t vtable_space;
        struct internal_struct{
            uint32_t global_tag_ID;
            uint32_t local_tag_handle;
        };
        struct internal_struct internal_struct_ent;
    };
    struct AnyTag AnyTag_ent;
    struct render_geometry{
        uint32_t flags_runtime_flags;
        struct tagBlock<meshes_import_info> meshes_import_info_ent;
        struct tagBlock<meshes> meshes_ent;
        struct tagBlock<PCA_Mesh_Indices> PCA_Mesh_Indices_ent;
        struct tagBlock<compression_info> compression_info_ent;
        struct tagBlock<per_mesh_node_map> per_mesh_node_map_ent;
        struct tagBlock<Optional_animated_mesh_tag_references> Optional_animated_mesh_tag_references_ent;
        struct tagBlock<Optional_LOD_volumes_data> Optional_LOD_volumes_data_ent;
        struct mesh_package{
            uint16_t flags;
            uint16_t enum_mesh_resource_packing_policy;
            uint16_t total_index_buffer_count;
            uint16_t total_vertex_buffer_count;
            uint16_t total_raytracing_metadata_count;
            uint16_t generated_pad4c35;
            struct tagBlock<mesh_resource_groups> mesh_resource_groups_ent;
            struct tagBlock<index_resource_look_up> index_resource_look_up_ent;
            struct tagBlock<vertex_resource_look_up> vertex_resource_look_up_ent;
            struct tagBlock<raytracing_resource_look_up> raytracing_resource_look_up_ent;
        };
        struct mesh_package mesh_package_ent;
        struct tagBlock<blendshape_compression_info> blendshape_compression_info_ent;
        struct tagBlock<blendshape_Procedural_Deformation_function_list> blendshape_Procedural_Deformation_function_list_ent;
        struct tagBlock<Procedural_Deformation_function_Remap_Table_List> Procedural_Deformation_function_Remap_Table_List_ent;
        struct tagBlock<Deformation_parameter_default_value_table_from_skeleton> Deformation_parameter_default_value_table_from_skeleton_ent;
        uint32_t generated_paddf2d;
        uint64_t perMeshPartConstantBuffer;
        uint8_t target_platformization;
        uint32_t generated_padc54c;
        uint16_t generated_padc54c_2;
        uint8_t generated_padc54c_3;
    };
    struct render_geometry render_geometry_ent;
    struct m_gpu_data{
        struct tagBlock<m_variants> m_variants_ent;
    };
    struct m_gpu_data m_gpu_data_ent;
    uint32_t generated_pad910e;
};


#ifdef PMDF_STRUCTURE_IMPL
// Tag Structure (used by the loader)

uint8_t pmdf_structure[] {0x38,0x7,0x38,0x6,0x34,0x34,0x34,0x34,0x3B,0x3B,0x38,0xD,0x40,0x3E,0x17,0x17,0x16,0x16,0x3B,0x40,0x40,0x40,0x40,0x17,0x16,0x17,0x17,0x17,0x16,0x39,0x0008,0x3C,0x39,0x0008,0x14,0x17,0x16,0x14,0x14,0x17,0x16,0x17,0x3B,0x40,0x3D,0x3B,0x40,0x3E,0x3B,0x40,0x40,0x3D,0x3B,0x40,0x16,0x3B,0x3B,0x40,0x19,0x19,0x20,0x3E,0x3B,0x40,0x3E,0x3B,0x40,0x3E,0x3E,0x14,0x3B,0x40,0x3E,0x3B,0x40,0x3E,0x3E,0x3B,0xD,0x40,0x41,0x2,0x41,0x2,0x6,0x40,0x2,0x41,0x41,0x3B,0x3B,0x3B,0x40,0x1E,0x17,0x14,0x39,0x0008,0x3C,0x39,0x0007,0x14,0x3B,0x40,0x2E,0x2E,0x6,0x6,0x6,0x3C,0x34,0xE,0x3D,0x34,0x34,0x3B,0x40,0x6,0x6,0x2E,0x3D,0x3B,0x40,0x6,0x14,0x3B,0x39,0x0013,0x3D,0x3D,0xE,0xE,0x3D,0x34,0x34,0x3B,0xE,0x3C,0xA,0x4,0xA,0x5,0x40,0x6,0x6,0x3B,0x2E,0x5,0x5,0x34,0x34,0x6,0x3B,0x40,0x30,0x3B,0x40,0xE,0x34,0x34,0x36,0x17,0x17,0x16,0x16,0x16,0x16,0x16,0x16,0x14,0x14,0x3B,0x40,0x40,0x3D,0x3B,0x3B,0x40,0x41,0x2,0x3B,0x40,0x17,0x17,0x40,0x1E,0x17,0x14,0x39,0x0008,0x3C,0x39,0x0007,0x14,0x3B,0x3B,0x38,0x3D,0xB,0x3D,0x3D,0x3D,0x34,0x34,0x40,0x43,0x40,0xC,0xC,0x3C,0x3C,0x34,0x34,0x3E,0x3E,0x38,0x3E,0x3E,0x3E,0x3E,0x42,0x3D,0x3D,0x3B,0x7,0x7,0x3B,0x40,0x3C,0x3C,0x3C,0x34,0x3E,0x3E,0x38,0x3E,0x3E,0x3E,0x3E,0x42,0x3D,0x3D,0x3B,0x7,0x7,0x3B,0x40,0x3D,0x3D,0xC,0xA,0x34,0x34,0x34,0x19,0x19,0x40,0x3E,0x3E,0x3C,0x34,0x34,0x34,0x3B,0xE,0x34,0x34,0x34,0x34,0x34,0x34,0x38,0x42,0x6,0x6,0x3E,0x34,0x34,0x34,0x34,0x7,0x3B,0x3B,0x40,0x6,0x4,0x34,0x34,0x34,0x42,0x40,0x42,0x3B,0x3B,0x40,0x3D,0x3D,0x3E,0x3E,0x3B,0x40,0x3E,0x3E,0x42,0x3B,0x7,0x7,0x39,0x0015,0x7,0x7,0x3B,0x3B,0x40,0x5,0x5,0x3B,0x40,0x5,0x5,0x3B,0x40,0x5,0x5,0x3B,0x3B,0x40,0x17,0x17,0x17,0x17,0x40,0x3E,0x3B,0x3B,0x40,0x40,0x2,0x3C,0x34,0x34,0x34,0x14,0x3B,0x2,0x3B,0x40,0x40,0x3D,0x3B,0x3B,0x40,0x2,0x14,0x3B,0x34,0x34,0x34,0x34,0x7,0x4,0x34,0x34,0x34,0x34,0x34,0x34,0x34,0x3B,0x38,0x40,0x39,0x0004,0x14,0x3B,0x3B,0x34,0x34,0x34,0x34,0x3B};


#else
extern uint8_t pmdf_structure[390];
#endif


#pragma pack(pop)

