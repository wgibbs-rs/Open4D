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





/** @brief Represents a 2D vector. */
typedef struct { double x, y; } OFD_Vector2;

/** @brief Represents a 3D vector. */
typedef struct { double x, y, z; } OFD_Vector3;

/** @brief Represents a 4D vector. */
typedef struct { double x, y, z, w; } OFD_Vector4;

/** @brief Represents a 6D vector. Used for rotational calculations in 4D, 
 * which have 6 planes of rotation. */
typedef struct { double xy, xz, xw, yz, yw, zw; } OFD_Vector6;

/** @brief Calculates the magnitude of the provided vector. */
extern OPEN4D_API double OFD_Vector2_Magnitude(const OFD_Vector2 a);

/** @brief Adds two 2D vectors together.*/
extern OPEN4D_API OFD_Vector2 OFD_Vector2_Add(const OFD_Vector2 a, const OFD_Vector2 b);

/** @brief Subtracts vector "b" from vector "a" */
extern OPEN4D_API OFD_Vector2 OFD_Vector2_Subtract(const OFD_Vector2 a, const OFD_Vector2 b);

/** @brief Calculates the dot product of two 2D vectors. */
extern OPEN4D_API double OFD_Vector2_Dot(const OFD_Vector2 a, const OFD_Vector2 b);

/** @brief Calculates the magnitude of the provided vector. */
extern OPEN4D_API double OFD_Vector3_Magnitude(const OFD_Vector3 a);

/** @brief Finds the cross product of two 3D vectors.
 * 
 *  The "cross product" is a 3D vector derived from two others. It
 *  represents a vector perpendicular to a plane formed by vectors "a" and "b"
 *  It also represents the area of the parallelogram formed by vectors "a" and "b"
 * 
 */
extern OPEN4D_API OFD_Vector3 OFD_Cross(const OFD_Vector3 a, const OFD_Vector3 b);

/** @brief Adds two 3D vectors together. */
extern OPEN4D_API OFD_Vector3 OFD_Vector3_Add(const OFD_Vector3 a, const OFD_Vector3 b);

/** @brief Subtracts vector "b" from vector "a" */
extern OPEN4D_API OFD_Vector3 OFD_Vector3_Subtract(const OFD_Vector3 a, const OFD_Vector3 b);

/** @brief Calculates the dot product of two 3D vectors. */
extern OPEN4D_API double OFD_Vector3_Dot(const OFD_Vector3 a, const OFD_Vector3 b);

/** @brief Calculates the magnitude of the provided vector. */
extern OPEN4D_API double OFD_Vector4_Magnitude(OFD_Vector4 a);

/** @brief Finds the exterior product, or wedge product of two 4D vectors.
 * 
 * The "exterior product," also known as the "wedge product" is a 6D vector 
 * derived from two 4D vectors. Similar to the cross product, the exterior product 
 * can find the area of a parallelogram formed by vectors "a" and "b" in 4D space.
 * 
 */
extern OPEN4D_API OFD_Vector6 OFD_Exterior(const OFD_Vector4 a, const OFD_Vector4 b);

/** @brief Adds two 4D vectors together. */
extern OPEN4D_API OFD_Vector4 OFD_Vector4_Add(const OFD_Vector4 a, const OFD_Vector4 b);

/** @brief Subtracts vector "b" from vector "a" */
extern OPEN4D_API OFD_Vector4 OFD_Vector4_Subtract(const OFD_Vector4 a, const OFD_Vector4 b);

/** @brief Calculates the dot product of two 4D vectors. */
extern OPEN4D_API double OFD_Vector4_Dot(const OFD_Vector4 a, const OFD_Vector4 b);


/** @brief Calculates the magnitude of the provided vector. */
extern OPEN4D_API double OFD_Vector6_Magnitude(const OFD_Vector6 a);


/** @brief Rotates a 4D vector around a central point. */
extern OPEN4D_API OFD_Vector4 OFD_Vector4_Rotate(const OFD_Vector4 a, const OFD_Vector4 c, const OFD_Vector6 r);


#endif // OFD_util_h_