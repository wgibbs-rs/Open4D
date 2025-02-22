


#ifndef OFD_object_c_h_
#define OFD_object_c_h_


#include "OFD_transform_c.h"
#include "../geometry/OFD_mesh_c.h"

/** @brief Stored information on a given physics object. */
typedef struct {
    OFD_Transform transform;
    OFD_Mesh mesh;
} OFD_Object;


#endif // OFD_object_c_h_