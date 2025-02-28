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

static OFD_Triangle3D triangleFromPoints(OFD_Vector3 a, OFD_Vector3 b, OFD_Vector3 c);
static OFD_Vector3 inter(OFD_Vector4 a, OFD_Vector4 b);
static double* toArray(OFD_Vector3 p);
static int sgn(double x);

OFD_Triangle3D *OFD_SliceTetrahedron(OFD_Tetrahedron t, double w) {
   if (t.a.w < w && t.b.w < w && t.c.w < w && t.d.w < w) return NULL;
   if (t.a.w > w && t.b.w > w && t.c.w > w && t.d.w > w) return NULL;
   
   int sa = sgn(t.a.w - w); int sb = sgn(t.b.w - w); int sc = sgn(t.c.w - w); int sd = sgn(t.d.w - w);

   if (sa != sb && sa != sc && sa != sd) {
      OFD_Triangle3D *out = malloc(sizeof(OFD_Triangle3D));
      *out = triangleFromPoints(inter(t.a, t.b), inter(t.a, t.c), inter(t.a, t.d));
      return out;
   }
   if (sb != sa && sb != sc && sb != sd) {
      OFD_Triangle3D *out = malloc(sizeof(OFD_Triangle3D));
      *out = triangleFromPoints(inter(t.a, t.b), inter(t.a, t.c), inter(t.a, t.d));
      return out;
   }
   if (sc != sa && sc != sb && sc != sd) {
      OFD_Triangle3D *out = malloc(sizeof(OFD_Triangle3D));
      *out = triangleFromPoints(inter(t.a, t.b), inter(t.a, t.c), inter(t.a, t.d));
      return out;
   }
   if (sd != sa && sd != sb && sd != sc) {
      OFD_Triangle3D *out = malloc(sizeof(OFD_Triangle3D));
      *out = triangleFromPoints(inter(t.a, t.b), inter(t.a, t.c), inter(t.a, t.d));
      return out;
   }
   


}

static OFD_Triangle3D triangleFromPoints(OFD_Vector3 a, OFD_Vector3 b, OFD_Vector3 c) {
   OFD_Triangle3D out;
   out.a = a;
   out.b = b;
   out.c = c;
   return out;
}

static OFD_Vector3 inter(OFD_Vector4 a, OFD_Vector4 b) {

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
