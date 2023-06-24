#pragma once
#pragma pack(push,1)
#include "../infiniteStructs.h"
#include <stdint.h>


/** 
  * This file was auto-generated with xml2h.py. DO NOT EDIT!!
  * Edit the XML files instead and regenerate this file.
  * Changes will not persist otherwise!
  */

// Generated from: hirt/sbsp.xml

// Flag Definitions

// Field flags

#define FLAGS_HAS_PROCESSED_PREFAB_INSTANCES (1<<0)
#define FLAGS_COLLISION_GEOMETRY_IS_OVER_DOUBLE_THE_BUDGET (1<<1)
#define FLAGS_PREFAB_PLACEMENTS_LIMIT_EXCEEDED (1<<2)
#define FLAGS_HIDDEN_IOS_HAVE_CHANGED (1<<3)
#define FLAGS_GET_DATA_FROM_HLODS (1<<4)


// Field content_policy_flags

#define CONTENT_POLICY_FLAGS_HAS_WORKING_PATHFINDING (1<<0)
#define CONTENT_POLICY_FLAGS_CONVEX_DECOMPOSITION_ENABLED (1<<1)


// Field failed_content_policy_flags

#define FAILED_CONTENT_POLICY_FLAGS_HAS_WORKING_PATHFINDING (1<<0)
#define FAILED_CONTENT_POLICY_FLAGS_CONVEX_DECOMPOSITION_ENABLED (1<<1)


// Field flags

#define FLAGS_IS_SEAM (1<<0)


// Field flags

#define FLAGS_ABOVE (1<<0)


// Field flags

#define FLAGS_AI_CANT_HEAR_THROUGH_THIS_SHIT (1<<0)
#define FLAGS_ONE_WAY (1<<1)
#define FLAGS_NO_WAY (1<<2)
#define FLAGS_ONE_WAY_REVERSED (1<<3)
#define FLAGS_NO_ONE_CAN_HEAR_THROUGH_THIS (1<<4)


// Field flags

#define FLAGS_CONTAINS_DOUBLE_SIDED_SURFACES (1<<0)


// Field flags

#define FLAGS_TWO_SIDED (1<<0)
#define FLAGS_INVISIBLE (1<<1)
#define FLAGS_CLIMBABLE (1<<2)
#define FLAGS_INVALID (1<<3)
#define FLAGS_CONVEYOR (1<<4)
#define FLAGS_SLIP (1<<5)
#define FLAGS_PLANE_NEGATED (1<<6)


// Field flags

#define FLAGS_RENDERED (1<<0)
#define FLAGS_TANGENT_SPACE (1<<1)
#define FLAGS_NON_CRITICAL (1<<2)
#define FLAGS_LIGHTMAP_LIGHT (1<<3)
#define FLAGS_REPORT_KEY_IS_VALID (1<<4)


// Field flags

#define FLAGS_RENDERED (1<<0)
#define FLAGS_TANGENT_SPACE (1<<1)
#define FLAGS_NON_CRITICAL (1<<2)
#define FLAGS_LIGHTMAP_LIGHT (1<<3)
#define FLAGS_REPORT_KEY_IS_VALID (1<<4)


// Field flags

#define FLAGS_RENDER_ONLY (1<<0)
#define FLAGS_DOES_NOT_BLOCK_AOE_DAMAGE (1<<1)
#define FLAGS_REMOVE_FROM_DYNAMIC_SHADOW_GEOMETRY (1<<2)
#define FLAGS_CINEMA_ONLY (1<<3)
#define FLAGS_EXCLUDE_FROM_CINEMA (1<<4)
#define FLAGS_DISABLE_PLAY_COLLISION (1<<5)
#define FLAGS_DISABLE_BULLET_COLLISION (1<<6)
#define FLAGS_IGNORE_CUBEMAP_VOLUME (1<<7)
#define FLAGS_ALWAYS_GENERATE_FLOATING_SHADOW (1<<8)
#define FLAGS_PVS_ALWAYS_VISIBLE (1<<9)
#define FLAGS_PVS_ALWAYS_USE_LOD_0 (1<<10)
#define FLAGS_PVS_DONT_USE_AS_AN_OCCLUDER (1<<11)
#define FLAGS_EXCLUDE_FROM_INTEL_MAP (1<<12)
#define FLAGS_EXCLUDE_FROM_BROADPHASE_CALCULATION (1<<13)
#define FLAGS_CAN_GENERATE_DECORATORS (1<<14)
#define FLAGS_ISHLOD (1<<15)


// Field flags2

#define FLAGS2_CONTAINS_DECAL_PARTS (1<<0)
#define FLAGS2_NEGATIVE_SCALE (1<<1)
#define FLAGS2_IS_QUICK_DELETED (1<<2)
#define FLAGS2_SUPPORTS_COATINGS (1<<3)
#define FLAGS2_WANTS_HOLOGRAM_OVERRIDE (1<<4)
#define FLAGS2_COATINGS_SETUP_ON_INITIAL_FRAME (1<<5)


// Field mesh_flags_override

#define MESH_FLAGS_OVERRIDE_MESH_HAS_VERTEX_COLOR (1<<0)
#define MESH_FLAGS_OVERRIDE_USE_REGION_INDEX_FOR_SORTING (1<<1)
#define MESH_FLAGS_OVERRIDE_CAN_BE_RENDERED_IN_DRAW_BUNDLES (1<<2)
#define MESH_FLAGS_OVERRIDE_MESH_IS_CUSTOM_SHADOW_CASTER (1<<3)
#define MESH_FLAGS_OVERRIDE_MESH_IS_UNINDEXED_DO_NOT_MODIFY (1<<4)
#define MESH_FLAGS_OVERRIDE_MASH_SHOULD_RENDER_IN_Z_PREPASS (1<<5)
#define MESH_FLAGS_OVERRIDE_USE_UNCOMPRESSED_VERTEX_FORMAT (1<<6)
#define MESH_FLAGS_OVERRIDE_MESH_IS_PCA (1<<7)
#define MESH_FLAGS_OVERRIDE_MESH_HAS_A_USEFUL_SET_OF_SECOND_TEXTURE_COORDS (1<<8)
#define MESH_FLAGS_OVERRIDE_MESH_HAS_A_USEFUL_SET_OF_THIRD_TEXTURE_COORDS (1<<9)
#define MESH_FLAGS_OVERRIDE_USE_UV3_TANGENT_ROTATION (1<<10)


// Field flags

#define FLAGS_RENDER_ONLY (1<<0)
#define FLAGS_DOES_NOT_BLOCK_AOE_DAMAGE (1<<1)
#define FLAGS_REMOVE_FROM_DYNAMIC_SHADOW_GEOMETRY (1<<2)
#define FLAGS_CINEMA_ONLY (1<<3)
#define FLAGS_EXCLUDE_FROM_CINEMA (1<<4)
#define FLAGS_DISABLE_PLAY_COLLISION (1<<5)
#define FLAGS_DISABLE_BULLET_COLLISION (1<<6)
#define FLAGS_IGNORE_CUBEMAP_VOLUME (1<<7)
#define FLAGS_ALWAYS_GENERATE_FLOATING_SHADOW (1<<8)
#define FLAGS_PVS_ALWAYS_VISIBLE (1<<9)
#define FLAGS_PVS_ALWAYS_USE_LOD_0 (1<<10)
#define FLAGS_PVS_DONT_USE_AS_AN_OCCLUDER (1<<11)
#define FLAGS_EXCLUDE_FROM_INTEL_MAP (1<<12)
#define FLAGS_EXCLUDE_FROM_BROADPHASE_CALCULATION (1<<13)
#define FLAGS_CAN_GENERATE_DECORATORS (1<<14)
#define FLAGS_ISHLOD (1<<15)


