//
// Created by Ned on 3/23/2016.
//

#include "BezierCurve.h"



float2 BezierCurve::getPoint(float t) {
    if (controlPoints.size() == 0)
        return float2(0.0, 0.0);

    float2 r(0.0, 0.0);
    for (int i = 0; i < controlPoints.size(); i++) {
        r = r + controlPoints[i] * berstein(i, controlPoints.size() - 1, t);
    }

    return r;
}

void BezierCurve::setColor() {
    glColor3d(1.0, 0.0, 1.0);
}