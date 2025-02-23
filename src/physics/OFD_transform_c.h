

#ifndef OFD_transform_c_h_
#define OFD_transform_c_h_


#include "../math/OFD_vector_c.h"



typedef struct {
    OFD_Vector4 position;
    OFD_Vector4 velocity;
    OFD_Vector6 angularVelocity;
} OFD_Transform;



#endif // OFD_transform_c_h_