#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include "ctime"
#include <GL/gl.h>
#include <GL/glut.h>

#include "float2.h"
#include "Object.h"
#include "Scene.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
// Needed on MsWindows
#include <windows.h>

#endif // Win32 platform

#define STEP .001
#define SELECTION_DISTANCE .05

#define KEY_UP false
#define KEY_DOWN true

Scene *scene;

void onDisplay() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    scene->draw();
    glutSwapBuffers();
}

void onReshape(int width, int height) {
    glViewport(0, 0, width, height);
}

float2 getConvertedPoint(int x, int y) {
    float2 convertedPoint = float2(2.0f * x / glutGet(GLUT_WINDOW_WIDTH) - 1.0f,
                                   -2.0f * y / glutGet(GLUT_WINDOW_HEIGHT) + 1.0f);
    return convertedPoint;
}

void onMouse(int button, int state, int x, int y) {
    float2 convertedPoint = getConvertedPoint(x, y);
    //printf("%f %f\n", convertedPoint.x, convertedPoint.y);
    if (state == GLUT_DOWN) {
        //printf("mouse down: %d %d\n", x, y);
        scene->onMouseDown(convertedPoint, button);
    } else if (state == GLUT_UP) {
        //printf("mouse up: %d %d\n", x, y);
        scene->onMouseUp(convertedPoint, button);
    }
}

void onMouseDown(float2 pt, int button) {
}

void onDrag(int x, int y) {
    float2 convertedPoint = getConvertedPoint(x, y);
    scene->onMouseDrag(convertedPoint);
}

void onKeyboard(unsigned char key, int x, int y) {
    scene->setKeyState(key, KEY_DOWN);

}

void onKeyboardUp(unsigned char key, int x, int y) {
    scene->setKeyState(key, KEY_UP);

}

/**
 * For testing purposes
 */
void initScene() {
    scene = new Scene();

    PolyLine *line = new PolyLine();
    line->addPoint(float2(.5, .5));
    line->addPoint(float2(-.5, -.5));

    BezierCurve *curve = new BezierCurve();
    curve->addControlPoint(float2(-0.5f, -0.5f));
    curve->addControlPoint(float2(0.5, .5));

    //scene->addObject(curve);
    //scene->addObject(line);
}

int main(int argc, char *argv[]) {
    std::srand(std::time(0));

    glutInit(&argc, argv);                        // GLUT initialization
    glutInitWindowSize(640, 640);                // Initial resolution of the MsWindows Window is 600x600 pixels
    glutInitWindowPosition(100, 100);            // Initial location of the MsWindows window
    glutInitDisplayMode(
            GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);    // Image = 8 bit R,G,B + double buffer + depth buffer

    glutCreateWindow("Curves");            // Window is born

    glutDisplayFunc(onDisplay);                    // Register event handlers
    glutReshapeFunc(onReshape);
    glutMouseFunc(onMouse);
    glutMotionFunc(onDrag);
    glutKeyboardFunc(onKeyboard);
    glutKeyboardUpFunc(onKeyboardUp);

    initScene();

    glutMainLoop();                                // Event loop
    return 0;
}


