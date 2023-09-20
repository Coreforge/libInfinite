cmake_minimum_required(VERSION 3.10.0)
project(Infinite VERSION 0.1.0)

# ASAN options
if(OFF)
	set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -fsanitize=address PARENT_SCOPE)
	set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address PARENT_SCOPE)
	set(CMAKE_MODULE_LINKER_FLAGS ${CMAKE_MODULE_LINKER_FLAGS} -fsanitize=address PARENT_SCOPE)
endif()

if(WIN32 AND NOT CREATE_DLL)
add_library(Infinite)
else()
add_library(Infinite SHARED)
endif()


add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/3rd_party/detex)
target_link_libraries(Infinite detex)
target_include_directories(Infinite PRIVATE ${CMAKE_CURRENT_LIST_DIR}/3rd_party/detex)

find_package(PNG REQUIRED)
target_link_libraries(Infinite ${PNG_LIBRARIES})
find_package(jsoncpp REQUIRED)
target_link_libraries(Infinite jsoncpp)

if(NOT DEFINED OODLE_LIBRARY)
	set(OODLE_LIBRARY ${CMAKE_CURRENT_LIST_DIR}/liblinoodle.so)
endif()
message(STATUS "Using oodle from ${OODLE_LIBRARY}")

#include_directories(${GTKMM_INCLUDE_DIRS})
#target_link_directories(infiniteExplorer ${GTKMM_LIBRARY_DIRS})
#target_include_directories(Infinite PRIVATE ${GTKMM_INCLUDE_DIRS})


set_property(TARGET Infinite PROPERTY CXX_STANDARD 20)

target_include_directories(Infinite PUBLIC .)

target_sources(Infinite PRIVATE ${CMAKE_CURRENT_LIST_DIR}/DataTable.cpp ${CMAKE_CURRENT_LIST_DIR}/ContentTable.cpp)
target_sources(Infinite PRIVATE ${CMAKE_CURRENT_LIST_DIR}/TagRefFieldTable.cpp ${CMAKE_CURRENT_LIST_DIR}/Item.cpp)
target_sources(Infinite PRIVATE ${CMAKE_CURRENT_LIST_DIR}/Header.cpp ${CMAKE_CURRENT_LIST_DIR}/TagRefTable.cpp)
target_sources(Infinite PRIVATE ${CMAKE_CURRENT_LIST_DIR}/DataRefTable.cpp)
target_sources(Infinite PRIVATE ${CMAKE_CURRENT_LIST_DIR}/BitmapHandle.cpp
								${CMAKE_CURRENT_LIST_DIR}/contentUtils.cpp
								${CMAKE_CURRENT_LIST_DIR}/BitmapBatchExtractor.cpp
								${CMAKE_CURRENT_LIST_DIR}/MaterialJsonExporter.cpp								
								${CMAKE_CURRENT_LIST_DIR}/StringIDLUT.cpp)

include(${CMAKE_CURRENT_LIST_DIR}/module/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/logger/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/tags/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/models/CMakeLists.txt)
#include(${CMAKE_CURRENT_LIST_DIR}/utils/CMakeLists.txt)



#target_link_libraries(infiniteExplorer ${GTKMM_LIBRARIES})



#link against oodle (or linoodle)

if(WIN32)
	add_library(oodle MODULE IMPORTED)
else()
	add_library(oodle SHARED IMPORTED)
endif()

set_target_properties(oodle PROPERTIES IMPORTED_LOCATION ${OODLE_LIBRARY})

target_link_libraries(Infinite oodle)

if(USE_COMPRESSONATOR)
	target_link_libraries(Infinite CMP_Compressonator)
	target_include_directories(Infinite PRIVATE ${COMPRESSONATOR_DIR}/cmp_compressonatorlib)
endif()

#set(LIBINFINITE_LIBRARY_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/libInfinite.so PARENT_SCOPE)

if(${INFINITE_COPY_OODLE_DLL})
	configure_file(${CMAKE_CURRENT_LIST_DIR}/${INFINITE_OODLE_DLL} ${INFINITE_OODLE_DLL} COPYONLY)
endif()

configure_file(${CMAKE_CURRENT_LIST_DIR}/3rd_party/detex/LICENSE detex_LICENSE COPYONLY)
