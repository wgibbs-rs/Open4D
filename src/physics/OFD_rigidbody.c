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


extern inline void OFD_SetRigidbodyPosition(OFD_Rigidbody* obj, OFD_Vector4 target) {
   OFD_Vector4 d_pos = OFD_Vector4_Subtract(target, obj->transform.position);
   obj->transform.position = target;
   for (int i = 0; i < obj->mesh.length; i++) {
      obj->mesh.mesh[i].a = OFD_Vector4_Add(obj->mesh.mesh[i].a, d_pos);
      obj->mesh.mesh[i].b = OFD_Vector4_Add(obj->mesh.mesh[i].b, d_pos);
      obj->mesh.mesh[i].c = OFD_Vector4_Add(obj->mesh.mesh[i].c, d_pos);
      obj->mesh.mesh[i].d = OFD_Vector4_Add(obj->mesh.mesh[i].d, d_pos);
   }
}

extern inline void OFD_SetRigidbodyRotation(OFD_Rigidbody* obj, OFD_Vector6 deg) {
   OFD_Vector6 d_rot = (OFD_Vector6){
      deg.xy - obj->transform.rotation.xy,
      deg.xz - obj->transform.rotation.xz,
      deg.xw - obj->transform.rotation.xw,
      deg.yz - obj->transform.rotation.yz,
      deg.yw - obj->transform.rotation.yw,
      deg.zw - obj->transform.rotation.zw
   };
   obj->transform.rotation = deg;
   for (int i = 0; i < obj->mesh.length; i++) {
      obj->mesh.mesh[i].a = OFD_Vector4_Rotate(obj->mesh.mesh[i].a, obj->transform.position, d_rot);
      obj->mesh.mesh[i].b = OFD_Vector4_Rotate(obj->mesh.mesh[i].b, obj->transform.position, d_rot);
      obj->mesh.mesh[i].c = OFD_Vector4_Rotate(obj->mesh.mesh[i].c, obj->transform.position, d_rot);
      obj->mesh.mesh[i].d = OFD_Vector4_Rotate(obj->mesh.mesh[i].d, obj->transform.position, d_rot);
   }
}

extern inline void OFD_ApplyRigidbodyTranslationalVelocity(OFD_Rigidbody* obj, const double dt) {
   OFD_SetRigidbodyPosition(
      obj,
      (OFD_Vector4){
         obj->transform.position.x + obj->transform.velocity.x * dt,
         obj->transform.position.y + obj->transform.velocity.y * dt,
         obj->transform.position.z + obj->transform.velocity.z * dt,
         obj->transform.position.w + obj->transform.velocity.w * dt
      }
   );
}

extern inline void OFD_ApplyRigidbodyRotationalVelocity(OFD_Rigidbody* obj, const double dt) {
   OFD_SetRigidbodyRotation(
      obj,
      (OFD_Vector6){
         obj->transform.rotation.xy + obj->transform.angular_velocity.xy * dt,
         obj->transform.rotation.xz + obj->transform.angular_velocity.xz * dt,
         obj->transform.rotation.xw + obj->transform.angular_velocity.xw * dt,
         obj->transform.rotation.yz + obj->transform.angular_velocity.yz * dt,
         obj->transform.rotation.yw + obj->transform.angular_velocity.yw * dt,
         obj->transform.rotation.zw + obj->transform.angular_velocity.zw * dt
      }
   );
}

extern inline void OFD_AnimateRigidbody(OFD_Rigidbody* restrict a, OFD_Rigidbody* restrict env, const int envSize, const OFD_WorldParameters world, const double dt) {
   printf("Error: " RED "error: " RESET "Physics has not been implemented in this version.");
}


extern inline void OFD_ApplyRigidbodyImpulse(OFD_Rigidbody* a, const OFD_Vector4* collisionsPoints, const int collisionPointsLength) {
   printf("Error: " RED "error: " RESET "Physics has not been implemented in this version.");
}