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

#ifndef OFD_physics_h_
#define OFD_physics_h_



#include <Open4D/OFD_physics.h>
#include <Open4D/OFD_math.h>
#include <Open4D/OFD_geometry.h>

/** @brief Finds collision points on a given mesh in an environment of other collidable structures. */
extern OFD_Vector4* OFD_GetCollisionPoints(const OFD_Mesh mesh, const OFD_Mesh* env);

/** @brief Tests if two tetrahedrons are colliding, and returns the collision point. */
extern OFD_Vector4* OFD_TestTetrahedronCollision(OFD_Tetrahedron a, OFD_Tetrahedron b);



typedef struct {

   /** @brief The spatial position of this object in 4D space. */
   OFD_Vector4 position;

   /** @brief The center of mass of this object. */
   OFD_Vector4 center_of_mass;

   /** @brief The translational velocity of this object in 4D space. (m/s) */
   OFD_Vector4 velocity;

   /** @brief The current rotation of the object from it's initial position. (degrees) */
   OFD_Vector6 rotation;

   /** @brief The angular velocity of this object in 4D space. (degrees) */
   OFD_Vector6 angular_velocity;

   /** @brief The mass of the object's structure. (kg) */
   float mass;

   /** @brief The Restitution of this object. (no unit) */
   float restitution;

   /** @brief The resistance of an object to initiation of motion. (no unit)
    * 
    * A simulation can contain many objects of varying frictional proportions, therefore each
    * object is assigned a frictional value, which will be used when in contact with another object.
    */
   float static_friction;
   /** @brief The resistance of an object to sliding motions. (no unit)
    * 
    * A simulation can contain many objects of varying frictional proportions, therefor each
    * object is assigned a friction value, which will be used when in contact with another object.
    */
   float kinetic_friction;

   /** @brief The resistance of an object to rolling motion. (no unit) */
   float rolling_friction;

   /** @brief The Moment Of Inertia tensor of the object. (kg • m^2) */
   float inertia;

} OFD_Transform;


extern const OFD_Transform OFD_DEFAULT_TRANSFORM;


/** @brief Stored information on a given physics object. */
typedef struct {
   OFD_Transform transform;
   OFD_Mesh mesh;
} OFD_Rigidbody;



/** @brief Defines parameters for world physics variables, like the constant of gravitational acceleration. */
typedef struct {
   float gravity;
} OFD_WorldParameters;


/** @brief Defines default world parameters.
 * 
 * - Gravitational Acceleration (g): 9.80665 (m/s^2)
 */
extern const OFD_WorldParameters OFD_DEFAULT_WORLD;



/** @brief Moves a single OFD_Rigidbody to a new location, adjusting it's mesh and transform. */
extern inline void OFD_SetRigidbodyPosition(OFD_Rigidbody* obj, OFD_Vector4 target);

/** @brief Rotates a single OFD_Rigidbody to a target orientation, adjusting mesh and transform. */
extern inline void OFD_SetRigidbodyRotation(OFD_Rigidbody* obj, OFD_Vector6 deg);

/** @brief Applies the velocity of a rigidbody to its position based on change in time. */
extern inline void OFD_ApplyRigidbodyTranslationalVelocity(OFD_Rigidbody* obj, const float dt);

/** @brief Applies the angular velocity of a rigidbody to its orientation based on change in time. */
extern inline void OFD_ApplyRigidbodyRotationalVelocity(OFD_Rigidbody* obj, const float dt);


/** @brief Animates a rigidbody by a time interval (dt). */
extern inline void OFD_AnimateRigidbody(
   OFD_Rigidbody* restrict a, 
   OFD_Rigidbody* restrict env, 
   const int envSize, 
   const OFD_WorldParameters world, 
   const float dt
);


/** @brief Calculates the moment of inertia for a geometry, given that mass is uniformly distributed. */
extern inline float OFD_UniformInertiaTensor(const OFD_Mesh mesh);

/** @brief Calculates and updates the velocities of a given object based on a collision impulse. */
extern inline void OFD_ApplyRigidbodyImpulse(
   OFD_Rigidbody* a, 
   const OFD_Vector4* collisionsPoints, 
   const int collisionPointsLength
);


#endif // OFD_physics_h_