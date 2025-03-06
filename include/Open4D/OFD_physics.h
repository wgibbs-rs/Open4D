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

#ifndef OFD_physics_h_
#define OFD_physics_h_

#include <Open4D/OFD_physics.h>
#include <Open4D/OFD_util.h>
#include <Open4D/OFD_geometry.h>

/** @brief Finds collision points on a given mesh in an environment of other collidable structures. */
extern OFD_Vector4* OFD_GetCollisionPoints(OFD_Mesh mesh, OFD_Mesh env[]);

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
   double mass;

   /** @brief The Restitution of this object. (no unit) */
   double restitution;

   /** @brief The resistance of an object to initiation of motion. (no unit)
    * 
    * A simulation can contain many objects of varying frictional proportions, therefore each
    * object is assigned a frictional value, which will be used when in contact with another object.
    */
   double static_friction;
   /** @brief The resistance of an object to sliding motions. (no unit)
    * 
    * A simulation can contain many objects of varying frictional proportions, therefor each
    * object is assigned a friction value, which will be used when in contact with another object.
    */
   double kinetic_friction;

   /** @brief The resistance of an object to rolling motion. (no unit) */
   double rolling_friction;

   /** @brief The Moment Of Inertia tensor of the object. (kg • m^2) */
   double inertia;

} OFD_Transform;


extern const OFD_Transform OFD_DEFAULT_TRANSFORM;


/** @brief Stored information on a given physics object. */
typedef struct {
   OFD_Transform transform;
   OFD_Mesh mesh;
} OFD_Rigidbody;



/** @brief Defines parameters for world physics variables, like the constant of gravitational acceleration. */
typedef struct {
   double gravity;
} OFD_WorldParameters;


/** @brief Defines default world parameters.
 * 
 * - Gravitational Acceleration (g): 9.80665 (m/s^2)
 */
static const OFD_WorldParameters OFD_DEFAULT_WORLD = { 9.80665 };




/** @brief Animates a rigidbody by a time interval (dt). */
extern void OFD_AnimateRigidbody(OFD_Rigidbody* a, OFD_Mesh other[], OFD_WorldParameters world, double dt);

/** @brief Calculates the moment of inertia for a geometry, given that mass is uniformly distributed. */
extern double OFD_UniformInertiaTensor(OFD_Mesh mesh);

/** @brief Calculates and updates the velocities of a given object based on a collision impulse. */
extern void OFD_ApplyRigidbodyImpulse(OFD_Rigidbody* a, OFD_Vector4 collisionsPoint[]);




#endif // OFD_physics_h_