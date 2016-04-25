//
// Created by Ned on 3/23/2016.
//

#include "Curve.h"

void Curve::drawObject() {
    if (!validPoints)
        calculatePoints();

    glBegin(GL_LINE_STRIP);
    {
        for (int i = 0; i < numPoints; i++) {
            float2 pt = points[i];
            glVertex2f(pt.x, pt.y);
        }
    }
    glEnd();
}

void Curve::invalidatePoints() {
    validPoints = false;
}

void Curve::calculatePoints() {
    if (!canBeDrawn())
        return;

    int index = 0;
    for (float i = 0; i < 1; i += STEP) {
        float2 pt = getPoint(i);
        points[index] = pt;
        index++;
    }
    validPoints = true;
}

bool Curve::closeToPoint(float2 point, float maxDistance) {
    if (!validPoints)
        calculatePoints();

    for (int i = 0; i < numPoints; i++) {
        if ((points[i] - point).norm() <= maxDistance)
            return true;
    }
    return false;
}