

#ifndef renderer_c_h_
#define renderer_c_h_


#include <Open4D/OFD_geometry.h>
#include <Open4D/OFD_util.h>

/** Draw a triangle to the active screen. Will be rendered for one frame before being cleared. */
extern void drawTriangle3D(OFD_Triangle3D tri[]);

/** Draw a point to the active screen. Will be rendered for one frame before being cleared. */
extern void drawPoint3D(OFD_Vector3 p);


/** Initialize the renderer, including creating the window and initializing the camera. */
extern void initializeRenderer();


/** @brief Renders all meshes and updates the current frame. */
extern void renderFrame(OFD_Mesh env[]);


#endif // renderer_c_h_