// Field flags2

#define FLAGS2_CONTAINS_DECAL_PARTS (1<<0)
#define FLAGS2_NEGATIVE_SCALE (1<<1)
#define FLAGS2_IS_QUICK_DELETED (1<<2)
#define FLAGS2_SUPPORTS_COATINGS (1<<3)
#define FLAGS2_WANTS_HOLOGRAM_OVERRIDE (1<<4)
#define FLAGS2_COATINGS_SETUP_ON_INITIAL_FRAME (1<<5)


// Field mesh_flags_override

#define MESH_FLAGS_OVERRIDE_MESH_HAS_VERTEX_COLOR (1<<0)
#define MESH_FLAGS_OVERRIDE_USE_REGION_INDEX_FOR_SORTING (1<<1)
#define MESH_FLAGS_OVERRIDE_CAN_BE_RENDERED_IN_DRAW_BUNDLES (1<<2)
#define MESH_FLAGS_OVERRIDE_MESH_IS_CUSTOM_SHADOW_CASTER (1<<3)
#define MESH_FLAGS_OVERRIDE_MESH_IS_UNINDEXED_DO_NOT_MODIFY (1<<4)
#define MESH_FLAGS_OVERRIDE_MASH_SHOULD_RENDER_IN_Z_PREPASS (1<<5)
#define MESH_FLAGS_OVERRIDE_USE_UNCOMPRESSED_VERTEX_FORMAT (1<<6)
#define MESH_FLAGS_OVERRIDE_MESH_IS_PCA (1<<7)
#define MESH_FLAGS_OVERRIDE_MESH_HAS_A_USEFUL_SET_OF_SECOND_TEXTURE_COORDS (1<<8)
#define MESH_FLAGS_OVERRIDE_MESH_HAS_A_USEFUL_SET_OF_THIRD_TEXTURE_COORDS (1<<9)
#define MESH_FLAGS_OVERRIDE_USE_UV3_TANGENT_ROTATION (1<<10)


// Field m_typeMask

#define M_TYPEMASK_BULLET (1<<0)
#define M_TYPEMASK_PLAY (1<<1)
#define M_TYPEMASK_INVISIBLEWALL (1<<2)
#define M_TYPEMASK_RENDER (1<<3)


// Field flags

#define FLAGS_ALLOW_DECALS (1<<0)


// Field errors

#define ERRORS_MULTIPLE_FOG_PLANES (1<<0)
#define ERRORS_FOG_ZONE_COLLISION (1<<1)
#define ERRORS_FOG_ZONE_IMMERSION (1<<2)


// Field warnings

#define WARNINGS_MULTIPLE_VISIBLE_FOG_PLANES (1<<0)
#define WARNINGS_VISIBLE_FOG_CLUSTER_OMISSION (1<<1)
#define WARNINGS_FOG_PLANE_MISSED_RENDER_BSP (1<<2)


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


// Field flags

#define FLAGS_CONTAINS_DOUBLE_SIDED_SURFACES (1<<0)


// Field flags

#define FLAGS_TWO_SIDED (1<<0)
#define FLAGS_INVISIBLE (1<<1)
#define FLAGS_CLIMBABLE (1<<2)
#define FLAGS_INVALID (1<<3)
#define FLAGS_CONVEYOR (1<<4)
#define FLAGS_SLIP (1<<5)
#define FLAGS_PLANE_NEGATED (1<<6)


// Field flags

#define FLAGS_CONTAINS_DOUBLE_SIDED_SURFACES (1<<0)


// Field flags

#define FLAGS_TWO_SIDED (1<<0)
#define FLAGS_INVISIBLE (1<<1)
#define FLAGS_CLIMBABLE (1<<2)
#define FLAGS_INVALID (1<<3)
#define FLAGS_CONVEYOR (1<<4)
#define FLAGS_SLIP (1<<5)
#define FLAGS_PLANE_NEGATED (1<<6)


// Field flags

#define FLAGS_CONTAINS_DOUBLE_SIDED_SURFACES (1<<0)


// Field flags

#define FLAGS_TWO_SIDED (1<<0)
#define FLAGS_INVISIBLE (1<<1)
#define FLAGS_CLIMBABLE (1<<2)
#define FLAGS_INVALID (1<<3)
#define FLAGS_CONVEYOR (1<<4)
#define FLAGS_SLIP (1<<5)
#define FLAGS_PLANE_NEGATED (1<<6)


// Field flags

#define FLAGS_CONTAINS_DOUBLE_SIDED_SURFACES (1<<0)


// Field flags

#define FLAGS_TWO_SIDED (1<<0)
#define FLAGS_INVISIBLE (1<<1)
#define FLAGS_CLIMBABLE (1<<2)
#define FLAGS_INVALID (1<<3)
#define FLAGS_CONVEYOR (1<<4)
#define FLAGS_SLIP (1<<5)
#define FLAGS_PLANE_NEGATED (1<<6)


// Field override_flags

#define OVERRIDE_FLAGS_RENDER_ONLY (1<<0)
#define OVERRIDE_FLAGS_DOES_NOT_BLOCK_AOE_DAMAGE (1<<1)
#define OVERRIDE_FLAGS_REMOVE_FROM_DYNAMIC_SHADOW_GEOMETRY (1<<2)
#define OVERRIDE_FLAGS_CINEMA_ONLY (1<<3)
#define OVERRIDE_FLAGS_EXCLUDE_FROM_CINEMA (1<<4)
#define OVERRIDE_FLAGS_DISABLE_PLAY_COLLISION (1<<5)
#define OVERRIDE_FLAGS_DISABLE_BULLET_COLLISION (1<<6)
#define OVERRIDE_FLAGS_IGNORE_CUBEMAP_VOLUME (1<<7)
#define OVERRIDE_FLAGS_ALWAYS_GENERATE_FLOATING_SHADOW (1<<8)
#define OVERRIDE_FLAGS_PVS_ALWAYS_VISIBLE (1<<9)
#define OVERRIDE_FLAGS_PVS_ALWAYS_USE_LOD_0 (1<<10)
#define OVERRIDE_FLAGS_PVS_DONT_USE_AS_AN_OCCLUDER (1<<11)
#define OVERRIDE_FLAGS_EXCLUDE_FROM_INTEL_MAP (1<<12)
#define OVERRIDE_FLAGS_EXCLUDE_FROM_BROADPHASE_CALCULATION (1<<13)
#define OVERRIDE_FLAGS_CAN_GENERATE_DECORATORS (1<<14)
#define OVERRIDE_FLAGS_ISHLOD (1<<15)


// Field instance_flags_Mask

