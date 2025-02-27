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

#ifndef OFD_rigidbody_c_h_
#define OFD_rigidbody_c_h_


#include "../geometry/OFD_mesh_c.h"
#include "OFD_transform_c.h"
#include "OFD_world.h"


/** @brief Stored information on a given physics object. */
typedef struct {
    OFD_Transform transform;
    OFD_Mesh mesh;
} OFD_Rigidbody;

/** @brief Animates a rigidbody by a time interval (dt). */
extern void OFD_AnimateRigidbody(OFD_Rigidbody* a, OFD_Mesh other[], OFD_WorldParameters world, double dt);

/** @brief Calculates the moment of inertia for a geometry, given that mass is uniformly distributed. */
extern double OFD_UniformInertiaTensor(OFD_Mesh mesh);

/** @brief Calculates and updates the velocities of a given object based on a collision impulse. */
extern void OFD_ApplyRigidbodyImpulse(OFD_Rigidbody* a, OFD_Vector4 collisionsPoint[]);


#endif // OFD_rigidbody_c_h_