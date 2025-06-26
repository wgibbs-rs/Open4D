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

#ifndef OFD_geometry_h_
#define OFD_geometry_h_



#ifdef _WIN32
  #ifdef OPEN4D_EXPORTS
    #define OPEN4D_API __declspec(dllexport)
  #else
    #define OPEN4D_API __declspec(dllimport)
  #endif
#else
  #define OPEN4D_API __attribute__((visibility("default")))
#endif



#include <Open4D/OFD_util.h>


/** @brief Defines a tetrahedron made of four 4D points. Each point is stored as an OFD_Vector4
 * s
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




/** @brief Defines the structure for an object's geometry. */
typedef struct {
   int length;
   OFD_Tetrahedron *mesh;
} OFD_Mesh;



/** @brief Slices a 4D mesh, returning a set of 3D faces.
 * 
 * This function uses OFD_SliceTetrahedron on all tetrahedrons in this mesh. From there,
 * it returns an pointer to an array of 3D faces.
 * 
 * @return Either one or two triangles. Will always be treated as an array.
 */
extern OPEN4D_API OFD_Triangle3D *OFD_SliceMesh(OFD_Mesh mesh, double w);


/** @brief Slices a 4D tetrahedron, returning a 3D face.
 * 
 * Given the simplicity of tetrahedrons, we can easily slice them across the fourth dimension.
 * Given a set of parameters, we return either one or two triangles, creating the (up to)
 * 4-point shape that results from slicing a tetrahedron.
 * 
 * @return Either one or two triangles. Will always be treated as an array.
 */
extern OPEN4D_API OFD_Triangle3D *OFD_SliceTetrahedron(OFD_Tetrahedron a, double w);


/** @brief Returns a triangle's vertices' X positions. */
extern OPEN4D_API double* OFD_TriangleToX(OFD_Triangle3D tri);
/** @brief Returns a triangle's vertices' Y positions. */
extern OPEN4D_API double* OFD_TriangleToY(OFD_Triangle3D tri);
/** @brief Returns a triangle's vertices' Z positions. */
extern OPEN4D_API double* OFD_TriangleToZ(OFD_Triangle3D tri);


// Define enum for the cells
enum OFD_Cell {
   FIVE_CELL,
   EIGHT_CELL,
   SIXTEEN_CELL,
   TWENTY_FOUR_CELL,
   ONE_TWENTY_CELL,
   SIX_HUNDRED_CELL
};


// Defined to allow for the OFD_regular_mesh
struct OPEN4D_API OFD_RegularMesh {
   int values[3];
};

/** @brief Defines the Schläfli Symbol for a given regular polytope.
 * 
 * Each polytope is provided by name, rather than index. To read the schläfli symbol of a given
 * polytope, call OFD_regular_mesh[NAME_CELL];
 * 
 * The available polytopes are:
 * 
 * - FIVE_CELL: 5-Cell, also known as the 4-simplex, is the simplest structure defined in
 * 4D space. It contains 5 cells.
 * 
 * - EIGHT_CELL: 8-Cell, also known as the Tesseract, is the 4D equivalent of a cube.
 * 
 * - SIXTEEN_CELL: 16-Cell, also known as the hexadecachoron, is the simplest structure in 4D
 * space that has no 3D or 2D equivalent.
 * 
 * - TWENTY_FOUR_CELL: 24-Cell, also known as the hyper-diamond, contains 24 octohedral cells.
 * 
 * - ONE_TWENTY_CELL: 120-Cell, also known as the hyper-dodecahedron, contains 120 dodecahedral
 * cells. It's the 4D equivalent of the dodecahedron, similar to how the regular dodecahedron is
 * the 3D equivalent of the pentagon.
 * 
 * - SIX_HUNDRED_CELL: 600-Cell, also known as the hexicosachoron, contains 600 tetrahedral cells.
 * It is the dual-polytope of the 120-Cell.
*/
extern struct OPEN4D_API OFD_RegularMesh OFD_regular_mesh[6];


/** The 5-Cell, also known as the 4-simplex, is the simplest structure defined in 
 * 4D space. It contains 5 cells.  */
extern OPEN4D_API OFD_Mesh OFD_five_cell();
/** The 8-Cell, also known as the Tesseract, is the 4D equivalent of a cube. */
extern OPEN4D_API OFD_Mesh OFD_eight_cell();
/** The 16-Cell, also known as the hexadecachoron, is the simplest structure in 
 * 4D space that has no 3D or 2D equivalent. */
extern OPEN4D_API OFD_Mesh OFD_sixteen_cell();
/** The 24-Cell, also known as the hyper-diamond, contains 24 octohedral cells. */
extern OPEN4D_API OFD_Mesh OFD_twenty_four_cell();
/** The 120-Cell, also known as the hyper-dodecahedron, contains 
 * 120 dodecahedral cells. It's the 4D equivalent of the dodecahedron, 
 * similar to how the regular dodecahedron is the 3D equivalent of the pentagon. */
extern OPEN4D_API OFD_Mesh OFD_one_twenty_cell();
/** The 600-Cell, also known as the hexicosachoron, contains 600 tetrahedral cells.
 * It is the dual-polytope of the 120-Cell. */
extern OPEN4D_API OFD_Mesh OFD_six_hundred_cell();


#endif // OFD_geometry_h_