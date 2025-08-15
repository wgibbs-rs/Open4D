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


#ifdef TESTING
#define TEST_STATIC
#else
#define TEST_STATIC static
#endif

// If testing, this is not static, and is defined in OFD_geometry, otherwise it is internal.
TEST_STATIC OFD_Vector3 inter(OFD_Vector4 a, OFD_Vector4 b, float w);
TEST_STATIC int sgn(float x);


OFD_TriangleArray OFD_SliceTetrahedron(const OFD_Tetrahedron t, const float w) {

   OFD_TriangleArray out;

   // First, we'll test to see if the shape even intersects with this w-position. 
   // If not, we can just return immediately.
   if (!(t.a.w > w || t.b.w > w || t.c.w > w || t.d.w > w)) return (OFD_TriangleArray){0, NULL};
   if (!(t.a.w < w || t.b.w < w || t.c.w < w || t.d.w < w)) return (OFD_TriangleArray){0, NULL};
   
   // Next, we'll get the signum of each value relative to the w position we're slicing at.
   int sa = sgn(t.a.w - w); int sb = sgn(t.b.w - w); int sc = sgn(t.c.w - w); int sd = sgn(t.d.w - w);

   // Next, we'll test for cases where only one point crosses the w-position. 
   // In this case, we can just return a single triangle where all three opposing 
   // points connect to the other.
   if (!(sa == sb || sa == sc || sa == sd)) {
      out = (OFD_TriangleArray){1, malloc(sizeof(OFD_Triangle3D))};
      if (!out.triangles) return (OFD_TriangleArray){0, NULL};
      *out.triangles = (OFD_Triangle3D){inter(t.a, t.b, w), inter(t.a, t.c, w), inter(t.a, t.d, w)};
      return out;
   }
   if (!(sb == sa || sb == sc || sb == sd)) {
      out = (OFD_TriangleArray){1, malloc(sizeof(OFD_Triangle3D))};
      if (!out.triangles) return (OFD_TriangleArray){0, NULL};
      *out.triangles = (OFD_Triangle3D){inter(t.b, t.a, w), inter(t.b, t.c, w), inter(t.b, t.d, w)};
      return out;
   }
   if (!(sc == sa || sc == sb || sc == sd)) {
      out = (OFD_TriangleArray){1, malloc(sizeof(OFD_Triangle3D))};
      if (!out.triangles) return (OFD_TriangleArray){0, NULL};
      *out.triangles = (OFD_Triangle3D){inter(t.c, t.a, w), inter(t.c, t.b, w), inter(t.c, t.d, w)};
      return out;
   }
   if (!(sd == sa || sd == sb || sd == sc)) {
      out = (OFD_TriangleArray){1, malloc(sizeof(OFD_Triangle3D))};
      if (!out.triangles) return (OFD_TriangleArray){0, NULL};
      *out.triangles = (OFD_Triangle3D){inter(t.d, t.a, w), inter(t.d, t.b, w), inter(t.d, t.c, w)};
      return out;
   }

   // Finally, we'll test for cases where two points are on each side.
   // In this case, we return two triangles.
   out = (OFD_TriangleArray){2, malloc(2 * sizeof(OFD_Triangle3D))};
   if (!out.triangles) return (OFD_TriangleArray){0, NULL};
   if (sa == sb && sc == sd) { // A and B are opposite to C and D
      out.triangles[0] = (OFD_Triangle3D){inter(t.a, t.c, w), inter(t.a, t.d, w), inter(t.b, t.c, w)};
      out.triangles[1] = (OFD_Triangle3D){inter(t.b, t.c, w), inter(t.b, t.d, w), inter(t.a, t.d, w)};
   }
   if (sa == sc && sb == sd) { // A and C are opposite to B and D
      out.triangles[0] = (OFD_Triangle3D){inter(t.a, t.b, w), inter(t.a, t.d, w), inter(t.c, t.b, w)};
      out.triangles[1] = (OFD_Triangle3D){inter(t.c, t.b, w), inter(t.c, t.d, w), inter(t.a, t.d, w)};
   }
   if (sa == sd && sb == sc) { // A and D are opposite to B and C
      out.triangles[0] = (OFD_Triangle3D){inter(t.a, t.b, w), inter(t.a, t.c, w), inter(t.d, t.b, w)};
      out.triangles[1] = (OFD_Triangle3D){inter(t.d, t.b, w), inter(t.d, t.c, w), inter(t.a, t.c, w)};
   }
   return out;

   // This shouldn't be reachable.
}

#if defined(__GNUC__) || defined(__clang__)
__attribute__((const))
#endif
TEST_STATIC OFD_Vector3 inter(OFD_Vector4 a, OFD_Vector4 b, float w) {
   if (a.w == b.w) return (OFD_Vector3){0, 0, 0};
   float percent = (w - a.w) / (b.w - a.w);
   return (OFD_Vector3){
      percent * (b.x - a.x) + a.x,
      percent * (b.y - a.y) + a.y,
      percent * (b.z - a.z) + a.z
   };
}

#if defined(__GNUC__) || defined(__clang__)
__attribute__((const))
#endif
inline TEST_STATIC int sgn(float x) { return (x > 0) - (x < 0); }