


#ifndef OFD_rigidbody_c_h_
#define OFD_rigidbody_c_h_


#include "OFD_transform_c.h"
#include "../geometry/OFD_mesh_c.h"

/** @brief Stored information on a given physics object. */
typedef struct {
    OFD_Transform transform;
    OFD_Mesh mesh;
} OFD_Rigidbody;

/** @brief Animates a rigidbody by a time interval (dt). */
static inline void OFD_AnimateRigidbody(OFD_Rigidbody* a, OFD_Rigidbody other[], double dt);


#endif // OFD_rigidbody_c_h_