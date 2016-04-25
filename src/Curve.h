//
// Created by Ned on 3/23/2016.
//

#ifndef CURVEASSIGNMENT_CURVE_H
#define CURVEASSIGNMENT_CURVE_H

#include "Object.h"

#define STEP .001

class Curve : public Object {
    bool validPoints = false;
    const static int numPoints = (int) (1 / STEP) + 1;
    float2 points[numPoints];
public:

    virtual void drawObject();

    virtual void invalidatePoints();

    virtual void calculatePoints();

    virtual bool closeToPoint(float2 point, float maxDistance);

    virtual float2 getPoint(float t) = 0;

    virtual void manipulateObjectConstructive(float2 pointClicked) = 0;

    virtual void manipulateObjectDestructive(float2 pointClicked) = 0;

    virtual void setColor() = 0;

    virtual bool canBeDrawn() = 0;
};


#endif //CURVEASSIGNMENT_CURVE_H
