

#ifndef OFD_mesh_c_h_
#define OFD_mesh_c_h_

#include "OFD_tetrahedron_c.h"


/** @brief Defines the structure for an object's geometry. */
typedef struct {
   OFD_Tetrahedron mesh[];
} OFD_Mesh;



#endif // OFD_mesh_c_h_