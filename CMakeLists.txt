cmake_minimum_required(VERSION 3.26.4)
project(brick-breaker-extreme)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(IS_RELEASE_MODE FALSE)

# Note: This compiler optimisation may break debugging.
if (IS_RELEASE_MODE)
    message("-- Loading release build, compiler optimisations set")
    set(CXXFLAGS  "-Wall -std=c++${CMAKE_CXX_STANDARD} -I./include -g -O2")
else()
    message("-- Loading debug build, compiler optimisations disabled")
    set(CXXFLAGS  "-Wall -std=c++${CMAKE_CXX_STANDARD} -I./include")
endif ()
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")

message("-- C++ Version Found " = " ${CMAKE_CXX_STANDARD}")

# The term "build type" in CMake refers to a certain build configuration such as debug and release.
# We give our configuration a debug build type by default.
# A debug build often results in fast compile times with debugging symbols baked
#  into executables - enabling debugging with tools as such as GDB and LLDB:

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif ()

# command generates a header file called config.h which includes preprocessor definitions that specify
#  our project's major and minor version number. CMake reads config.h.in to produce this header file:
# configure_file(config.h.in config.h)

file(GLOB GAME_SOURCES "src/*.cpp")
file(COPY assets DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
add_executable(${PROJECT_NAME} ${GAME_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_BINARY_DIR}")
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Detect and add SFML
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
