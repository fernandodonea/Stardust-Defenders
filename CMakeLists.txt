cmake_minimum_required(VERSION 3.10)
project(StardustDefenders)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Use libc++ if using Clang (default on Mac)
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()

# Detect the operating system
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    # Use default system paths for SFML on Linux
    find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)
    include_directories(${SFML_INCLUDE_DIRS})
    link_directories(${SFML_LIBRARY_DIRS})
else()
    # macOS-specific SFML setup
    set(SFML_PATH "/usr/local/opt/sfml@2")
    include_directories(${SFML_PATH}/include)
    link_directories(${SFML_PATH}/lib)
endif()

# Include our own additional headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Set runtime output directory to the project root so asset paths work correctly
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# Recursively get all .cpp files in the src directory
file(GLOB_RECURSE CPP_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Add the executable
add_executable(StardustDefenders ${CPP_FILES})

# Link SFML libraries
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(StardustDefenders sfml-graphics sfml-window sfml-system sfml-audio)
else()
    target_link_libraries(StardustDefenders sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
endif()