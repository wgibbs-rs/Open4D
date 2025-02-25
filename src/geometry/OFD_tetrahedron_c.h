
#ifndef OFD_tetrahedron_c_h_
#define OFD_tetrahedron_c_h_

#include "../util/OFD_vector_c.h"
#include "OFD_triangle_c.h"

/** @brief Defines a tetrahedron made of four 4D points. Each point is stored as an OFD_Vector4
 * 
 * Open4D geometry relies on objects made of tetrahedrons. This allows for simpler
 * slicing and physics. Geometry such as tesseracts, hyperdodecahedrons, and 
 * hyperspheres can be easily converted to tetrehedrons by taking each face and connecting it
 * to the center point. This results in many tetrahedrons that make up our 4D structure.
 */
typedef struct {
    OFD_Vector4 a, b, c, d;
} OFD_Tetrahedron;


/** @brief Slices a 4D tetrahedron, returning a 3D face.
 * 
 * Given the simplicity of tetrahedrons, we can easily slice them across the fourth dimension.
 * Given a set of parameters, we return either one or two triangles, creating the (up to)
 * 4-point shape that results from slicing a tetrahedron.
 * 
 * @return Either one or two triangles. Will always be treated as an array.
 */
static inline OFD_Triangle3D* OFD_SliceTetrahedron(OFD_Tetrahedron g);


#endif // OFD_tetrahedron_c_h_