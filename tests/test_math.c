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


#include <Open4D/OFD_util.h>
#include <Open4D/OFD_test.h>

#include "math.h"

// OFD_Vector2_Magnitude(OFD_Vector2 x);
void test_vector2_magnitude() {
   OFD_Assert(OFD_Vector2_Magnitude((OFD_Vector2){3, 4}) == 5, "OFD_Vector2_Magnitude #1");
   OFD_Assert(OFD_Vector2_Magnitude((OFD_Vector2){1, 0}) == 1, "OFD_Vector2_Magnitude #2");
   OFD_Assert(OFD_Vector2_Magnitude((OFD_Vector2){-3, -4}) == 5, "OFD_Vector2_Magnitude #3");
}

// OFD_Vector2_Add(OFD_Vector2, OFD_Vector2);
void test_vector2_add() {
   OFD_Vector2 out;

   out = OFD_Vector2_Add(
      (OFD_Vector2){2, 3},
      (OFD_Vector2){4, 2}
   );
   OFD_Assert(out.x == 6, "OFD_Vector2_Add #1 (x)");
   OFD_Assert(out.y == 5, "OFD_Vector2_Add #1 (y)");


   out = OFD_Vector2_Add(
      (OFD_Vector2){0, 0}, 
      (OFD_Vector2){0, 0}
   );
   OFD_Assert(out.x == 0, "OFD_Vector2_Add #2 (x)");
   OFD_Assert(out.y == 0, "OFD_Vector2_Add #2 (y)");

}


// OFD_Vector2_Subtract(OFD_Vector2, OFD_Vector2);
void test_vector2_subtract() {
   OFD_Vector2 out;

   out = OFD_Vector2_Subtract(
      (OFD_Vector2){2, 3},
      (OFD_Vector2){4, 2}
   );
   OFD_Assert(out.x == -2, "OFD_Vector2_Add #1 (x)");
   OFD_Assert(out.y == 1, "OFD_Vector2_Add #1 (y)");


   out = OFD_Vector2_Subtract(
      (OFD_Vector2){0, 0}, 
      (OFD_Vector2){0, 0}
   );
   OFD_Assert(out.x == 0, "OFD_Vector2_Add #2 (x)");
   OFD_Assert(out.y == 0, "OFD_Vector2_Add #2 (y)");

}


void test_vector2_dot() {

   double out = OFD_Vector2_Dot(
      (OFD_Vector2){3, 5},
      (OFD_Vector2){1, 2}
   );

   OFD_Assert(out == 13, "OFD_Vector2_Dot #1");

   out = OFD_Vector2_Dot(
      (OFD_Vector2){0, 2},
      (OFD_Vector2){5, 0}
   );

   OFD_Assert(out == 0, "OFD_Vector2_Dot #2");
}


void test_vector3_magnitude() {

   OFD_Assert(
      fabs(OFD_Vector3_Magnitude((OFD_Vector3){3, 4, 5})) - 7.07106781187 < 1e-9, 
      "OFD_Vector3_Magnitude #1"
   );
   OFD_Assert(
      OFD_Vector3_Magnitude((OFD_Vector3){3, 4, 12}) == 13, 
      "OFD_Vector3_Magnitude #2"
   );

   OFD_Assert(
      OFD_Vector3_Magnitude((OFD_Vector3){0, 0, 0}) == 0, 
      "OFD_Vector3_Magnitude #3"
   );
   
   
}


void test_vector3_cross() { 

   OFD_Vector3 out;

   out = OFD_Cross(
      (OFD_Vector3){2, 3, 4},
      (OFD_Vector3){5, 4, 3}
   );
   
   OFD_Assert(out.x == -7, "OFD_Vector3_Cross #1 (x)");
   OFD_Assert(out.y == 14, "OFD_Vector3_Cross #1 (y)");
   OFD_Assert(out.z == -7, "OFD_Vector3_Cross #1 (z)");



   out = OFD_Cross(
      (OFD_Vector3){0, 2, 3},
      (OFD_Vector3){5, 4, 0}
   );
   
   OFD_Assert(out.x == -12, "OFD_Vector3_Cross #2 (x)");
   OFD_Assert(out.y == 15, "OFD_Vector3_Cross #2 (y)");
   OFD_Assert(out.z == -10, "OFD_Vector3_Cross #2 (z)");

   
}

