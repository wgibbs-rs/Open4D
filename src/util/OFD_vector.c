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

#include "OFD_vector_c.h"
#include <math.h>


static inline double OFD_Vector2_Magnitude(OFD_Vector2 a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

static inline OFD_Vector2 OFD_Vector2_Add(OFD_Vector2 a, OFD_Vector2 b) {
    OFD_Vector2 o;
    o.x = a.x + b.x;
    o.y = a.y + b.y;
    return o;
}

static inline OFD_Vector2 OFD_Vector2_Subtract(OFD_Vector2 a, OFD_Vector2 b) {
    OFD_Vector2 o;
    o.x = a.x - b.x;
    o.y = a.y - b.y;
    return o;
}

static inline double OFD_Vector2_Dot(OFD_Vector2 a, OFD_Vector2 b) {
    return a.x * b.x + a.y * b.y;
}



static inline double OFD_Vector3_Magnitude(OFD_Vector3 a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

static inline OFD_Vector3 OFD_Cross(OFD_Vector3 a, OFD_Vector3 b) {
    OFD_Vector3 o;
    o.x = a.y * b.z - a.z * b.y;
    o.y = a.z * b.x - a.x * b.z;
    o.z = a.x * b.y - a.y * b.x;
    return o;
}

static inline OFD_Vector3 OFD_Vector3_Add(OFD_Vector3 a, OFD_Vector3 b) {
    OFD_Vector3 o;
    o.x = a.x + b.x;
    o.y = a.y + b.y;
    o.z = a.z + b.z;
    return o;
}

static inline OFD_Vector3 OFD_Vector3_Subtract(OFD_Vector3 a, OFD_Vector3 b) {
    OFD_Vector3 o;
    o.x = a.x - b.x;
    o.y = a.y - b.y;
    o.z = a.z - b.z;
    return o;
}

static inline double OFD_Vector3_Dot(OFD_Vector3 a, OFD_Vector3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}



static inline double OFD_Vector4_Magnitude(OFD_Vector4 a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}

static inline OFD_Vector6 OFD_Exterior(OFD_Vector4 a, OFD_Vector4 b) {
    OFD_Vector6 o;
    o.xy = a.x * b.y - a.y * b.x;
    o.xz = a.x * b.z - a.z * b.x;
    o.xw = a.x * b.w - a.w * b.x;
    o.yz = a.y * b.z - a.z * b.y;
    o.yw = a.y * b.w - a.w * b.y;
    o.zw = a.z * b.w - a.w * b.z;
    return o;
}

static inline OFD_Vector4 OFD_Vector4_Add(OFD_Vector4 a, OFD_Vector4 b) {
    OFD_Vector4 o;
    o.x = a.x + b.x;
    o.y = a.y + b.y;
    o.z = a.z + b.z;
    o.w = a.w + b.w;
    return o;
}

static inline OFD_Vector4 OFD_Vector4_Subtract(OFD_Vector4 a, OFD_Vector4 b) {
    OFD_Vector4 o;
    o.x = a.x - b.x;
    o.y = a.y - b.y;
    o.z = a.z - b.z;
    o.w = a.w - b.w;
    return o;
}

static inline double OFD_Vector4_Dot(OFD_Vector4 a, OFD_Vector4 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}


static inline double OFD_Vector6_Magnitude(OFD_Vector6 a) {
    return sqrt(a.xy * a.xy + a.xz * a.xz + a.xw * a.xw + a.yz * a.yz + a.yw * a.yw + a.zw * a.zw);
}



static inline OFD_Vector4 OFD_Vector4_Rotate(OFD_Vector4 a, OFD_Vector4 c, OFD_Vector6 r) {
    
}