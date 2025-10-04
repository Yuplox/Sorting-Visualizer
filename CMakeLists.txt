# Set minimum CMake version
cmake_minimum_required(VERSION 4.0)

include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.11.0
)

FetchContent_MakeAvailable(Catch2)

# Set required compiler standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Allows clangd to properly lint code
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Describes the project
project(SortingVisualizer
    VERSION 0.1
    DESCRIPTION "Sorting visualizer made with Qt"
)

# Set location of source files
set(SOURCE_FILES 
    ${PROJECT_SOURCE_DIR}/src/rand_vector.cpp
    ${PROJECT_SOURCE_DIR}/tests/sorter_test.cpp)

# Set location of include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/include/
)

# Defines the executable generated
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Sets directory for executable based on CONFIG
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/debug"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/release"
)

# Links external library
target_link_libraries(${PROJECT_NAME}
    PRIVATE Catch2::Catch2WithMain
)

# Adds tests to CTest
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(${PROJECT_NAME})

# Adds compile options
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -Wpedantic -Wshadow>
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -Wpedantic -Wshadow>
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
)

# Adds debug-specific options
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:GNU>>:-g -O0>
    $<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:Clang>>:-g -O0>
    $<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:MSVC>>:/Zi /Od /RTC1>
)

# Adds release-specific options
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:GNU>>:-O3>
    $<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:Clang>>:-O3>
    $<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:MSVC>>:/O2>
)