#define INSTANCE_FLAGS_MASK_RENDER_ONLY (1<<0)
#define INSTANCE_FLAGS_MASK_DOES_NOT_BLOCK_AOE_DAMAGE (1<<1)
#define INSTANCE_FLAGS_MASK_REMOVE_FROM_DYNAMIC_SHADOW_GEOMETRY (1<<2)
#define INSTANCE_FLAGS_MASK_CINEMA_ONLY (1<<3)
#define INSTANCE_FLAGS_MASK_EXCLUDE_FROM_CINEMA (1<<4)
#define INSTANCE_FLAGS_MASK_DISABLE_PLAY_COLLISION (1<<5)
#define INSTANCE_FLAGS_MASK_DISABLE_BULLET_COLLISION (1<<6)
#define INSTANCE_FLAGS_MASK_IGNORE_CUBEMAP_VOLUME (1<<7)
#define INSTANCE_FLAGS_MASK_ALWAYS_GENERATE_FLOATING_SHADOW (1<<8)
#define INSTANCE_FLAGS_MASK_PVS_ALWAYS_VISIBLE (1<<9)
#define INSTANCE_FLAGS_MASK_PVS_ALWAYS_USE_LOD_0 (1<<10)
#define INSTANCE_FLAGS_MASK_PVS_DONT_USE_AS_AN_OCCLUDER (1<<11)
#define INSTANCE_FLAGS_MASK_EXCLUDE_FROM_INTEL_MAP (1<<12)
#define INSTANCE_FLAGS_MASK_EXCLUDE_FROM_BROADPHASE_CALCULATION (1<<13)
#define INSTANCE_FLAGS_MASK_CAN_GENERATE_DECORATORS (1<<14)
#define INSTANCE_FLAGS_MASK_ISHLOD (1<<15)


// Field physics_override_flags

#define PHYSICS_OVERRIDE_FLAGS_ALLOW_DECALS (1<<0)


// Field physics_instance_flags_Mask

#define PHYSICS_INSTANCE_FLAGS_MASK_ALLOW_DECALS (1<<0)


// Field instance_policy_mask

#define INSTANCE_POLICY_MASK_OVERRIDE_PATHFINDING_POLICY (1<<0)


// Field placementFlags

#define PLACEMENTFLAGS_IS_HLOD (1<<0)


// Field flags

#define FLAGS_DELETE_BIT (1<<0)
#define FLAGS_ADJUSTED_BIT (1<<1)
#define FLAGS_APPROXIMATED_POSITION_BIT (1<<2)


// Field render_flags

#define RENDER_FLAGS_HAS_COATINGS (1<<0)
#define RENDER_FLAGS_COATINGS_ARE_FINALIZED (1<<1)
#define RENDER_FLAGS_DISABLE_GPU_SUBMISSION (1<<2)




// Enum Definitions

// Enum marker_type

enum marker_type_enum {
    MARKER_TYPE_NONE,
    MARKER_TYPE_FALLING_LEAF_GENERATOR,
    MARKER_TYPE_SKY_UNUSED,
    MARKER_TYPE_MODEL
};

// Enum report_type

enum report_type_enum {
    REPORT_TYPE_SILENT,
    REPORT_TYPE_COMMENT,
    REPORT_TYPE_WARNING,
    REPORT_TYPE_ERROR
};

// Enum type

enum type_enum {
    TYPE_SILENT,
    TYPE_COMMENT,
    TYPE_WARNING,
    TYPE_ERROR
};

// Enum source

enum source_enum {
    SOURCE_NONE,
    SOURCE_STRUCTURE,
    SOURCE_POOP,
    SOURCE_LIGHTMAP,
    SOURCE_PATHFINDING
};

// Enum pathfinding_policy

enum pathfinding_policy_enum {
    PATHFINDING_POLICY_CUT_OUT,
    PATHFINDING_POLICY_STATIC,
    PATHFINDING_POLICY_NONE
};

// Enum streaming_priority

enum streaming_priority_enum {
    STREAMING_PRIORITY_DEFAULT,
    STREAMING_PRIORITY_HIGHER,
    STREAMING_PRIORITY_HIGHEST
};

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

// Enum override_pathfinding_policy

enum override_pathfinding_policy_enum {
    OVERRIDE_PATHFINDING_POLICY_CUT_OUT,
    OVERRIDE_PATHFINDING_POLICY_STATIC,
    OVERRIDE_PATHFINDING_POLICY_NONE
};

// Enum override_streaming_priority

enum override_streaming_priority_enum {
    OVERRIDE_STREAMING_PRIORITY_DEFAULT,
    OVERRIDE_STREAMING_PRIORITY_HIGHER,
    OVERRIDE_STREAMING_PRIORITY_HIGHEST
};

// Enum instance_type

enum instance_type_enum {
    INSTANCE_TYPE_DEFAULT,
    INSTANCE_TYPE_FOLIAGE
};



// Structs

struct edge_mapping{
    uint32_t structure_edge_index;
};


struct cluster_mapping{
    uint32_t cluster_index;
    struct point3D cluster_center;
};


struct seam_identifiers{
    struct seams_identifier{
        uint32_t seam_id0;
        uint32_t seam_id1;
        uint32_t seam_id2;
        uint32_t seam_id3;
    };
    struct seams_identifier seams_identifier_ent;
    struct tagBlock<edge_mapping> edge_mapping_ent;
    struct tagBlock<cluster_mapping> cluster_mapping_ent;
};


struct collision_materials{
    shortBlockIndex conveyor_surface_index;
    shortBlockIndex seam_mapping_index;
    uint16_t flags_flags;
};


struct leaves{
    uint8_t cluster;
};


struct super_node_parent_mappings{
    uint16_t parent_super_node_index;
    uint8_t parent_internal_node_index;
    uint8_t flags_flags;
    uint32_t has_traversal_geometry_mask;
    shortBlockIndex first_traversal_geometry_index;
    shortBlockIndex first_aabb_index;
    uint32_t aabb_mask;
    shortBlockIndex non_terminal_traversal_geometry_index;
    uint16_t generated_pad5df5;
};


struct super_node_recursable_masks{
    uint16_t mask;
};


struct portal_indices{
    uint16_t index;
};


struct seam_indices{
    uint16_t index;
};


struct structure_super_node_traversal_geometry_block{
    struct tagBlock<portal_indices> portal_indices_ent;
    struct tagBlock<seam_indices> seam_indices_ent;
};


struct vertices{
    struct point3D point;
};


struct cluster_portals{
    struct oriented_bounds{
        struct point3D center;
        struct vector3D extents;
        realQuaternion orientation;
    };
    struct oriented_bounds oriented_bounds_ent;
    uint16_t back_cluster;
    uint16_t front_cluster;
    uint32_t plane_index;
    struct point3D centroid;
    float bounding_radius;
    uint32_t flags_flags;
    struct tagBlock<vertices> vertices_ent;
};


struct portals{
    uint16_t portal_index;
};




struct instances_Data_Block{
    uint16_t instance_index;
};


struct instance_Buckets_Block{
    uint32_t runtime_geo_mesh_index;
    struct tagReference runtime_geo_tag_reference;
    uint32_t pad;
    struct tagBlock<instances_Data_Block> instances_Data_Block_ent;
    uint32_t instances_Data_Block_Flags;
    uint32_t instances_Data_Block_Vector1;
    uint32_t instances_Data_Block_Vector2;
};


struct clusters{
    // EXPLANATION: CLUSTER_INFO
    realBounds bounds_x;
    realBounds bounds_y;
    realBounds bounds_z;
    struct tagBlock<portals> portals_ent;
    uint16_t mesh_index;
    uint16_t instance_imposter_cluster_mopp_index;
    struct tagBlock<seam_indices> seam_indices_ent;
    struct tagBlock<instance_Buckets_Block> instance_Buckets_Block_ent;
    uint32_t instance_Buckets_Flags;
    uint32_t instance_Buckets_Vector1;
    uint32_t instance_Buckets_Vector2;
};


struct bsp3d_nodes{
    uint64_t node_data_designator;
};


