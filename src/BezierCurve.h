//
// Created by Ned on 3/23/2016.
//

#ifndef CURVEASSIGNMENT_BEZIERCURVE_H
#define CURVEASSIGNMENT_BEZIERCURVE_H


#include "Freeform.h"

class BezierCurve : public Freeform {

    float2 getPoint(float t);

    void setColor();

    double static berstein(int i, int n, double t) {
        if (n == 1) {
            if (i == 0) return 1 - t;
            if (i == 1) return t;
            return 0;
        }
        if (i < 0 || i > n) return 0;
        return (1 - t) * berstein(i, n - 1, t) +
               t * berstein(i - 1, n - 1, t);
    }

};


#endif //CURVEASSIGNMENT_BEZIERCURVE_H
