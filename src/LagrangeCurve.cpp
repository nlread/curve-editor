//
// Created by Ned on 3/23/2016.
//

#include "LagrangeCurve.h"

void LagrangeCurve::addControlPoint(float2 p) {
    Freeform::addControlPoint(p);
    knots.clear();
    for (int i = 0; i < controlPoints.size(); i++)
        knots.push_back((float) i / (controlPoints.size() - 1));
}

float2 LagrangeCurve::getPoint(float t) {
    if (controlPoints.size() < 2)
        return float2(0.0, 0.0);

    float2 r(0.0, 0.0);
    for (int i = 0; i < controlPoints.size(); i++) {
        double denominator = 1;
        double numerator = 1;
        for (int j = 0; j < knots.size(); j++) {
            if (j != i) {
                denominator *= (knots[i] - knots[j]);
                numerator *= (t - knots[j]);
            }
        }
        r += controlPoints[i] * (numerator / denominator);
    }
    return r;
}

void LagrangeCurve::setColor() {
    glColor3d(0.0, 1.0, 0.0);
}