struct bsp3d_supernodes{
    float plane_0;
    float plane_1;
    float plane_2;
    float plane_3;
    float plane_4;
    float plane_5;
    float plane_6;
    float plane_7;
    float plane_8;
    float plane_9;
    float plane10;
    float plane11;
    float plane12;
    float plane13;
    float plane14;
    uint32_t plane_dimensions;
    uint32_t child_index_0;
    uint32_t child_index_1;
    uint32_t child_index_2;
    uint32_t child_index_3;
    uint32_t child_index_4;
    uint32_t child_index_5;
    uint32_t child_index_6;
    uint32_t child_index_7;
    uint32_t child_index_8;
    uint32_t child_index_9;
    uint32_t child_index10;
    uint32_t child_index11;
    uint32_t child_index12;
    uint32_t child_index13;
    uint32_t child_index14;
    uint32_t child_index15;
};


struct planes{
    realPlane3D plane;
};




struct bsp2d_references{
    uint16_t plane;
    uint16_t bsp2d_node;
};


struct bsp2d_nodes{
    realPlane2D plane;
    uint16_t left_child;
    uint16_t right_child;
};


struct surfaces{
    uint16_t plane_index;
    uint16_t first_edge;
    uint16_t material;
    uint8_t flags_flags;
    uint8_t best_plane_calculation_vertex_index_;
};


struct edges{
    uint16_t start_vertex;
    uint16_t end_vertex;
    uint16_t forward_edge;
    uint16_t reverse_edge;
    uint16_t left_surface;
    uint16_t right_surface;
};




struct cookie_cutters{
    // CUSTOM: Cookie_Cutter
    struct collision_model{
        struct tagBlock<bsp3d_nodes> bsp3d_nodes_ent;
        struct tagBlock<bsp3d_supernodes> bsp3d_supernodes_ent;
        struct tagBlock<planes> planes_ent;
        struct tagBlock<leaves> leaves_ent;
        struct tagBlock<bsp2d_references> bsp2d_references_ent;
        struct tagBlock<bsp2d_nodes> bsp2d_nodes_ent;
        struct tagBlock<surfaces> surfaces_ent;
        struct tagBlock<edges> edges_ent;
        struct tagBlock<vertices> vertices_ent;
    };
    struct collision_model collision_model_ent;
    // CUSTOM: 
};


struct markers{
    uint8_t enum_marker_type;
    char marker_parameter[32];
    uint8_t generated_padbec6;
    uint16_t generated_padbec6_2;
    realQuaternion rotation;
    struct point3D position;
};




struct faces{
    uint32_t node_index;
    struct tagBlock<vertices> vertices_ent;
};


struct connection_indices{
    uint32_t connection_index;
};


struct leaf_map_leaves{
    struct tagBlock<faces> faces_ent;
    struct tagBlock<connection_indices> connection_indices_ent;
};




struct leaf_map_connections{
    uint32_t plane_index;
    uint32_t back_leaf_index;
    uint32_t front_leaf_index;
    struct tagBlock<vertices> vertices_ent;
    float area;
};




struct vectors{
    struct point{
        struct point3D position;
// Array with 4 elements
        uint8_t node_index[4];
// Array with 4 elements
        float node_weight[4];
    };
    struct point point_ent;
    realARGBColor color;
    struct vector3D normal;
    float screen_length;
};


struct lines{
// Array with 2 elements
    struct point{
        struct point3D position;
// Array with 4 elements
        uint8_t node_index[4];
// Array with 4 elements
        float node_weight[4];
    };
    struct point point_ent[2];
    realARGBColor color;
};


struct triangles{
// Array with 3 elements
    struct point{
        struct point3D position;
// Array with 4 elements
        uint8_t node_index[4];
// Array with 4 elements
        float node_weight[4];
    };
    struct point point_ent[3];
    realARGBColor color;
};


struct quads{
// Array with 4 elements
    struct point{
        struct point3D position;
// Array with 4 elements
        uint8_t node_index[4];
// Array with 4 elements
        float node_weight[4];
    };
    struct point point_ent[4];
    realARGBColor color;
};


struct comments{
    struct dataReference text;
    struct point{
        struct point3D position;
// Array with 4 elements
        uint8_t node_index[4];
// Array with 4 elements
        float node_weight[4];
    };
    struct point point_ent;
    realARGBColor color;
};


struct reports{
    uint8_t enum_type;
    uint8_t enum_source;
    uint16_t flags_flags;
    struct dataReference text;
    uint32_t source_identifier;
    char source_filename[32];
    uint32_t source_line_number;
    struct tagBlock<vertices> vertices_ent;
    struct tagBlock<vectors> vectors_ent;
    struct tagBlock<lines> lines_ent;
    struct tagBlock<triangles> triangles_ent;
    struct tagBlock<quads> quads_ent;
    struct tagBlock<comments> comments_ent;
    uint32_t report_key;
    uint32_t node_index;
    realBounds bounds_x;
    realBounds bounds_y;
    realBounds bounds_z;
    realARGBColor color;
};


struct errors{
    char name[256];
    uint8_t enum_report_type;
    uint8_t generated_padf276;
    uint16_t flags_flags;
    uint16_t runtime_generation_flags;
    uint16_t generated_pad3f2b;
    uint32_t runtime_something;
    struct tagBlock<reports> reports_ent;
};


struct Lod_Levels_Block{
    float lodTransitionDistance;
};


struct per_Instance_Material_Block{
    struct tagReference material;
};


struct instanced_geometry_instances{
    struct vector3D scale;
    struct vector3D forward;
    struct vector3D left;
    struct vector3D up;
    struct point3D position;
    struct tagReference Runtime_geo_mesh_reference;
    struct tagReference Foliage_material_palette_reference;
    uint16_t Runtime_geo_mesh_index;
    uint16_t unique_io_index;
    uint16_t flags_flags;
    uint16_t generated_pad89b2;
    float bounds_x0;
    float bounds_x1;
    float bounds_y0;
    float bounds_y1;
    float bounds_z0;
    float bounds_z1;
    struct point3D world_bounding_sphere_center;
    float world_bounding_sphere_radius;
    uint32_t generated_padd667;
    uint64_t Placement_Checksum;
    uint8_t enum_pathfinding_policy;
    uint8_t enum_streaming_priority;
    uint16_t flags_flags2;
    uint16_t hlod_index;
    uint16_t generated_pad231c;
    struct lod_Overrides{
        struct tagBlock<Lod_Levels_Block> Lod_Levels_Block_ent;
        uint32_t Lod_Levels_Block_Flags;
        uint32_t Lod_Levels_Block_Vector1;
        uint32_t Lod_Levels_Block_Vector2;
        float lod_fade_after_Distance;
    };
    struct lod_Overrides lod_Overrides_ent;
    string_id style_id;
    uint32_t damage_style_index;
    uint32_t generated_pad6fd1;
    uint64_t style_tag_override_data;
    struct material_override_data{
        struct tagBlock<per_Instance_Material_Block> per_Instance_Material_Block_ent;
        uint32_t per_Instance_Material_Flags;
        uint32_t per_Instance_Material_Vector1;
        uint32_t per_Instance_Material_Vector2;
        uint16_t flags_mesh_flags_override;
        uint16_t generated_pad58dd;
    };
    struct material_override_data material_override_data_ent;
    struct point3D rectMin;
    struct point3D rectMax;
    uint32_t external_guid;
    uint64_t coating_entry;
    uint64_t editorData;
};






