cmake_minimum_required(VERSION 2.6)

set(PROJECTNAME iCubWorkshop)
project(${PROJECTNAME})

find_package(YARP REQUIRED)
include_directories(${YARP_INCLUDE_DIRS})

add_subdirectory(motorTutorial)
