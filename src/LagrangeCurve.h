//
// Created by Ned on 3/23/2016.
//

#ifndef CURVEASSIGNMENT_LAGRANGECURVE_H
#define CURVEASSIGNMENT_LAGRANGECURVE_H


#include "Freeform.h"

class LagrangeCurve : public Freeform {
    std::vector<float> knots;

public:
    void addControlPoint(float2 p);

    float2 getPoint(float t);

    void setColor();
};

#endif //CURVEASSIGNMENT_LAGRANGECURVE_H
