cmake_minimum_required(VERSION 3.0.0)
project(Infinite VERSION 0.1.0)

add_library(Infinite SHARED)

set(OODLE_LIBRARY ${CMAKE_CURRENT_LIST_DIR}/liblinoodle.so)

#include_directories(${GTKMM_INCLUDE_DIRS})
#target_link_directories(infiniteExplorer ${GTKMM_LIBRARY_DIRS})
#target_include_directories(Infinite PRIVATE ${GTKMM_INCLUDE_DIRS})


set_property(TARGET Infinite PROPERTY CXX_STANDARD 17)

target_sources(Infinite PRIVATE ${CMAKE_CURRENT_LIST_DIR}/DataTable.cpp ${CMAKE_CURRENT_LIST_DIR}/ContentTable.cpp ${CMAKE_CURRENT_LIST_DIR}/StringTable.cpp)

include(${CMAKE_CURRENT_LIST_DIR}/module/CMakeLists.txt)

target_include_directories(Infinite PUBLIC .)

#target_link_libraries(infiniteExplorer ${GTKMM_LIBRARIES})



#link against oodle (or linoodle)

add_library(oodle SHARED IMPORTED)

set_target_properties(oodle PROPERTIES IMPORTED_LOCATION ${OODLE_LIBRARY})


target_link_libraries(Infinite PRIVATE oodle)


set(LIBINFINITE_LIBRARY_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/libInfinite.so PARENT_SCOPE)

if(${INFINITE_COPY_OODLE_DLL})
	configure_file(${CMAKE_CURRENT_LIST_DIR}/${INFINITE_OODLE_DLL} ${INFINITE_OODLE_DLL} COPYONLY)
endif()