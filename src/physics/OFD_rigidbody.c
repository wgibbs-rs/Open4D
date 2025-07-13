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


const OFD_Transform OFD_DEFAULT_TRANSFORM = { 
   .position = {0, 0, 0, 0}, 
   .center_of_mass = {0, 0, 0, 0}, 
   .rotation = {0, 0, 0, 0, 0, 0}, 
   .angular_velocity = {0, 0, 0, 0, 0, 0},
   .mass = 1,
   .restitution = 0,
   .static_friction = 0,
   .kinetic_friction = 0,
   .rolling_friction = 0,
   .inertia = 10
};

const OFD_WorldParameters OFD_DEFAULT_WORLD = {
   .gravity = 9.80665 // Standardized by nist.gov
};



void OFD_AnimateRigidbody(OFD_Rigidbody* a, OFD_Mesh* env, const int envLength, const OFD_WorldParameters world, const double dt) {
   printf("Error: " RED "error: " RESET "Physics has not been implemented in this version.");
}


void OFD_ApplyRigidbodyImpulse(OFD_Rigidbody* a, const OFD_Vector4* collisionsPoints, const int collisionPointsLength) {
   printf("Error: " RED "error: " RESET "Physics has not been implemented in this version.");
}