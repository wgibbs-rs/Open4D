

cmake_minimum_required(VERSION 3.10)
project(Open4D)

# Set C standard
set(CMAKE_C_STANDARD 99)

# Add the library 
add_library(Open4D SHARED 
    ${PROJECT_SOURCE_DIR}/src/geometry/OFD_mesh.c
    ${PROJECT_SOURCE_DIR}/src/geometry/OFD_tetrahedron.c
    ${PROJECT_SOURCE_DIR}/src/geometry/OFD_primitive.c
    ${PROJECT_SOURCE_DIR}/src/physics/OFD_collision.c
    ${PROJECT_SOURCE_DIR}/src/physics/OFD_rigidbody.c
    ${PROJECT_SOURCE_DIR}/src/util/OFD_vector.c
)

set_target_properties(Open4D PROPERTIES
    OUTPUT_NAME "Open4D"
)

target_include_directories(Open4D PUBLIC ${PROJECT_SOURCE_DIR}/include)



# Testing

enable_testing()

# Add all individual unit tests

add_executable(test_util tests/test_util.c)
target_link_libraries(test_util Open4D)
add_test(NAME TestUtilities COMMAND test_util)



target_compile_definitions(Open4D PRIVATE OPEN4D_EXPORTS)

if(NOT WIN32)
  set(CMAKE_C_VISIBILITY_PRESET hidden)
  set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
endif()