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

#ifndef OFD_util_h_
#define OFD_util_h_




#ifdef _WIN32
    #ifdef OPEN4D_EXPORTS
        #define OPEN4D_API __declspec(dllexport)
    #else
        #define OPEN4D_API __declspec(dllimport)
    #endif
#else
    #define OPEN4D_API __attribute__((visibility("default")))
#endif


// Use const attribute for Clang and GCC optimization.
#if defined(__GNUC__) || defined(__clang__)
#define ATTRIBUTE_CONST __attribute__((const))
#else
#define ATTRIBUTE_CONST
#endif


#include <math.h>
#include <stdlib.h>



/** @brief Represents a 2D vector. */
typedef struct { double x, y; } OFD_Vector2;

/** @brief Represents a 3D vector. */
typedef struct { double x, y, z; } OFD_Vector3;

/** @brief Represents a 4D vector. */
typedef struct { double x, y, z, w; } OFD_Vector4;

/** @brief Represents a 6D vector. */
typedef struct { double xy, xz, xw, yz, yw, zw; } OFD_Vector6;

/** @brief Calculates the magnitude of the provided vector. */
ATTRIBUTE_CONST inline static OPEN4D_API double OFD_Vector2_Magnitude(const OFD_Vector2 a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

/** @brief Adds two 2D vectors together.*/
ATTRIBUTE_CONST inline static OPEN4D_API OFD_Vector2 OFD_Vector2_Add(const OFD_Vector2 a, const OFD_Vector2 b) {
    return (OFD_Vector2){ 
        a.x + b.x,
        a.y + b.y
    };
}

/** @brief Subtracts vector "b" from vector "a" */
ATTRIBUTE_CONST inline static OPEN4D_API OFD_Vector2 OFD_Vector2_Subtract(const OFD_Vector2 a, const OFD_Vector2 b) {
    return (OFD_Vector2){
        a.x - b.x,
        a.y - b.y
    };
}

/** @brief Calculates the dot product of two 2D vectors. */
ATTRIBUTE_CONST inline static OPEN4D_API double OFD_Vector2_Dot(const OFD_Vector2 a, const OFD_Vector2 b) {
    return a.x * b.x + a.y * b.y;
}

/** @brief Calculates the magnitude of the provided vector. */
ATTRIBUTE_CONST inline static OPEN4D_API double OFD_Vector3_Magnitude(const OFD_Vector3 a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

/** @brief Finds the cross product of two 3D vectors.
 * 
 *  The "cross product" is a 3D vector derived from two others. It
 *  represents a vector perpendicular to a plane formed by vectors "a" and "b"
 *  It also represents the area of the parallelogram formed by vectors "a" and "b"
 * 
 */
ATTRIBUTE_CONST inline static OPEN4D_API OFD_Vector3 OFD_Cross(const OFD_Vector3 a, const OFD_Vector3 b) {
    return (OFD_Vector3){
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

/** @brief Adds two 3D vectors together. */
ATTRIBUTE_CONST inline static OPEN4D_API OFD_Vector3 OFD_Vector3_Add(const OFD_Vector3 a, const OFD_Vector3 b) {
    return (OFD_Vector3){
        a.x + b.x,
        a.y + b.y,
        a.z + b.z
    };
}

/** @brief Subtracts vector "b" from vector "a" */
ATTRIBUTE_CONST inline static OPEN4D_API OFD_Vector3 OFD_Vector3_Subtract(const OFD_Vector3 a, const OFD_Vector3 b) {
    return (OFD_Vector3){
        a.x - b.x,
        a.y - b.y,
        a.z - b.z
    };
}

/** @brief Calculates the dot product of two 3D vectors. */
ATTRIBUTE_CONST inline static OPEN4D_API double OFD_Vector3_Dot(const OFD_Vector3 a, const OFD_Vector3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

/** @brief Calculates the magnitude of the provided vector. */
ATTRIBUTE_CONST inline static OPEN4D_API double OFD_Vector4_Magnitude(const OFD_Vector4 a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
}

/** @brief Finds the exterior product, or wedge product of two 4D vectors.
 * 
 * The "exterior product," also known as the "wedge product" is a 6D vector 
 * derived from two 4D vectors. Similar to the cross product, the exterior product 
 * can find the area of a parallelogram formed by vectors "a" and "b" in 4D space.
 * 
 */
ATTRIBUTE_CONST inline static OPEN4D_API OFD_Vector6 OFD_Exterior(const OFD_Vector4 a, const OFD_Vector4 b) {
    return (OFD_Vector6){
        a.x * b.y - a.y * b.x,
        a.x * b.z - a.z * b.x,
        a.x * b.w - a.w * b.x,
        a.y * b.z - a.z * b.y,
        a.y * b.w - a.w * b.y,
        a.z * b.w - a.w * b.z
    };
}

/** @brief Adds two 4D vectors together. */
ATTRIBUTE_CONST inline static OPEN4D_API OFD_Vector4 OFD_Vector4_Add(const OFD_Vector4 a, const OFD_Vector4 b) {
    return (OFD_Vector4){
        a.x + b.x,
        a.y + b.y,
        a.z + b.z,
        a.w + b.w
    };
}

/** @brief Subtracts vector "b" from vector "a" */
ATTRIBUTE_CONST inline static OPEN4D_API OFD_Vector4 OFD_Vector4_Subtract(const OFD_Vector4 a, const OFD_Vector4 b) {
    return (OFD_Vector4){
        a.x - b.x,
        a.y - b.y,
        a.z - b.z,
        a.w - b.w
    };
}

/** @brief Calculates the dot product of two 4D vectors. */
ATTRIBUTE_CONST inline static OPEN4D_API double OFD_Vector4_Dot(const OFD_Vector4 a, const OFD_Vector4 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}


/** @brief Calculates the magnitude of the provided vector. */
ATTRIBUTE_CONST inline static OPEN4D_API double OFD_Vector6_Magnitude(const OFD_Vector6 a) {
    return sqrt(a.xy * a.xy + a.xz * a.xz + a.xw * a.xw + a.yz * a.yz + a.yw * a.yw + a.zw * a.zw);
}


#if defined(__GNUC__) || defined(__clang__)
__attribute__((const))
#endif
static inline double toRadians(const double a) {
    return a * 0.0174532925199; // a * π / 180
}

/** @brief Rotates a 4D vector around a central point. */
ATTRIBUTE_CONST inline static OPEN4D_API OFD_Vector4 OFD_Vector4_Rotate(const OFD_Vector4 a, const OFD_Vector4 c, const OFD_Vector6 r) {
    double sXY = sin(toRadians(r.xy)); double sXZ = sin(toRadians(r.xz)); double sXW = sin(toRadians(r.xw)); double sYZ = sin(toRadians(r.yz)); double sYW = sin(toRadians(r.yw)); double sZW = sin(toRadians(r.zw));
    double cXY = cos(toRadians(r.xy)); double cXZ = cos(toRadians(r.xz)); double cXW = cos(toRadians(r.xw)); double cYZ = cos(toRadians(r.yz)); double cYW = cos(toRadians(r.yw)); double cZW = cos(toRadians(r.zw));

    return (OFD_Vector4){
        cYZ * cYW * cZW * (a.x - c.x) + (cXZ * (-cXW * sZW - sXW * sYW * cZW) - sXZ * sYZ * cYW * cZW) * (a.y - c.y) + (cXY * (sXW * sZW - cXW * sYW * cZW) + sXY * (sXZ * (cXW * sZW + sXW * sYW * cZW) - cXZ * sYZ * cYW * cZW)) * (a.z- c.z) + (-sXY * (sXW * sZW - cXW * sYW * cZW) + cXY * (sXZ * (cXW * sZW + sXW * sYW * cZW) - cXZ * sYZ * cYW * cZW)) * (a.w - c.w) + c.x, 
        cYZ * cYW * sZW * (a.x - c.x) + (cXZ * (cXW * cZW - sXW * sYW * sZW) - sXZ * sYZ * cYW * sZW) * (a.y - c.y) + (cXY * (-sXW * cZW - cXW * sYW * sZW) + sXY * (-sXZ * (cXW * cZW - sXW * sYW * sZW) - cXZ * sYZ * cYW * sZW)) * (a.z- c.z) + (-sXY * (-sXW * cZW - cXW * sYW * sZW) + cXY * (-sXZ * (cXW * cZW - sXW * sYW * sZW) - cXZ * sYZ * cYW * sZW)) * (a.w - c.w) + c.y,
        (cYZ * sYW) * (a.x - c.x) + (cXZ * sXW * cYW - sXZ * sYZ * sYW) * (a.y - c.y) + (cXY * cXW * cYW + sXY * (-sXZ * sXW * cYW - cXZ * sYZ * sYW)) * (a.z- c.z) + (-sXY * cXW * cYW + cXY * (-sXZ * sXW * cYW - cXZ * sYZ * sYW)) * (a.w - c.w) + c.z,
        (sYZ) * (a.x - c.x) + (sXZ * cYZ) * (a.y - c.y) + (sXY * cXZ * cYZ) * (a.z- c.z) + (cXY * cXZ * cYZ) * (a.w - c.w) + c.w 
    };
}



#endif // OFD_util_h_