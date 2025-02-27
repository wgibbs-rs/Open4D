cmake_minimum_required(VERSION 3.10)
project(Open4D)

# Set C standard
set(CMAKE_C_STANDARD 99)

# Add the library 
add_library(Open4D SHARED 
    src/OFD.c 
    src/geometry/OFD_mesh.c
    src/geometry/OFD_tetrahedron.c
    src/physics/OFD_collision.c
    src/physics/OFD_rigidbody.c
    src/util/OFD_vector.c
)

set_target_properties(Open4D PROPERTIES
    OUTPUT_NAME "Open4D"
)

target_include_directories(Open4D PUBLIC include)