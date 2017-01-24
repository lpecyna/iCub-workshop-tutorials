cmake_minimum_required(VERSION 2.6)

set(PROJECTNAME motorTutorial)
project(${PROJECTNAME})

find_package(YARP REQUIRED)
list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})
include_directories(${YARP_INCLUDE_DIRS})

file(GLOB source src/*.cpp)

source_group("Source Files" FILES ${source})

add_executable(${PROJECTNAME} ${source})

target_link_libraries(${PROJECTNAME} ${YARP_LIBRARIES}) 

install(TARGETS ${PROJECTNAME} DESTINATION build)
