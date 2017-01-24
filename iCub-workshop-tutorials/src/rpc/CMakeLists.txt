cmake_minimum_required(VERSION 2.6)

set(PROJECTNAME rpctutorial)
project(${PROJECTNAME})

find_package(YARP REQUIRED)

list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH} ${ICUBCONTRIB_MODULE_PATH})

include(YarpInstallationHelpers)

include_directories(${YARP_INCLUDE_DIRS})

add_subdirectory(rpctutorial)
