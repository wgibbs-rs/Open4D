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


#include <Open4D/OFD_geometry.h>
#include <Open4D/OFD_test.h>

#include <stdlib.h>
#include <limits.h>

void test_inter() {

    OFD_Vector4 a = {1, 2, 3, 4};
    OFD_Vector4 b = {4, 3, 2, 1};

    OFD_Vector3 out = inter(a, b, 2.5);

    OFD_Assert(
        out.x == 2.5 &&
        out.y == 2.5 &&
        out.z == 2.5,
        "inter #1"
    );

    out = inter(a, b, 4);

    OFD_Assert(
        out.x == 1 &&
        out.y == 2 &&
        out.z == 3,
        "inter #2"
    );

    out = inter(a, b, 1);

    OFD_Assert(
        out.x == 4 &&
        out.y == 3 &&
        out.z == 2,
        "inter #3"
    );

    // Ensure inter does not fail with invalid inputs:

    // CASE: A and B are the same
    b = (OFD_Vector4){1, 2, 3, 4};
    out = inter(a, b, 1);
    OFD_Assert( !out.x && !out.y && !out.z, "inter #4");

}


void test_sgn() {

    OFD_Assert(sgn(5) > 0, "sgn #1");
    OFD_Assert(sgn(-5) < 0, "sgn #2");
    OFD_Assert(sgn(0) == 0, "sgn #3");

    OFD_Assert(sgn(1e-9) > 0, "sgn #4");
    OFD_Assert(sgn(INT_MAX) > 0, "sgn #5");
    OFD_Assert(sgn(INT_MIN) < 0, "sgn #6");

}


void test_slice_tetrahedron() {

    // Testing a normal tetrahedron
    OFD_Tetrahedron t;
    OFD_TriangleArray tri;
    OFD_Vector3 point_one, point_two, point_thr;

    t = (OFD_Tetrahedron) {
        (OFD_Vector4){1, 2, 3, -4},
        (OFD_Vector4){4, 1, 2, -1},
        (OFD_Vector4){5, 6, 7, -8},
        (OFD_Vector4){4, 3, 2, 1} // Why does this only work when d.w > 6?
    };

    tri = OFD_SliceTetrahedron(t, 0);
    OFD_Assert(tri.length == 1, "OFD_SliceTetrahedron #1 (length)");

    point_one = inter( t.a, t.d, 0 );
    point_two = inter( t.b, t.d, 0 );
    point_thr = inter( t.c, t.d, 0 );
    
    OFD_Assert(
        (neareq(tri.triangles[0].a.x, point_one.x) +
         neareq(tri.triangles[0].a.x, point_two.x) +
         neareq(tri.triangles[0].a.x, point_thr.x)) == 1 &&
        (neareq(tri.triangles[0].a.y, point_one.y) +
         neareq(tri.triangles[0].a.y, point_two.y) +
         neareq(tri.triangles[0].a.y, point_thr.y)) == 1 &&
        (neareq(tri.triangles[0].a.z, point_one.z) +
         neareq(tri.triangles[0].a.z, point_two.z) +
         neareq(tri.triangles[0].a.z, point_thr.z)) == 1,

        "OFD_SliceTetrahedron #1 (a)"
    );
    OFD_Assert(
        (neareq(tri.triangles[0].b.x, point_one.x) +
         neareq(tri.triangles[0].b.x, point_two.x) +
         neareq(tri.triangles[0].b.x, point_thr.x)) == 1 &&
        (neareq(tri.triangles[0].b.y, point_one.y) +
         neareq(tri.triangles[0].b.y, point_two.y) +
         neareq(tri.triangles[0].b.y, point_thr.y)) == 1 &&
        (neareq(tri.triangles[0].b.z, point_one.z) +
         neareq(tri.triangles[0].b.z, point_two.z) +
         neareq(tri.triangles[0].b.z, point_thr.z)) == 1,

        "OFD_SliceTetrahedron #1 (b)"
    );
    OFD_Assert(
        (neareq(tri.triangles[0].c.x, point_one.x) +
         neareq(tri.triangles[0].c.x, point_two.x) +
         neareq(tri.triangles[0].c.x, point_thr.x)) == 1 &&
        (neareq(tri.triangles[0].c.y, point_one.y) +
         neareq(tri.triangles[0].c.y, point_two.y) +
         neareq(tri.triangles[0].c.y, point_thr.y)) == 1 &&
        (neareq(tri.triangles[0].c.z, point_one.z) +
         neareq(tri.triangles[0].c.z, point_two.z) +
         neareq(tri.triangles[0].c.z, point_thr.z)) == 1,

        "OFD_SliceTetrahedron #1 (c)"
    );
    
}

int main() {

    test_inter();
    test_sgn();

    test_slice_tetrahedron();

}