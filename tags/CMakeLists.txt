target_sources(Infinite PRIVATE ${CMAKE_CURRENT_LIST_DIR}/TagLoader.cpp)
target_sources(Infinite PRIVATE ${CMAKE_CURRENT_LIST_DIR}/TagManager.cpp)
target_sources(Infinite PRIVATE ${CMAKE_CURRENT_LIST_DIR}/Tag.cpp)

include(${CMAKE_CURRENT_LIST_DIR}/loaders/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/handles/CMakeLists.txt)