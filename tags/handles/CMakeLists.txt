target_sources(Infinite PRIVATE ${CMAKE_CURRENT_LIST_DIR}/modeHandle.cpp)
target_sources(Infinite PRIVATE ${CMAKE_CURRENT_LIST_DIR}/mat_Handle.cpp)
target_sources(Infinite PRIVATE ${CMAKE_CURRENT_LIST_DIR}/rtgoHandle.cpp)
target_sources(Infinite PRIVATE ${CMAKE_CURRENT_LIST_DIR}/pmdfHandle.cpp)
target_sources(Infinite PRIVATE ${CMAKE_CURRENT_LIST_DIR}/sbspHandle.cpp)
target_sources(Infinite PRIVATE ${CMAKE_CURRENT_LIST_DIR}/shdvHandle.cpp)
target_sources(Infinite PRIVATE ${CMAKE_CURRENT_LIST_DIR}/vartHandle.cpp)
target_sources(Infinite PRIVATE ${CMAKE_CURRENT_LIST_DIR}/levlHandle.cpp)
target_sources(Infinite PRIVATE ${CMAKE_CURRENT_LIST_DIR}/mwsyHandle.cpp)
target_sources(Infinite PRIVATE ${CMAKE_CURRENT_LIST_DIR}/cwmsHandle.cpp)
target_sources(Infinite PRIVATE ${CMAKE_CURRENT_LIST_DIR}/cmswHandle.cpp)
target_sources(Infinite PRIVATE ${CMAKE_CURRENT_LIST_DIR}/render_geometryHandle.cpp)

include(${CMAKE_CURRENT_LIST_DIR}/baseClasses/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/materialParameters/CMakeLists.txt)
