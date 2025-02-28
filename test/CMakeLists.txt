# Set minimum required version for CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Open4DTest C)

# Set the C standard
set(CMAKE_C_STANDARD 11)

# Find Raylib (global installation)
find_package(raylib REQUIRED)

# Set the path of the Open4D dynamic linked library.
if (APPLE)
    set(OPEN4D_LIB_PATH "${CMAKE_SOURCE_DIR}/../build/libOpen4D.dylib")  # Update this to your Open4D dylib location
elseif (WIN32) 
    set(OPEN4D_LIB_PATH "${CMAKE_SOURCE_DIR}/../build/libOpen4D.dll")
elseif (UNIX)
    set(OPEN4D_LIB_PATH "${CMAKE_SOURCE_DIR}/../build/libOpen4D.so")
endif()

set(OPEN4D_INCLUDE_PATH "${CMAKE_SOURCE_DIR}/../include")  # Update this to your Open4D header location

# Include Open4D headers
include_directories(${OPEN4D_INCLUDE_PATH})

# Create the executable from the main source file
add_executable(Open4DTest 
    main.c
    renderer.c
)

# Link Open4D dynamic library and Raylib to the executable
target_link_libraries(Open4DTest 
    ${OPEN4D_LIB_PATH}
    raylib
)