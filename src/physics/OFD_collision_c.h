
#ifndef OFD_collision_c_h_
#define OFD_collision_c_h_

#include "../util/OFD_vector_c.h"
#include "../geometry/OFD_mesh_c.h"

/** @brief Finds collision points on a given mesh in an environment of other collidable structures. */
static inline OFD_Vector4* OFD_GetCollisionPoints(OFD_Mesh mesh, OFD_Mesh env[]);

/** @brief Tests if two tetrahedrons are colliding, and returns the collision point. */
static inline OFD_Vector4* OFD_TestTetrahedronCollision(OFD_Tetrahedron a, OFD_Tetrahedron b);

#endif // OFD_collision_c_h_