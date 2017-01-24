cmake_minimum_required(VERSION 2.6)

set(PROJECTNAME rpctutorial)
project(${PROJECTNAME})

find_package(YARP REQUIRED)
list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})

include(YarpIDL)
set(IDL_GENERATED_CODE_DIR "${CMAKE_CURRENT_SOURCE_DIR}") 
yarp_idl_to_dir(${PROJECTNAME}.thrift ${IDL_GENERATED_CODE_DIR})

include(YarpInstallationHelpers)

file(GLOB source src/*.cpp)
file(GLOB header include/*.h)

source_group("Source Files" FILES ${source})
source_group("Header Files" FILES ${header})

include_directories(${PROJECT_SOURCE_DIR}/include
                    ${YARP_INCLUDE_DIRS}
                    ${IDL_GENERATED_CODE_DIR}/include
)

add_executable(${PROJECTNAME} ${source})

target_link_libraries(${PROJECTNAME} ${YARP_LIBRARIES}) 

install(TARGETS ${PROJECTNAME} DESTINATION build)
