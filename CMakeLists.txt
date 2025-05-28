cmake_minimum_required(VERSION 3.10)
project(StardustDefenders)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Use libc++ if using Clang (default on Mac)
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()


# Set HERE the "brew --prefix sfml@2"
#  |
#  |
#  v

# Specify SFML path (update this if needed)
set(SFML_PATH "/usr/local/opt/sfml@2")
include_directories(${SFML_PATH}/include)
link_directories(${SFML_PATH}/lib)

# Include our own additional headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Set runtime output directory to the project root so asset paths work correctly
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# Recursively get all .cpp files in the src directory
file(GLOB_RECURSE CPP_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Create executable
add_executable(StardustDefenders ${CPP_FILES})

# Set RPATH to SFML libraries for runtime linking
set_target_properties(StardustDefenders PROPERTIES
    BUILD_RPATH "${SFML_PATH}/lib"
    INSTALL_RPATH "${SFML_PATH}/lib"
)

# Link SFML libraries
target_link_libraries(StardustDefenders sfml-graphics sfml-window sfml-system sfml-audio sfml-network)