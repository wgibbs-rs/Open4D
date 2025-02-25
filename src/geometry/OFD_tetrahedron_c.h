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

#ifndef OFD_tetrahedron_c_h_
#define OFD_tetrahedron_c_h_

#include "../util/OFD_vector_c.h"

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



/** @brief Defines a triangle in 3D space. */
typedef struct {
   OFD_Vector3 a, b, c;
} OFD_Triangle3D;

typedef struct {
   int count;
   OFD_Triangle3D mesh[];
} OFD_Triangle3DArray;



/** @brief Slices a 4D tetrahedron, returning a 3D face.
 * 
 * Given the simplicity of tetrahedrons, we can easily slice them across the fourth dimension.
 * Given a set of parameters, we return either one or two triangles, creating the (up to)
 * 4-point shape that results from slicing a tetrahedron.
 * 
 * @return Either one or two triangles. Will always be treated as an array.
 */
static inline OFD_Triangle3DArray OFD_SliceTetrahedron(OFD_Tetrahedron a, double w);


/** @brief Returns a triangle's vertices' X positions. */
static inline double* OFD_TriangleToX(OFD_Triangle3D tri);
/** @brief Returns a triangle's vertices' Y positions. */
static inline double* OFD_TriangleToY(OFD_Triangle3D tri);
/** @brief Returns a triangle's vertices' Z positions. */
static inline double* OFD_TriangleToZ(OFD_Triangle3D tri);
/** @brief Returns each vertex as an array. */
static inline double* OFD_TriangleToArray(OFD_Triangle3D tri);


#endif // OFD_tetrahedron_c_h_