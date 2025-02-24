

#ifndef OFD_transform_c_h_
#define OFD_transform_c_h_

#include "../math/OFD_vector_c.h"
#include "../geometry/OFD_mesh_c.h"
#include "OFD_rigidbody_c.h"
#include <stdlib.h>

typedef struct {

    /** @brief The spatial position of this object in 4D space. */
    OFD_Vector4 position;
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
    double inertiaTensor[4][4];

} OFD_Transform;


static inline OFD_Transform OFD_DefaultTransform(OFD_Mesh mesh) {
    OFD_Transform o;
    o.mass = 1;
    o.restitution = 0;
    o.kineticFriction = 0.5;
    o.staticFriction = 0.5;
    double* uniformIneria = OFD_UniformInertiaTensor(mesh);
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++)  o.inertiaTensor[i][j] = uniformIneria[i * 4 + j];
    free(uniformIneria);
    return o;
}


#endif // OFD_transform_c_h_