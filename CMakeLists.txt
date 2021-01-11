cmake_minimum_required(VERSION 3.0)
project(SFButton)

###################################################################
# Option Setting
option(ENABLE_SAMPLE "build sample program.(Default:OFF)" OFF)

###################################################################
# import SFML library
find_package(SFML 2.5.1 COMPONENTS system window graphics)
if (SFML_FOUND)
    message(STATUS "SFML found.")
    message(STATUS "SFML_INCLUDE_DIRS: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
else()
    message(STATUS "SFML is not found in the system")
    message(STATUS "Assume SFML is contained in build structure.")
endif ()

###################################################################
# Configure general build settings
set(CMAKE_CXX_STANDARD 17)

###################################################################
# Configure build for SFGraphing library
file(GLOB SFBUTTON_SRC src/*.cpp)
add_library(SFButton STATIC ${SFBUTTON_SRC} )
target_link_libraries(SFButton PUBLIC sfml-graphics sfml-window sfml-system)
target_include_directories(SFButton PUBLIC include/)

###################################################################
# Configure build for Sample program
if(ENABLE_SAMPLE)
file(GLOB SAMPLE_SRC sample/*.cpp)
add_executable(sample ${SAMPLE_SRC})
target_link_libraries(sample SFButton)
endif()
