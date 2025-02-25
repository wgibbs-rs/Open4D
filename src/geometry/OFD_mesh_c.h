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

#ifndef OFD_mesh_c_h_
#define OFD_mesh_c_h_

#include "OFD_tetrahedron_c.h"


/** @brief Defines the structure for an object's geometry. */
typedef struct {
   OFD_Tetrahedron *mesh;
} OFD_Mesh;


/** @brief Slices a 4D mesh into an array of 3D triangles. */
static inline OFD_Triangle3D* OFD_SliceMesh(OFD_Mesh mesh, double w);

#endif // OFD_mesh_c_h_