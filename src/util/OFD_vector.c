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

#include "Open4D/OFD_util.h"
#include <math.h>


double OFD_Vector2_Magnitude(OFD_Vector2 a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

OFD_Vector2 OFD_Vector2_Add(OFD_Vector2 a, OFD_Vector2 b) {
    return (OFD_Vector2){ 
        a.x + b.x,
        a.y + b.y
    };
}

OFD_Vector2 OFD_Vector2_Subtract(OFD_Vector2 a, OFD_Vector2 b) {
    return (OFD_Vector2){
        a.x - b.x,
        a.y - b.y
    };
}

double OFD_Vector2_Dot(OFD_Vector2 a, OFD_Vector2 b) {
    return a.x * b.x + a.y * b.y;
}



double OFD_Vector3_Magnitude(OFD_Vector3 a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

OFD_Vector3 OFD_Cross(OFD_Vector3 a, OFD_Vector3 b) {
    return (OFD_Vector3){
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

OFD_Vector3 OFD_Vector3_Add(OFD_Vector3 a, OFD_Vector3 b) {
    return (OFD_Vector3){
        a.x + b.x,
        a.y + b.y,
        a.z + b.z
    };
}

OFD_Vector3 OFD_Vector3_Subtract(OFD_Vector3 a, OFD_Vector3 b) {
    return (OFD_Vector3){
        a.x - b.x,
        a.y - b.y,
        a.z - b.z
    };
}

double OFD_Vector3_Dot(OFD_Vector3 a, OFD_Vector3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}



double OFD_Vector4_Magnitude(OFD_Vector4 a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}

OFD_Vector6 OFD_Exterior(OFD_Vector4 a, OFD_Vector4 b) {
    return (OFD_Vector6){
        a.x * b.y - a.y * b.x,
        a.x * b.z - a.z * b.x,
        a.x * b.w - a.w * b.x,
        a.y * b.z - a.z * b.y,
        a.y * b.w - a.w * b.y,
        a.z * b.w - a.w * b.z
    };
}

OFD_Vector4 OFD_Vector4_Add(OFD_Vector4 a, OFD_Vector4 b) {
    return (OFD_Vector4){
        a.x + b.x,
        a.y + b.y,
        a.z + b.z,
        a.w + b.w
    };
}

OFD_Vector4 OFD_Vector4_Subtract(OFD_Vector4 a, OFD_Vector4 b) {
    return (OFD_Vector4){
        a.x - b.x,
        a.y - b.y,
        a.z - b.z,
        a.w - b.w
    };
}

double OFD_Vector4_Dot(OFD_Vector4 a, OFD_Vector4 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}


double OFD_Vector6_Magnitude(OFD_Vector6 a) {
    return sqrt(a.xy * a.xy + a.xz * a.xz + a.xw * a.xw + a.yz * a.yz + a.yw * a.yw + a.zw * a.zw);
}


OFD_Vector4 OFD_Vector4_Rotate(OFD_Vector4 a, OFD_Vector4 c, OFD_Vector6 r) {
    
}