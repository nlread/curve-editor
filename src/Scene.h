//
// Created by Ned on 3/23/2016.
//

#ifndef CURVEASSIGNMENT_SCENE_H
#define CURVEASSIGNMENT_SCENE_H


#define POLYLINE_KEY 'p'
#define DEFAULT_CONSTRUCTIVE_KEY 'a'
#define DEFAULT_DESTRUCTION_KEY 'd'
#define BEZIER_KEY 'b'
#define MOVE_KEY 'm'
#define LAGRANGE_KEY 'l'
#define CYCLE_SELECTED_KEY ' '

#define KEY_UP false
#define KEY_DOWN true

#include <GL/glut.h>
#include "float2.h"
#include "Freeform.h"
#include "PolyLine.h"
#include "BezierCurve.h"
#include "LagrangeCurve.h"

class Scene {
    std::vector<Object *> objects = std::vector<Object *>();
    Object *selected = NULL;
    int selectedIndex = -1;
    bool *keyStates = new bool[256];
    char selectedConstructiveKey = -1;

public:
    Scene();

    void addObject(Object *toAdd);

    void removeObject(int indexToRemove);

    void draw();

    void cycleSelectedObject();

    void setKeyState(char key, bool state);

    bool isKeyDown(char key);

    bool isKeyUp(char key);

    void handleKeyDown(char key);

    void handleKeyUp(char key);

    void onMouseDown(float2 pointClicked, int state);

    void onMouseUp(float2 pointClicked, int state);

    void onMouseDrag(float2 pointMovedTo);

    void setSelected(int indexOfSelected);

    void setSelectedToNearest(float2 point);

    void setSelectedToNearest(float2 point, float maxDistance);

    void applyDestructiveActionToSelected(float2 destructivePoint);

    void applyConstructiveActionToSelected(float2 constructivePoint);

    bool selectedIsValid();

    void setSelectedConstruvtiveKey(char newKey);
};


#endif //CURVEASSIGNMENT_SCENE_H

