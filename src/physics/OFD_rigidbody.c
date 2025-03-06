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

#include "Open4D/OFD_physics.h"


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


/** @brief Offsets a vector by a given velocity and change in time. */
static void offsetVector(OFD_Vector4* a, OFD_Vector4 velocity, double dt);

void OFD_AnimateRigidbody(OFD_Rigidbody* a, OFD_Mesh other[], OFD_WorldParameters world, double dt) {

   // Step 1: Apply gravity
   a->transform.velocity.y -= world.gravity;

   // Step 2: Test for collisions.


   // Step 3: Apply impulse forces

   
   // Step 4: Apply translational velocity

   a->transform.center_of_mass.x += a->transform.velocity.x * dt;
   a->transform.center_of_mass.y += a->transform.velocity.y * dt;
   a->transform.center_of_mass.z += a->transform.velocity.z * dt;
   a->transform.center_of_mass.w += a->transform.velocity.w * dt;
   for (int i = 0; i < a->mesh.length; i++) {
      offsetVector(&a->mesh.mesh[i].a, a->transform.velocity, dt);
      offsetVector(&a->mesh.mesh[i].a, a->transform.velocity, dt);
      offsetVector(&a->mesh.mesh[i].a, a->transform.velocity, dt);
      offsetVector(&a->mesh.mesh[i].a, a->transform.velocity, dt);
   }

   // Step 5: Apply rotational velocity
   for (int i = 0; i < a->mesh.length; i++) {
      a->mesh.mesh[i].a = OFD_Vector4_Rotate(a->mesh.mesh[i].a, a->transform.center_of_mass, a->transform.rotation);
      a->mesh.mesh[i].b = OFD_Vector4_Rotate(a->mesh.mesh[i].b, a->transform.center_of_mass, a->transform.rotation);
      a->mesh.mesh[i].c = OFD_Vector4_Rotate(a->mesh.mesh[i].c, a->transform.center_of_mass, a->transform.rotation);
      a->mesh.mesh[i].d = OFD_Vector4_Rotate(a->mesh.mesh[i].d, a->transform.center_of_mass, a->transform.rotation);
   }

}


static void offsetVector(OFD_Vector4* a, OFD_Vector4 velocity, double dt) {
   a->x += velocity.x * dt;
   a->y += velocity.y * dt;
   a->z += velocity.z * dt;
   a->w += velocity.w * dt;
}


void OFD_ApplyRigidbodyImpulse(OFD_Rigidbody* a, OFD_Vector4 collisionsPoint[]) {



}