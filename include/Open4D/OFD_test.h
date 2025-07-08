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

/** @brief Makes an assertion and reports the result. */
static int OFD_Assert(const int assertion, const char* test_name) {
    if (assertion)
        printf("%s: \x1b[32m[PASS]\x1b[0m\n", test_name);
    else 
        printf("%s: \x1b[31m[FAIL]\x1b[0m\n", test_name);
    fflush(stdout);
    assert(assertion);
    return 0;
}