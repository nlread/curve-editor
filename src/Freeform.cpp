//
// Created by Ned on 3/23/2016.
//

#include "Freeform.h"

void Freeform::addControlPoint(float2 p) {
    controlPoints.push_back(p);
    invalidatePoints();
}

std::vector<float2> *Freeform::getPointsToDraw() {
    return &controlPoints;
}

bool Freeform::canBeDrawn() {
    return controlPoints.size() >= 2;
}

int Freeform::numControlPoints() {
    return controlPoints.size();
}

int Freeform::findNearControlPointIndex(float2 pointNearTo, float maxDistance) {
    for (int i = 0; i < controlPoints.size(); i++) {
        float2 cp = controlPoints[i];
        if ((cp - pointNearTo).norm() < maxDistance) {
            return i;
        }
    }
    return -1;
}

void Freeform::endManipulateObjectDrag() {
    draggingControlPointIndex = -1;
}

void Freeform::manipulateObjectDrag(float2 destinationPoint) {
    if (draggingControlPointIndex != -1) {
        controlPoints[draggingControlPointIndex] = destinationPoint;
        invalidatePoints();
        calculatePoints();
    }
}

void Freeform::beginManipulateObjectDrag(float2 beginPoint) {
    int index = findNearControlPointIndex(beginPoint, SELECTION_DISTANCE);
    draggingControlPointIndex = index;
}

void Freeform::manipulateObjectDestructive(float2 pointClicked) {
    int index = findNearControlPointIndex(pointClicked, SELECTION_DISTANCE);
    if (index != -1) {
        controlPoints.erase(controlPoints.begin() + index);
        invalidatePoints();
        calculatePoints();
    }
}

void Freeform::manipulateObjectConstructive(float2 pointClicked) {
    addControlPoint(pointClicked);
}