struct instanced_foliage_instances{
    struct vector3D scale;
    struct vector3D forward;
    struct vector3D left;
    struct vector3D up;
    struct point3D position;
    struct tagReference Runtime_geo_mesh_reference;
    struct tagReference Foliage_material_palette_reference;
    uint16_t Runtime_geo_mesh_index;
    uint16_t unique_io_index;
    uint16_t flags_flags;
    uint16_t generated_pad89b2;
    float bounds_x0;
    float bounds_x1;
    float bounds_y0;
    float bounds_y1;
    float bounds_z0;
    float bounds_z1;
    struct point3D world_bounding_sphere_center;
    float world_bounding_sphere_radius;
    uint32_t generated_padd667;
    uint64_t Placement_Checksum;
    uint8_t enum_pathfinding_policy;
    uint8_t enum_streaming_priority;
    uint16_t flags_flags2;
    uint16_t hlod_index;
    uint16_t generated_pad231c;
    struct lod_Overrides{
        struct tagBlock<Lod_Levels_Block> Lod_Levels_Block_ent;
        uint32_t Lod_Levels_Block_Flags;
        uint32_t Lod_Levels_Block_Vector1;
        uint32_t Lod_Levels_Block_Vector2;
        float lod_fade_after_Distance;
    };
    struct lod_Overrides lod_Overrides_ent;
    string_id style_id;
    uint32_t damage_style_index;
    uint32_t generated_pad6fd1;
    uint64_t style_tag_override_data;
    struct material_override_data{
        struct tagBlock<per_Instance_Material_Block> per_Instance_Material_Block_ent;
        uint32_t per_Instance_Material_Flags;
        uint32_t per_Instance_Material_Vector1;
        uint32_t per_Instance_Material_Vector2;
        uint16_t flags_mesh_flags_override;
        uint16_t generated_pad58dd;
    };
    struct material_override_data material_override_data_ent;
    struct point3D rectMin;
    struct point3D rectMax;
    uint32_t external_guid;
    uint64_t coating_entry;
    uint64_t editorData;
};




struct instanced_physics_instances{
    struct tagReference m_collisionTagReference;
    struct tagBlock<instanced_physics_instances> instanced_physics_instances_ent;
    uint32_t instanced_physics_instances_Flags;
    uint32_t instanced_physics_instances_Vector1;
    uint32_t instanced_physics_instances_Vector2;
    struct vector3D Scale;
    struct vector3D Forward;
    struct vector3D Left;
    struct vector3D Up;
    struct point3D Position;
    uint32_t flags_m_typeMask;
    uint32_t m_guid;
// Array with 4 elements
    uint32_t havok_body_ID[4];
    uint8_t flags_flags;
    uint32_t generated_pad119d;
    uint16_t generated_pad119d_2;
    uint8_t generated_pad119d_3;
    uint64_t m_scene;
};




struct fog_plane_indices{
    uint32_t index;
};


struct visible_fog_plane_indices{
    uint32_t index;
};


struct vis_fog_omission_cluster_indices{
    uint32_t index;
};


struct containing_fog_zone_indices{
    uint32_t index;
};






struct intersected_cluster_indices{
    uint32_t index;
};


struct inf_extent_cluster_indices{
    uint32_t index;
};


struct fog_planes{
    uint32_t fog_zone_index;
    uint32_t connected_plane_designator;
    struct tagBlock<lines> lines_ent;
    struct tagBlock<intersected_cluster_indices> intersected_cluster_indices_ent;
    struct tagBlock<inf_extent_cluster_indices> inf_extent_cluster_indices_ent;
};




struct immersed_cluster_indices{
    uint32_t index;
};


struct bounding_fog_plane_indices{
    uint32_t index;
};


struct collision_fog_plane_indices{
    uint32_t index;
};


struct fog_zones{
    uint32_t media_index;
    uint32_t base_fog_plane_index;
    struct tagBlock<lines> lines_ent;
    struct tagBlock<immersed_cluster_indices> immersed_cluster_indices_ent;
    struct tagBlock<bounding_fog_plane_indices> bounding_fog_plane_indices_ent;
    struct tagBlock<collision_fog_plane_indices> collision_fog_plane_indices_ent;
};


struct debug_info{
    struct tagBlock<clusters> clusters_ent;
    struct tagBlock<fog_planes> fog_planes_ent;
    struct tagBlock<fog_zones> fog_zones_ent;
};


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


struct widget_references{
    uint16_t marker_index;
    uint16_t generated_pad3469;
    struct tagReference widget_ref;
};




















struct collision_bsp{
    struct tagBlock<bsp3d_nodes> bsp3d_nodes_ent;
    struct tagBlock<bsp3d_supernodes> bsp3d_supernodes_ent;
    struct tagBlock<planes> planes_ent;
    struct tagBlock<leaves> leaves_ent;
    struct tagBlock<bsp2d_references> bsp2d_references_ent;
    struct tagBlock<bsp2d_nodes> bsp2d_nodes_ent;
    struct tagBlock<surfaces> surfaces_ent;
    struct tagBlock<edges> edges_ent;
    struct tagBlock<vertices> vertices_ent;
};




















struct large_collision_bsp{
    struct tagBlock<bsp3d_nodes> bsp3d_nodes_ent;
    struct tagBlock<bsp3d_supernodes> bsp3d_supernodes_ent;
    struct tagBlock<planes> planes_ent;
    struct tagBlock<leaves> leaves_ent;
    struct tagBlock<bsp2d_references> bsp2d_references_ent;
    struct tagBlock<bsp2d_nodes> bsp2d_nodes_ent;
    struct tagBlock<surfaces> surfaces_ent;
    struct tagBlock<edges> edges_ent;
    struct tagBlock<vertices> vertices_ent;
};


struct raw_resources{
    struct raw_items{
        struct tagBlock<collision_bsp> collision_bsp_ent;
        struct tagBlock<large_collision_bsp> large_collision_bsp_ent;
    };
    struct raw_items raw_items_ent;
};










































struct tag_resources{
    struct resource_items{
        struct tagBlock<collision_bsp> collision_bsp_ent;
        struct tagBlock<large_collision_bsp> large_collision_bsp_ent;
    };
    struct resource_items resource_items_ent;
};


struct instance_material_overrides{
    struct tagReference Original_material_ref;
    struct tagReference Override_material_ref;
};


struct material_overrides{
    struct tagReference Original_material_ref;
    struct tagReference Override_material_ref;
};


struct external_references{
    struct tagReference static_render_geometry;
    struct tagReference static_collision_geometry;
    struct tagReference material_palette;
    string_id name;
    string_id material_override_variant_name;
    struct vector3D scale;
    struct vector3D forward;
    struct vector3D left;
    struct vector3D up;
    struct point3D position;
    uint16_t flags_override_flags;
    uint16_t flags_instance_flags_Mask;
    uint8_t flags_physics_override_flags;
    uint8_t flags_physics_instance_flags_Mask;
    uint8_t enum_override_pathfinding_policy;
    uint8_t enum_override_streaming_priority;
    uint16_t flags_instance_policy_mask;
    uint16_t generated_pad81ce;
// Array with 16 elements
    float LOD_Transition_Distance_Override[16];
    float LOD_fade_after_override;
    uint32_t enum_instance_type;
    uint32_t guid;
    uint32_t hlodIndex;
    uint16_t flags_placementFlags;
    uint16_t generated_padce83;
    string_id styleId;
    uint32_t generated_pad1b38;
    uint64_t styleTagOverride;
    struct tagBlock<instance_material_overrides> instance_material_overrides_ent;
    struct tagBlock<material_overrides> material_overrides_ent;
};


