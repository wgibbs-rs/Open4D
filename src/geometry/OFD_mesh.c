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

#include "Open4D/OFD_geometry.h"
#include <stdlib.h>
#include <stdio.h>

struct OFD_RegularMesh OFD_regular_mesh[] = {
   [FIVE_CELL] = {3, 3, 3},
   [EIGHT_CELL] = {4, 3, 3},
   [SIXTEEN_CELL] = {3, 3, 4},
   [TWENTY_FOUR_CELL] = {3, 4, 3},
   [ONE_TWENTY_CELL] = {5, 3, 3},
   [SIX_HUNDRED_CELL] = {3, 3, 5}
};


OFD_TriangleArray OFD_SliceMesh(const OFD_Mesh mesh, const float w) { 
   OFD_TriangleArray out;

   // Iterate through all tetrahedrons and add their slice to a mesh.
   for (int i = 0; i < mesh.length; i++) { 
      OFD_TriangleArray slice = OFD_SliceTetrahedron(mesh.mesh[i], w);

      if (slice.length == 0) continue;

      out.triangles = realloc(out.triangles, (out.length + slice.length)  * sizeof(OFD_Triangle3D));

      // If no "out" after realloc, then we free them both and return NULL.
      if (!out.triangles) { 
         free(slice.triangles);
         free(out.triangles);
         return (OFD_TriangleArray){0, NULL}; // And we'll need to indicate failure.
      }

      // out.length is still the old value, so we can use it to append out new triangles.
      out.triangles[out.length] = slice.triangles[0];
      if (slice.length == 2) out.triangles[out.length + 1] = slice.triangles[1];

      out.length += slice.length;
      free(slice.triangles);
   }
   return out;
}
