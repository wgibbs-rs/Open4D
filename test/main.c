

#include "renderer.h"


#include <raylib.h>

int main(void) {

    initializeRenderer();

    OFD_Mesh a[2];

    while (!WindowShouldClose()) {
        renderFrame(a);
    }

    CloseWindow();

    return 0;
}