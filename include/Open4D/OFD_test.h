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

#include <stdio.h>
#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>

/** @brief Makes an assertion and reports the result. */
static int OFD_Assert(const int assertion, const char* test_name, ...) {
    va_list args;
    va_start(args, test_name);
    vprintf(test_name, args);
    if (assertion)
        printf(": \x1b[32m[PASS]\x1b[0m\n");
    else 
        printf(": \x1b[31m[FAIL]\x1b[0m\n");
    va_end(args);
    fflush(stdout);
    assert(assertion);
    return 0;
}


// Returns true if a and b are *nearly* equal to each other, accounting for truncation.
#if defined(__GNUC__) || defined(__clang__)
__attribute__((pure))
#endif
static inline int neareq(double a, double b) {
    return fabs(a - b) < 1e-6;
}