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

#ifndef OFD_transform_c_h_
#define OFD_transform_c_h_

#include "../util/OFD_vector_c.h"
#include "../geometry/OFD_mesh_c.h"
#include "OFD_rigidbody_c.h"


typedef struct {

    /** @brief The spatial position of this object in 4D space. */
    OFD_Vector4 position;

    /** @brief The center of mass of this object. */
    OFD_Vector4 centerOfMass;

    /** @brief The translational velocity of this object in 4D space. (m/s) */
    OFD_Vector4 velocity;

    /** @brief The current rotation of the object from it's initial position. (degrees) */
    OFD_Vector6 rotation;

    /** @brief The angular velocity of this object in 4D space. (degrees) */
    OFD_Vector6 angularVelocity;

    /** @brief The mass of the object's structure. (kg) */
    double mass;

    /** @brief The Restitution of this object. (no unit) */
    double restitution;

    /** @brief The resistance of an object to initiation of motion. (no unit)
     * 
     * A simulation can contain many objects of varying frictional proportions, therefore each
     * object is assigned a frictional value, which will be used when in contact with another object.
     */
    double staticFriction;
    /** @brief The resistance of an object to sliding motions. (no unit)
     * 
     * A simulation can contain many objects of varying frictional proportions, therefor each
     * object is assigned a friction value, which will be used when in contact with another object.
     */
    double kineticFriction;

    /** @brief The resistance of an object to rolling motion. (no unit) */
    double rollingFriction;

    /** @brief The Moment Of Inertia tensor of the object. (kg • m^2) */
    double inertia;

} OFD_Transform;


OFD_Transform OFD_DefaultTransform(OFD_Mesh mesh) {
    OFD_Transform o;
    o.mass = 1;
    o.restitution = 0;
    o.kineticFriction = 0.5;
    o.staticFriction = 0.5;
    return o;
}


#endif // OFD_transform_c_h_