

#ifndef OFD_triangle_c_h_
#define OFD_triangle_c_h_


#include "../math/OFD_vector_c.h"

/** @brief Stores information on a 3D triangle's vertices. */
typedef struct {
    OFD_Vector3 a, b, c;
} OFD_Triangle3D;



#endif // OFD_triangle_c_h_