struct obb_volume_list{
    struct point3D origin;
    struct vector3D axis_1;
    struct vector3D axis_2;
    struct vector3D axis_3;
    uint32_t type;
};


struct bitmaps{
    struct tagReference bitmap;
};


struct StreamingBitmapScale_Block{
    uint32_t bitmap_index_in_bsp;
    float scale;
};


struct PerLodBitmaps_Block{
    struct tagBlock<StreamingBitmapScale_Block> StreamingBitmapScale_Block_ent;
    uint32_t StreamingBitmapScale_Block_Flags;
    uint32_t StreamingBitmapScale_Block_Vector1;
    uint32_t StreamingBitmapScale_Block_Vector2;
};


struct uniqueIos{
    struct tagBlock<PerLodBitmaps_Block> PerLodBitmaps_Block_ent;
    uint32_t PerLodBitmaps_Block_Flags;
    uint32_t PerLodBitmaps_Block_Vector1;
    uint32_t PerLodBitmaps_Block_Vector2;
    uint16_t io_index;
    uint16_t generated_pad5360;
};






struct uniqueFoliage{
    struct tagBlock<PerLodBitmaps_Block> PerLodBitmaps_Block_ent;
    uint32_t PerLodBitmaps_Block_Flags;
    uint32_t PerLodBitmaps_Block_Vector1;
    uint32_t PerLodBitmaps_Block_Vector2;
    uint16_t io_index;
    uint16_t generated_pad5360;
};


struct decorator_placements{
    struct point3D position;
    uint8_t type_index;
    uint8_t motion_scale;
    uint8_t ground_tint;
    uint8_t flags_flags;
    realQuaternion rotation;
    float scale;
    struct point3D tint_color;
    struct point3D original_point;
    struct point3D original_normal;
    uint32_t extra;
    uint16_t placement_surface_albedo;
    uint16_t placement_surface_normal;
};


struct decorator_sets{
    struct tagReference decorator_asset;
    struct tagBlock<decorator_placements> decorator_placements_ent;
    struct tagReference owning_layer_default_bsp;
};


struct sets{
    struct tagReference decorator_asset;
    uint32_t offset;
    uint32_t count;
    uint8_t set_type_index;
    uint8_t generated_pad961e;
    uint16_t generated_pad961e_2;
};




struct decorator_runtime{
    struct tagBlock<sets> sets_ent;
    struct tagBlock<clusters> clusters_ent;
    uint32_t bspIndex;
    uint32_t generated_pad92da;
    uint64_t decorator_runtime_gpu;
    uint64_t decorator_runtime_cpu;
};


// Root Block

struct sbsp{
    struct anon_struct_0{
        uint64_t vtable_space;
        struct internal_struct{
            uint32_t global_tag_ID;
            uint32_t local_tag_handle;
        };
        struct internal_struct internal_struct_ent;
    };
    struct anon_struct_0 anon_struct_0_ent;
    struct build_identifier{
        uint32_t manifest_id0;
        uint32_t manifest_id1;
        uint32_t manifest_id2;
        uint32_t manifest_id3;
        uint32_t build_index;
        uint32_t structure_importer_version;
    };
    struct build_identifier build_identifier_ent;
    struct parent_build_identifier{
        uint32_t manifest_id0;
        uint32_t manifest_id1;
        uint32_t manifest_id2;
        uint32_t manifest_id3;
        uint32_t build_index;
        uint32_t structure_importer_version;
    };
    struct parent_build_identifier parent_build_identifier_ent;
    uint32_t import_info_checksum;
    uint32_t import_version;
    struct tagReference owner_level;
    struct tagReference structure_meta_data;
    uint16_t flags_flags;
    uint16_t flags_content_policy_flags;
    uint16_t flags_failed_content_policy_flags;
    uint16_t generated_pad7169;
    struct tagBlock<seam_identifiers> seam_identifiers_ent;
    struct tagBlock<collision_materials> collision_materials_ent;
    struct tagBlock<leaves> leaves_ent;
    struct tagBlock<super_node_parent_mappings> super_node_parent_mappings_ent;
    struct tagBlock<super_node_recursable_masks> super_node_recursable_masks_ent;
    struct tagBlock<structure_super_node_traversal_geometry_block> structure_super_node_traversal_geometry_block_ent;
    realBounds world_bounds_x;
    realBounds world_bounds_y;
    realBounds world_bounds_z;
    struct tagBlock<cluster_portals> cluster_portals_ent;
    struct tagBlock<clusters> clusters_ent;
    struct tagBlock<cookie_cutters> cookie_cutters_ent;
    struct tagBlock<markers> markers_ent;
    struct tagBlock<leaf_map_leaves> leaf_map_leaves_ent;
    struct tagBlock<leaf_map_connections> leaf_map_connections_ent;
    struct tagBlock<errors> errors_ent;
    struct tagBlock<instanced_geometry_instances> instanced_geometry_instances_ent;
    uint32_t instanced_geometry_instances_Flags;
    uint32_t instanced_geometry_instances_Vector1;
    uint32_t instanced_geometry_instances_Vector2;
    struct tagBlock<instanced_foliage_instances> instanced_foliage_instances_ent;
    uint32_t instanced_foliage_instances_Flags;
    uint32_t instanced_foliage_instances_Vector1;
    uint32_t instanced_foliage_instances_Vector2;
    struct tagBlock<instanced_physics_instances> instanced_physics_instances_ent;
    uint32_t instanced_physics_instances_Flags;
    uint32_t instanced_physics_instances_Vector1;
    uint32_t instanced_physics_instances_Vector2;
    uint32_t Instance_Geometry_Tag_Instance_Count;
    uint64_t Instance_Postprocess_Checksum;
    struct tagBlock<debug_info> debug_info_ent;
    uint32_t generated_pad5788;
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
    struct tagBlock<widget_references> widget_references_ent;
    struct resource_interface{
        struct tagBlock<raw_resources> raw_resources_ent;
        struct externalResource<tag_resources> tag_resources_res;
        uint32_t use_resource_items;
    };
    struct resource_interface resource_interface_ent;
    struct tagBlock<external_references> external_references_ent;
    uint32_t base_material_count;
    struct tagBlock<obb_volume_list> obb_volume_list_ent;
    uint64_t m_instanceGroupPipelineStateCache;
    struct dataReference growable_dataof;
    uint64_t heap_array_pointer;
    uint32_t heap_current_size;
    uint32_t active_growth_state;
    uint64_t instanceData;
    uint64_t instanceBufferConstants;
    uint64_t ioPlacementGpuTestingBuffer;
    uint64_t ioLodStaticInfoBuffer;
    uint64_t ioLodIndexBuffer;
    uint64_t ioLodTransitionsOffsets;
    struct activeIoBitfield{
        uint64_t Bsp_Structure_Bitfield_Buffer;
// Array with 1024 elements
        uint32_t chunk[1024];
    };
    struct activeIoBitfield activeIoBitfield_ent;
    uint64_t newlyVisibleIoBitfieldBuffer;
    uint64_t ioPlacementLodInfoBuffer;
    struct tagReference acoustics_data;
    uint32_t number_of_IO_over_the_limit;
    uint32_t needToClearShadowSubmissionsBuffers;
    uint32_t generated_pad0ad3;
    uint64_t gpuFloatingShadowSubmissionData;
    uint64_t BSPRuntimeData;
    uint64_t View_GPU_Submission_Data;
// Array with 1024 elements
    uint32_t chunk[1024];
    uint64_t Raytracing_Submission_Data;
    struct tagBlock<bitmaps> bitmaps_ent;
    uint32_t bitmaps_Flags;
    uint32_t bitmaps_Vector1;
    uint32_t bitmaps_Vector2;
    struct tagBlock<uniqueIos> uniqueIos_ent;
    uint32_t uniqueIos_Flags;
    uint32_t uniqueIos_Vector1;
    uint32_t uniqueIos_Vector2;
    struct tagBlock<uniqueFoliage> uniqueFoliage_ent;
    uint32_t uniqueFoliage_Flags;
    uint32_t uniqueFoliage_Vector1;
    uint32_t uniqueFoliage_Vector2;
    struct tagBlock<decorator_sets> decorator_sets_ent;
    struct tagBlock<decorator_runtime> decorator_runtime_ent;
    uint8_t flags_render_flags;
    uint32_t generated_pad8b4a;
    uint16_t generated_pad8b4a_2;
    uint8_t generated_pad8b4a_3;
};