void test_vector3_add() {

   OFD_Vector3 out = OFD_Vector3_Add(
      (OFD_Vector3){1, 2, 3},
      (OFD_Vector3){3, 2, 1}
   );

   OFD_Assert(out.x == 4, "OFD_Vector3_Add #1 (x)");
   OFD_Assert(out.y == 4, "OFD_Vector3_Add #1 (y)");
   OFD_Assert(out.z == 4, "OFD_Vector3_Add #1 (z)");


   out = OFD_Vector3_Add(
      (OFD_Vector3){0, 2, 3},
      (OFD_Vector3){3, 0, 0}
   );

   OFD_Assert(out.x == 3, "OFD_Vector3_Add #2 (x)");
   OFD_Assert(out.y == 2, "OFD_Vector3_Add #2 (y)");
   OFD_Assert(out.z == 3, "OFD_Vector3_Add #2 (z)");

}


void test_vector3_subtract() {

   OFD_Vector3 out = OFD_Vector3_Subtract(
      (OFD_Vector3){1, 2, 3},
      (OFD_Vector3){3, 2, 1}
   );

   OFD_Assert(out.x == -2, "OFD_Vector3_Subtract #1 (x)");
   OFD_Assert(out.y == 0, "OFD_Vector3_Subtract #1 (y)");
   OFD_Assert(out.z == 2, "OFD_Vector3_Subtract #1 (z)");


   out = OFD_Vector3_Subtract(
      (OFD_Vector3){0, 2, 3},
      (OFD_Vector3){3, 0, 0}
   );

   OFD_Assert(out.x == -3, "OFD_Vector3_Subtract #2 (x)");
   OFD_Assert(out.y == 2, "OFD_Vector3_Subtract #2 (y)");
   OFD_Assert(out.z == 3, "OFD_Vector3_Subtract #2 (z)");

}


void test_vector3_dot() {

   double out = OFD_Vector3_Dot(
      (OFD_Vector3){1, 2, 3},
      (OFD_Vector3){3, 2, 1}
   );

   OFD_Assert(out == 10, "OFD_Vector3_Dot #1");

   out = OFD_Vector3_Dot(
      (OFD_Vector3){0, 0, 0},
      (OFD_Vector3){0, 0, 0}
   );

   OFD_Assert(out == 0, "OFD_Vector3_Dot #2");

   out = OFD_Vector3_Dot(
      (OFD_Vector3){1, 0, 3},
      (OFD_Vector3){0, 2, 0}
   );

   OFD_Assert(out == 0, "OFD_Vector3_Dot #3");
}


void test_vector4_magnitude() {

   OFD_Assert(
      fabs(OFD_Vector4_Magnitude((OFD_Vector4){3, 4, 5, 6})) - 9.2736184955 < 1e-9, 
      "OFD_Vector4_Magnitude #1"
   );

   OFD_Assert(
      OFD_Vector4_Magnitude((OFD_Vector4){3, 4, 12, 0}) == 13, 
      "OFD_Vector4_Magnitude #2"
   );

   OFD_Assert(
      OFD_Vector4_Magnitude((OFD_Vector4){0, 0, 0}) == 0, 
      "OFD_Vector4_Magnitude #3"
   );
   

}


void test_exterior() {

   OFD_Vector4 a = (OFD_Vector4){1, 2, 3, 4};
   OFD_Vector4 b = (OFD_Vector4){4, 3, 2, 1};


   OFD_Vector6 result = OFD_Exterior(a, b);

   OFD_Assert(
      result.xy == -5   &&
      result.xz == -10  &&
      result.xw == -15  &&
      result.yz == -5   &&
      result.yw == -10  &&
      result.zw == -5,
      "OFD_Exterior #1"
   );

   result = OFD_Exterior((OFD_Vector4){0, 0, 0, 0}, (OFD_Vector4){0, 0, 0, 0});

   OFD_Assert(
      result.xy == 0 &&
      result.xz == 0 &&
      result.xw == 0 &&
      result.yz == 0 &&
      result.yw == 0 &&
      result.zw == 0,
      "OFD_Exterior #2"
   );

}


void test_vector4_add() {


   OFD_Vector4 out = OFD_Vector4_Add(
      (OFD_Vector4){1, 2, 3, 4},
      (OFD_Vector4){4, 3, 2, 1}
   );

   OFD_Assert(out.x == 5, "OFD_Vector4_Add #1 (x)");
   OFD_Assert(out.y == 5, "OFD_Vector4_Add #1 (y)");
   OFD_Assert(out.z == 5, "OFD_Vector4_Add #1 (z)");
   OFD_Assert(out.w == 5, "OFD_Vector4_Add #1 (w)");



   out = OFD_Vector4_Add(
      (OFD_Vector4){0, 2, 3, 0},
      (OFD_Vector4){3, 0, 0, 1}
   );

   OFD_Assert(out.x == 3, "OFD_Vector4_Add #2 (x)");
   OFD_Assert(out.y == 2, "OFD_Vector4_Add #2 (y)");
   OFD_Assert(out.z == 3, "OFD_Vector4_Add #2 (z)");
   OFD_Assert(out.w == 1, "OFD_Vector4_Add #2 (w)");



}



