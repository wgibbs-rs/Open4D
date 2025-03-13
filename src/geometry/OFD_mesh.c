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


OFD_Triangle3D *OFD_SliceMesh(OFD_Mesh mesh, double w) { 
   OFD_Triangle3D *out = NULL;
   int count = 0;

   // Iterate through all tetrahedrons and add their slice to a mesh.
   for (int i = 0; i < mesh.length; i++) { 
      OFD_Triangle3D *slice = OFD_SliceTetrahedron(mesh.mesh[i], w);
      if (!slice) { continue; }

      int length = sizeof(slice) / sizeof(slice[0]);

      // Extend 'out' to account for new OFD_Triangle3D's.
      out = realloc(out, (count + length) * sizeof(OFD_Triangle3D));

      if (!out) { 
         free(slice);
         return NULL;
      }

      out[count] = slice[0];
      if (length == 2) {
         out[count + 1] = slice[1];
      }
      count += length;
      free(slice);
   }
   return out;
}