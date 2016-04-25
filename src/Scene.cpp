//
// Created by Ned on 3/23/2016.
//

#include "Scene.h"

void Scene::setSelectedConstruvtiveKey(char newKey) {
    selectedConstructiveKey = newKey;
}

bool Scene::selectedIsValid() {
    return !(selected == NULL || selectedIndex == -1);
}

void Scene::applyConstructiveActionToSelected(float2 constructivePoint) {
    if (!selectedIsValid())
        return;
    selected->manipulateObjectConstructive(constructivePoint);
}

void Scene::applyDestructiveActionToSelected(float2 destructivePoint) {
    if (!selectedIsValid())
        return;
    selected->manipulateObjectDestructive(destructivePoint);
    if (!selected->canBeDrawn()) {
        removeObject(selectedIndex);
    }
}

void Scene::setSelectedToNearest(float2 point, float maxDistance) {
    for (int i = 0; i < objects.size(); i++) {
        if (!objects[i]->canBeDrawn())
            continue;
        if (objects[i]->closeToPoint(point, maxDistance)) {
            setSelected(i);
            glutPostRedisplay();
            return;
        }
    }
}

void Scene::setSelectedToNearest(float2 point) {
    setSelectedToNearest(point, SELECTION_DISTANCE);
}

void Scene::setSelected(int indexOfSelected) {
    if (indexOfSelected < 0 || indexOfSelected >= objects.size()) {
        return;
    }

    if (selected != NULL)
        selected->setSelected(false);

    selectedIndex = indexOfSelected;
    selected = objects[selectedIndex];
    selected->setSelected(true);
}

void Scene::onMouseDrag(float2 pointMovedTo) {
    if (isKeyUp(MOVE_KEY))
        return;
    if(selectedIsValid()) {
        selected->manipulateObjectDrag(pointMovedTo);
        glutPostRedisplay();
    }
}

void Scene::onMouseUp(float2 pointClicked, int state) {
    if (state == GLUT_LEFT_BUTTON) {
        if (isKeyDown(MOVE_KEY)) {
            if(selectedIsValid())
                selected->endManipulateObjectDrag();
        } else if (isKeyDown(selectedConstructiveKey) || isKeyDown(DEFAULT_CONSTRUCTIVE_KEY))
            applyConstructiveActionToSelected(pointClicked);
        else if (isKeyDown(DEFAULT_DESTRUCTION_KEY))
            applyDestructiveActionToSelected(pointClicked);
        else
            setSelectedToNearest(pointClicked);
    } else if (state == GLUT_RIGHT_BUTTON) {
        applyDestructiveActionToSelected(pointClicked);
    }
    glutPostRedisplay();
}

void Scene::onMouseDown(float2 pointClicked, int state) {
    if (isKeyDown(MOVE_KEY)) {
        if (selectedIsValid()) {
            selected->beginManipulateObjectDrag(pointClicked);
        }
    }
}

void Scene::handleKeyUp(char key) {
    if (key == selectedConstructiveKey) {
        selectedConstructiveKey = -1;
        if (!selected->canBeDrawn()) {
            removeObject(selectedIndex);
        }
    }
}

void Scene::handleKeyDown(char key) {
    if (key == CYCLE_SELECTED_KEY) {
        cycleSelectedObject();
        glutPostRedisplay();
    } else if (selectedConstructiveKey == -1) { //Create new object
        if (key == POLYLINE_KEY) {
            PolyLine *newLine = new PolyLine();
            addObject(newLine);
            selectedConstructiveKey = POLYLINE_KEY;
        } else if (key == BEZIER_KEY) {
            BezierCurve *newBezier = new BezierCurve();
            addObject(newBezier);
            selectedConstructiveKey = BEZIER_KEY;
        } else if (key == LAGRANGE_KEY) {
            LagrangeCurve *newLagrange = new LagrangeCurve();
            addObject(newLagrange);
            selectedConstructiveKey = LAGRANGE_KEY;
        }
    }
}

bool Scene::isKeyUp(char key) {
    if (key > 255 || key < 0)
        return true;
    return keyStates[key] == KEY_UP;
}

bool Scene::isKeyDown(char key) {
    if (key > 255 || key < 0)
        return false;
    return keyStates[key] == KEY_DOWN;
}

void Scene::setKeyState(char key, bool state) {
    bool triggerEvent = state != keyStates[key];
    keyStates[key] = state;
    if (triggerEvent) {
        if (state == KEY_DOWN) {
            handleKeyDown(key);
        } else {
            handleKeyUp(key);
        }
    }
}

void Scene::cycleSelectedObject() {
    if (objects.size() == 0 || objects.size() == 1)
        return;

    if (selectedIndex == -1 || selectedIndex == objects.size() - 1)
        setSelected(0);
    else
        setSelected(selectedIndex + 1);
}

void Scene::draw() {
    bool valid = selectedIsValid();
    for (int i = 0; i < objects.size(); i++) {
        if (i != selectedIndex || !valid);
        objects[i]->draw();
    }
    if (valid)
        selected->draw();
}

void Scene::removeObject(int indexToRemove) {
    if (indexToRemove < 0 || indexToRemove > objects.size())
        return;

    Object *objectToRemove = objects[indexToRemove];
    if (selected == objectToRemove)
        selected = NULL;
    objects.erase(objects.begin() + indexToRemove);
    delete objectToRemove;

    if (objects.size() == 0)
        selectedIndex = -1;
    else
        setSelected(0);

    glutPostRedisplay();
}

void Scene::addObject(Object *toAdd) {
    if(toAdd == NULL)
        return;
    objects.push_back(toAdd);
    setSelected(objects.size() - 1);
}

Scene::Scene() {
    for(int i=0; i<256; i++) {
        keyStates[i] = KEY_UP;
    }
}