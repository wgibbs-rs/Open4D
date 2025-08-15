/*
   Open4D
   Copyright (c) 2025 William Gibbs

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

#include "Open4D/OFD_physics.h"

#include <stdio.h>
#include <stdlib.h>

#define RED "\033[1;31m"
#define RESET "\033[0m"

/** @brief Finds collision points on a given mesh in an environment of other collidable structures. */
OFD_Vector4* OFD_GetCollisionPoints(const OFD_Mesh mesh, const OFD_Mesh* env) {
   printf("Error: " RED "error: " RESET "Physics has not been implemented in this version.");
   return NULL;
}

/** @brief Tests if two tetrahedrons are colliding, and returns the collision point. */
OFD_Vector4* OFD_TestTetrahedronCollision(const OFD_Tetrahedron a, const OFD_Tetrahedron b) {
   printf("Error: " RED "error: " RESET "Physics has not been implemented in this version.");
   return NULL;
}