#ifdef SBSP_STRUCTURE_IMPL
// Tag Structure (used by the loader)

uint8_t sbsp_structure[] {0x38,0x7,0x38,0x6,0x34,0x34,0x34,0x34,0x3B,0x3B,0x38,0x6,0x6,0x6,0x6,0x6,0x6,0x3B,0x38,0x6,0x6,0x6,0x6,0x6,0x6,0x3B,0x6,0x6,0x41,0x41,0xE,0xE,0xE,0x34,0x34,0x40,0x38,0x6,0x6,0x6,0x6,0x3B,0x40,0x6,0x3B,0x40,0x6,0x17,0x3B,0x3B,0x40,0x2E,0x2E,0xE,0x3B,0x40,0x3C,0x3B,0x40,0x5,0x4,0xF,0x6,0x2E,0x2E,0x6,0x2E,0x34,0x34,0x3B,0x40,0x3D,0x3B,0x40,0x40,0x5,0x3B,0x40,0x5,0x3B,0x3B,0x25,0x25,0x25,0x40,0x38,0x17,0x19,0x1A,0x3B,0x5,0x5,0x6,0x17,0x14,0xD,0x40,0x17,0x3B,0x3B,0x40,0x36,0x25,0x25,0x25,0x40,0x5,0x3B,0x5,0x5,0x40,0x5,0x3B,0x40,0x6,0x41,0x6,0x40,0x5,0x3B,0x6,0x6,0x6,0x3B,0x6,0x6,0x6,0x3B,0x40,0x37,0x38,0x40,0x7,0x3B,0x40,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x3B,0x40,0x1E,0x3B,0x40,0xF,0x34,0x3D,0x3E,0x3B,0x40,0x5,0x5,0x3B,0x40,0x1D,0x5,0x5,0x3B,0x40,0x3D,0x3D,0x5,0xF,0x3C,0x3B,0x40,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3B,0x40,0x17,0x3D,0x5,0x3B,0x3B,0x37,0x3B,0x40,0xA,0x0,0x34,0x34,0x34,0x1A,0x17,0x3B,0x40,0x40,0x6,0x40,0x17,0x3B,0x3B,0x40,0x6,0x3B,0x3B,0x40,0x6,0x6,0x6,0x40,0x17,0x3B,0x14,0x3B,0x40,0x1,0xA,0x34,0xE,0x3D,0x34,0x34,0x6,0x40,0xA,0xA,0xE,0x42,0x6,0x0,0x6,0x40,0x38,0x17,0x39,0x0004,0x3C,0x39,0x0004,0x14,0x3B,0x20,0x14,0x3B,0x40,0x38,0x17,0x39,0x0004,0x3C,0x39,0x0004,0x14,0x3B,0x20,0x19,0x14,0x3B,0x40,0x39,0x0002,0x38,0x17,0x39,0x0004,0x3C,0x39,0x0004,0x14,0x3B,0x20,0x3B,0x40,0x39,0x0003,0x38,0x17,0x39,0x0004,0x3C,0x39,0x0004,0x14,0x3B,0x20,0x3B,0x40,0x39,0x0004,0x38,0x17,0x39,0x0004,0x3C,0x39,0x0004,0x14,0x3B,0x20,0x3B,0x40,0x42,0x38,0x17,0x39,0x0004,0x3C,0x39,0x0004,0x14,0x3B,0x20,0x3B,0x6,0x6,0x25,0x25,0x25,0x20,0x3B,0x3B,0x40,0x19,0x19,0x19,0x19,0x17,0x41,0x41,0x5,0x5,0xE,0x34,0x34,0x14,0x14,0x14,0x14,0x14,0x14,0x17,0x14,0x34,0x34,0x34,0x34,0x7,0xA,0xA,0xE,0x3D,0x34,0x34,0x38,0x40,0x14,0x3B,0x6,0x6,0x6,0x14,0x3B,0x2,0x6,0x34,0x34,0x34,0x34,0x7,0x38,0x40,0x41,0x3B,0x6,0x6,0x6,0xE,0x34,0x34,0x3B,0x17,0x17,0x6,0x7,0x7,0x3B,0x6,0x6,0x6,0x40,0x19,0x19,0x19,0x19,0x17,0x41,0x41,0x5,0x5,0xE,0x34,0x34,0x14,0x14,0x14,0x14,0x14,0x14,0x17,0x14,0x34,0x34,0x34,0x34,0x7,0xA,0xA,0xE,0x3D,0x34,0x34,0x38,0x40,0x14,0x3B,0x6,0x6,0x6,0x14,0x3B,0x2,0x6,0x34,0x34,0x34,0x34,0x7,0x38,0x40,0x41,0x3B,0x6,0x6,0x6,0xE,0x34,0x34,0x3B,0x17,0x17,0x6,0x7,0x7,0x3B,0x6,0x6,0x6,0x40,0x41,0x40,0x5,0x3B,0x6,0x6,0x6,0x19,0x19,0x19,0x19,0x17,0xD,0x6,0x39,0x0004,0x3E,0xF,0x34,0x34,0x34,0x34,0x34,0x34,0x34,0x7,0x3B,0x6,0x6,0x6,0x6,0x7,0x40,0x40,0xE,0xE,0x40,0xB,0x5,0x5,0x34,0x34,0x17,0x17,0x3B,0x40,0x6,0x3B,0x40,0x6,0x3B,0x40,0x6,0x3B,0x40,0x6,0x3B,0x3B,0x40,0x6,0x6,0x40,0xB,0x5,0x5,0x34,0x34,0x17,0x17,0x3B,0x40,0x6,0x3B,0x40,0x6,0x3B,0x3B,0x40,0x6,0x6,0x40,0xB,0x5,0x5,0x34,0x34,0x17,0x17,0x3B,0x40,0x6,0x3B,0x40,0x6,0x3B,0x40,0x6,0x3B,0x3B,0x3B,0x34,0x34,0x34,0x34,0x38,0xD,0x40,0x3E,0x17,0x17,0x16,0x16,0x3B,0x40,0x40,0x40,0x40,0x17,0x16,0x17,0x17,0x17,0x16,0x39,0x0008,0x3C,0x39,0x0008,0x14,0x17,0x16,0x14,0x14,0x17,0x16,0x17,0x3B,0x40,0x3D,0x3B,0x40,0x3E,0x3B,0x40,0x40,0x3D,0x3B,0x40,0x16,0x3B,0x3B,0x40,0x19,0x19,0x20,0x3E,0x3B,0x40,0x3E,0x3B,0x40,0x3E,0x3E,0x14,0x3B,0x40,0x3E,0x3B,0x40,0x3E,0x3E,0x3B,0xD,0x40,0x41,0x2,0x41,0x2,0x6,0x40,0x2,0x41,0x41,0x3B,0x3B,0x3B,0x40,0x1E,0x17,0x14,0x39,0x0008,0x3C,0x39,0x0007,0x14,0x3B,0x40,0x2E,0x2E,0x6,0x6,0x6,0x3C,0x34,0xE,0x3D,0x34,0x34,0x3B,0x40,0x6,0x6,0x2E,0x3D,0x3B,0x40,0x6,0x14,0x3B,0x39,0x0013,0x3D,0x3D,0xE,0xE,0x3D,0x34,0x34,0x3B,0xE,0x3C,0xA,0x4,0xA,0x5,0x40,0x6,0x6,0x3B,0x2E,0x5,0x5,0x34,0x34,0x6,0x3B,0x40,0x30,0x3B,0x40,0xE,0x34,0x34,0x36,0x17,0x17,0x16,0x16,0x16,0x16,0x16,0x16,0x14,0x14,0x3B,0x40,0x40,0x3D,0x3B,0x3B,0x40,0x41,0x2,0x3B,0x40,0x17,0x17,0x40,0x1E,0x17,0x14,0x39,0x0008,0x3C,0x39,0x0007,0x14,0x3B,0x3B,0x38,0x3D,0xB,0x3D,0x3D,0x3D,0x34,0x34,0x40,0x43,0x40,0xC,0xC,0x3C,0x3C,0x34,0x34,0x3E,0x3E,0x38,0x3E,0x3E,0x3E,0x3E,0x42,0x3D,0x3D,0x3B,0x7,0x7,0x3B,0x40,0x3C,0x3C,0x3C,0x34,0x3E,0x3E,0x38,0x3E,0x3E,0x3E,0x3E,0x42,0x3D,0x3D,0x3B,0x7,0x7,0x3B,0x40,0x3D,0x3D,0xC,0xA,0x34,0x34,0x34,0x19,0x19,0x40,0x3E,0x3E,0x3C,0x34,0x34,0x34,0x3B,0xE,0x34,0x34,0x34,0x34,0x34,0x34,0x38,0x42,0x6,0x6,0x3E,0x34,0x34,0x34,0x34,0x7,0x3B,0x3B,0x40,0x6,0x4,0x34,0x34,0x34,0x42,0x40,0x42,0x3B,0x3B,0x40,0x3D,0x3D,0x3E,0x3E,0x3B,0x40,0x3E,0x3E,0x42,0x3B,0x7,0x7,0x39,0x0015,0x7,0x7,0x3B,0x3B,0x40,0x5,0x5,0x3B,0x40,0x5,0x5,0x3B,0x40,0x5,0x5,0x3B,0x3B,0x40,0x17,0x17,0x17,0x17,0x40,0x3E,0x3B,0x3B,0x40,0x40,0x2,0x3C,0x34,0x34,0x34,0x14,0x3B,0x2,0x3B,0x40,0x40,0x3D,0x3B,0x3B,0x40,0x2,0x14,0x3B,0x34,0x34,0x34,0x34,0x7,0x4,0x34,0x34,0x34,0x34,0x34,0x34,0x34,0x3B,0x40,0x5,0x34,0x34,0x41,0x3B,0x38,0x40,0x38,0x40,0x40,0x7,0x3B,0x40,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x3B,0x40,0x1E,0x3B,0x40,0xF,0x34,0x3D,0x3E,0x3B,0x40,0x5,0x5,0x3B,0x40,0x1D,0x5,0x5,0x3B,0x40,0x3D,0x3D,0x5,0xF,0x3C,0x3B,0x40,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3B,0x40,0x17,0x3D,0x5,0x3B,0x3B,0x40,0x40,0x6,0x6,0x6,0x3B,0x40,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x3B,0x40,0x1E,0x3B,0x40,0xF,0x34,0x5,0x6,0x3B,0x40,0x6,0x6,0x3B,0x40,0x1D,0x6,0x6,0x3B,0x40,0x6,0x6,0x5,0xF,0x3C,0x3B,0x40,0x6,0x6,0x6,0x6,0x6,0x6,0x3B,0x40,0x17,0x6,0x5,0x34,0x34,0x3B,0x3B,0x3B,0x3B,0x43,0x38,0x40,0x40,0x7,0x3B,0x40,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x3B,0x40,0x1E,0x3B,0x40,0xF,0x34,0x3D,0x3E,0x3B,0x40,0x5,0x5,0x3B,0x40,0x1D,0x5,0x5,0x3B,0x40,0x3D,0x3D,0x5,0xF,0x3C,0x3B,0x40,0x3D,0x3D,0x3D,0x3D,0x3D,0x3D,0x3B,0x40,0x17,0x3D,0x5,0x3B,0x3B,0x40,0x40,0x6,0x6,0x6,0x3B,0x40,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x6,0x3B,0x40,0x1E,0x3B,0x40,0xF,0x34,0x5,0x6,0x3B,0x40,0x6,0x6,0x3B,0x40,0x1D,0x6,0x6,0x3B,0x40,0x6,0x6,0x5,0xF,0x3C,0x3B,0x40,0x6,0x6,0x6,0x6,0x6,0x6,0x3B,0x40,0x17,0x6,0x5,0x34,0x34,0x3B,0x3B,0x3B,0x3B,0x6,0x3B,0x40,0x41,0x41,0x41,0x2,0x2,0x19,0x19,0x19,0x19,0x17,0xE,0xE,0xF,0xF,0xA,0xA,0xE,0x34,0x34,0x39,0x0010,0x14,0x14,0xC,0x6,0x3E,0xE,0x34,0x34,0x2,0x34,0x34,0x34,0x34,0x7,0x40,0x41,0x41,0x3B,0x40,0x41,0x41,0x3B,0x3B,0x6,0x40,0x17,0x19,0x19,0x19,0x3E,0x3B,0x7,0x42,0x7,0x6,0x6,0x7,0x7,0x7,0x7,0x7,0x7,0x38,0x7,0x39,0x0400,0x3E,0x3B,0x7,0x7,0x41,0x6,0x6,0x34,0x34,0x34,0x34,0x7,0x7,0x7,0x39,0x0400,0x3E,0x7,0x40,0x41,0x3B,0x6,0x6,0x6,0x40,0x40,0x40,0x6,0x14,0x3B,0x6,0x6,0x6,0x3B,0x6,0x6,0x6,0x5,0x34,0x34,0x3B,0x6,0x6,0x6,0x40,0x40,0x40,0x6,0x14,0x3B,0x6,0x6,0x6,0x3B,0x6,0x6,0x6,0x5,0x34,0x34,0x3B,0x6,0x6,0x6,0x40,0x41,0x40,0x17,0x3C,0x3C,0x3C,0xF,0x1A,0x14,0x17,0x17,0x17,0x6,0x3D,0x3D,0x3B,0x41,0x3B,0x40,0x40,0x41,0x6,0x6,0x3C,0x34,0x34,0x34,0x3B,0x40,0x19,0x14,0x19,0x19,0x14,0x19,0x19,0x3B,0x6,0x34,0x34,0x34,0x34,0x7,0x7,0x3B,0xF,0x34,0x34,0x34,0x34,0x34,0x34,0x34,0x3B};


#else
extern uint8_t sbsp_structure[1492];
#endif


#pragma pack(pop)

