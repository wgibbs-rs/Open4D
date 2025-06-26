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

static OFD_Triangle3D triangleFromPoints(OFD_Vector3 a, OFD_Vector3 b, OFD_Vector3 c);
static OFD_Vector3 inter(OFD_Vector4 a, OFD_Vector4 b, double w);
static double* toArray(OFD_Vector3 p);
static int sgn(double x);

OFD_Triangle3D *OFD_SliceTetrahedron(OFD_Tetrahedron t, double w) {

   // First, we'll test to see if the shape even intersects with this w-position. 
   // If not, we can just return immediately.
   if (t.a.w < w && t.b.w < w && t.c.w < w && t.d.w < w) return NULL;
   if (t.a.w > w && t.b.w > w && t.c.w > w && t.d.w > w) return NULL;
   
   // Next, we'll get the signum of each value relative to the w position we're slicing at.
   int sa = sgn(t.a.w - w); int sb = sgn(t.b.w - w); int sc = sgn(t.c.w - w); int sd = sgn(t.d.w - w);

   // Next, we'll test for cases where only one point crosses the w-position. 
   // In this case, we can just return a single triangle where all three opposing 
   // points connect to the other.
   if (sa != sb && sa != sc && sa != sd) {
      OFD_Triangle3D *out = malloc(sizeof(OFD_Triangle3D));
      *out = (OFD_Triangle3D){inter(t.a, t.b, w), inter(t.a, t.c, w), inter(t.a, t.d, w)};
      return out;
   }
   if (sb != sa && sb != sc && sb != sd) {
      OFD_Triangle3D *out = malloc(sizeof(OFD_Triangle3D));
      *out = (OFD_Triangle3D){inter(t.b, t.a, w), inter(t.b, t.c, w), inter(t.b, t.d, w)};
      return out;
   }
   if (sc != sa && sc != sb && sc != sd) {
      OFD_Triangle3D *out = malloc(sizeof(OFD_Triangle3D));
      *out = (OFD_Triangle3D){inter(t.c, t.a, w), inter(t.c, t.b, w), inter(t.c, t.d, w)};
      return out;
   }
   if (sd != sa && sd != sb && sd != sc) {
      OFD_Triangle3D *out = malloc(sizeof(OFD_Triangle3D));
      *out = (OFD_Triangle3D){inter(t.d, t.a, w), inter(t.d, t.b, w), inter(t.d, t.c, w)};
      return out;
   }

   // Finally, we'll test for cases where two points are on each side.
   // In this case, we return two triangles.
   if (sa == sb && sc == sd) { // A and B are opposite to C and D
      OFD_Triangle3D *out = malloc(2 * sizeof(OFD_Triangle3D));
      out[0] = (OFD_Triangle3D){inter(t.a, t.c, w), inter(t.a, t.d, w), inter(t.b, t.c, w)};
      out[1] = (OFD_Triangle3D){inter(t.b, t.c, w), inter(t.b, t.d, w), inter(t.a, t.d, w)};
      return out;
   }
   if (sa == sc && sb == sd) { // A and C are opposite to B and D
      OFD_Triangle3D *out = malloc(2 * sizeof(OFD_Triangle3D));
      out[0] = (OFD_Triangle3D){inter(t.a, t.b, w), inter(t.a, t.d, w), inter(t.c, t.b, w)};
      out[1] = (OFD_Triangle3D){inter(t.c, t.b, w), inter(t.c, t.d, w), inter(t.a, t.d, w)};
      return out;
   }
   if (sa == sd && sb == sc) { // A and D are opposite to B and C
      OFD_Triangle3D *out = malloc(2 * sizeof(OFD_Triangle3D));
      out[0] = (OFD_Triangle3D){inter(t.a, t.b, w), inter(t.a, t.c, w), inter(t.d, t.b, w)};
      out[1] = (OFD_Triangle3D){inter(t.d, t.b, w), inter(t.d, t.c, w), inter(t.a, t.c, w)};
      return out;
   }


   // If all else fails, we'll need to print this to notify the user that some error
   // must have occurred. Reaching this point is normally impossible.
   printf("When slicing a mesh, no result was reached. Returning NULL.\n\nPlease report this error to the official Open4D Github at https://github.com/wgibbs-rs/Open4D.");
   return NULL;
   
}

static OFD_Vector3 inter(OFD_Vector4 a, OFD_Vector4 b, double w) {
   double percent = (w - a.w) / (b.w - a.w);
   return (OFD_Vector3){
      percent * (b.x - a.x) + a.x,
      percent * (b.y - a.y) + a.y,
      percent * (b.z - a.z) + a.z
   };
}



static OFD_Triangle3D triangleFromPoints(OFD_Vector3 a, OFD_Vector3 b, OFD_Vector3 c) {
   return (OFD_Triangle3D) {a, b, c};
}


static int sgn(double x) {
   if (x > 0) return 1;
   if (x < 0) return -1;
   return 0;
}

double* OFD_TriangleToX(OFD_Triangle3D tri) {
   double* a = malloc(3 * sizeof(double));
   if (!a) return NULL;
   a[0] = tri.a.x; a[1] = tri.b.x; a[2] = tri.c.x;
   return a;
}

double* OFD_TriangleToY(OFD_Triangle3D tri) {
   double* a = malloc(3 * sizeof(double));
   if (!a) return NULL;
   a[0] = tri.a.y; a[1] = tri.b.y; a[2] = tri.c.y;
   return a;
}


double* OFD_TriangleToZ(OFD_Triangle3D tri) {
   double* a = malloc(3 * sizeof(double));
   if (!a) return NULL;
   a[0] = tri.a.z; a[1] = tri.b.z; a[2] = tri.c.z;
   return a;
}
