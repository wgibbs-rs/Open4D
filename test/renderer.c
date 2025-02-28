


#include "renderer.h"
#include <raylib.h>
#include <rlgl.h>

#include <Open4D/OFD_geometry.h>

#include <math.h>



static Camera camera = { 0 };

static double rotation = 0;

static const double DEGREES_TO_RADIANS = (M_PI / 180);

void drawTriangle3D(OFD_Triangle3D tri[]) {
    
}




void drawPoint3D(OFD_Vector3 p) {

}




void renderFrame(OFD_Mesh env[]) {


    if (IsKeyDown(KEY_LEFT)) {
        Vector3 cameraPosition = camera.position;
        camera.position.x = cameraPosition.x * cos(-4 * DEGREES_TO_RADIANS) - cameraPosition.y * sin(-4 * DEGREES_TO_RADIANS);
        camera.position.y = cameraPosition.x * sin(-4 * DEGREES_TO_RADIANS) + cameraPosition.y * cos(-4 * DEGREES_TO_RADIANS);
    }
    if (IsKeyDown(KEY_RIGHT)) {
        Vector3 cameraPosition = camera.position;
        camera.position.x = cameraPosition.x * cos(4 * DEGREES_TO_RADIANS) - cameraPosition.y * sin(4 * DEGREES_TO_RADIANS);
        camera.position.y = cameraPosition.x * sin(4 * DEGREES_TO_RADIANS) + cameraPosition.y * cos(4 * DEGREES_TO_RADIANS);
    }

    // In the correct version, we'd gather the OFD_Triangle3D's from all of the environment.
    // In this temperary version, we'll just draw a triangle or two.


    BeginDrawing();
    ClearBackground((Color){64, 64, 64, 255});


    BeginMode3D(camera);

    DrawTriangle3D(
        (Vector3){0.0f, 0.0f, 0.0f},
        (Vector3){2.0f, 3.0f, 1.0f},
        (Vector3){1.0f, 2.0f, -2.0f},
        RED
    );

    EndMode3D();

    EndDrawing();

}


void initializeRenderer() {
    InitWindow(800, 800, "Test Simulation of Open4D");
    SetTargetFPS(30);


    camera.position = (Vector3){ -10.0f, 0.0f, 2.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 0.0f, 1.0f };
    camera.fovy = 90.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    rlDisableBackfaceCulling();

}