void test_vector4_subtract() {

   OFD_Vector4 out = OFD_Vector4_Subtract(
      (OFD_Vector4){1, 2, 3, 4},
      (OFD_Vector4){4, 3, 2, 1}
   );

   OFD_Assert(out.x == -3, "OFD_Vector4_Subtract #1 (x)");
   OFD_Assert(out.y == -1, "OFD_Vector4_Subtract #1 (y)");
   OFD_Assert(out.z == 1, "OFD_Vector4_Subtract #1 (z)");
   OFD_Assert(out.w == 3, "OFD_Vector4_Subtract #1 (w)");



   out = OFD_Vector4_Subtract(
      (OFD_Vector4){0, 2, 3, 0},
      (OFD_Vector4){3, 0, 0, 1}
   );

   OFD_Assert(out.x == -3, "OFD_Vector4_Subtract #2 (x)");
   OFD_Assert(out.y == 2, "OFD_Vector4_Subtract #2 (y)");
   OFD_Assert(out.z == 3, "OFD_Vector4_Subtract #2 (z)");
   OFD_Assert(out.w == -1, "OFD_Vector4_Subtract #2 (w)");

}


void test_vector4_dot() {

   double out = OFD_Vector4_Dot(
      (OFD_Vector4){1, 2, 3, 4},
      (OFD_Vector4){4, 3, 2, 1}
   );

   OFD_Assert(out == 20, "OFD_Vector4_Dot #1");

   out = OFD_Vector4_Dot(
      (OFD_Vector4){0, 0, 0, 0},
      (OFD_Vector4){0, 0, 0, 0}
   );

   OFD_Assert(out == 0, "OFD_Vector4_Dot #2");

   out = OFD_Vector4_Dot(
      (OFD_Vector4){1, 0, 3, 0},
      (OFD_Vector4){0, 2, 0, 4}
   );

   OFD_Assert(out == 0, "OFD_Vector4_Dot #3");

}


void test_vector6_magnitude() {

   OFD_Vector6 a = (OFD_Vector6){1, 2, 3, 4, 5, 6};

   OFD_Assert(
      fabs(OFD_Vector6_Magnitude(a) - 9.53939201417) < 1e-9,
      "OFD_Vector6_Magnitude #1"
   );

   a = (OFD_Vector6){0, 0, 0, 0, 0, 0};

   OFD_Assert(
      OFD_Vector6_Magnitude(a) == 0,
      "OFD_Vector6_Magnitude #2"
   );


}




void test_vector4_rotate() {

   OFD_Vector4 _p = OFD_Vector4_Rotate(
      (OFD_Vector4){1, 0, 0, 0}, 
      (OFD_Vector4){0,0,0,0}, 
      (OFD_Vector6){0, 0, 0, 0, 0, 90}
   );

   OFD_Assert(
      neareq(_p.x, 0) && neareq(_p.y, 1) && neareq(_p.z, 0) && neareq(_p.w, 0),
      "OFD_Vector4_Rotate #1"
   );


   _p = OFD_Vector4_Rotate(
      (OFD_Vector4){0, 0, 0, 0}, 
      (OFD_Vector4){0,0,0,0}, 
      (OFD_Vector6){0, 0, 0, 0, 0, 90}
   );

   OFD_Assert(
      neareq(_p.x, 0) && neareq(_p.y, 0) && neareq(_p.z, 0) && neareq(_p.w, 0),
      "OFD_Vector4_Rotate #2"
   );

}


int main() {

   // Vector2

   test_vector2_magnitude();
   test_vector2_add();
   test_vector2_subtract();
   test_vector2_dot();

   // Vector3

   test_vector3_magnitude();
   test_vector3_cross();
   test_vector3_add();
   test_vector3_subtract();
   test_vector3_dot();

   // Vector4

   test_vector4_magnitude();
   test_exterior();
   test_vector4_add();
   test_vector4_subtract();
   test_vector4_dot();

   test_vector4_rotate();

   test_vector6_magnitude();


}