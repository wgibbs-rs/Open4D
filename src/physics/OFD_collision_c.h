/*
   Open4D
   Copyright (c) 2025 William Gibbs & S.V

   This software is provided 'as-is', without any express or implied
   warranty. In no event will the authors be held liable for any damages
   arising from the use of this software.

   Permission is granted to anyone to use this software for any purpose,
   including commercial applications, and to alter it and redistribute it
   freely, subject to the following restrictions:

   1. The origin of this software must not be misrepresented; you must not
      claim that you wrote the original software. If you use this software
      in a product, an acknowledgment in the product documentation would be
      appreciated but is not required.
   2. Altered source versions must be plainly marked as such, and must not be
      misrepresented as being the original software.
   3. This notice may not be removed or altered from any source distribution.
*/

#ifndef OFD_collision_c_h_
#define OFD_collision_c_h_

#include "../util/OFD_vector_c.h"
#include "../geometry/OFD_mesh_c.h"

/** @brief Finds collision points on a given mesh in an environment of other collidable structures. */
static inline OFD_Vector4* OFD_GetCollisionPoints(OFD_Mesh mesh, OFD_Mesh env[]);

/** @brief Tests if two tetrahedrons are colliding, and returns the collision point. */
static inline OFD_Vector4* OFD_TestTetrahedronCollision(OFD_Tetrahedron a, OFD_Tetrahedron b);

#endif // OFD_collision_c_h_