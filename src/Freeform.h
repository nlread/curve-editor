//
// Created by Ned on 3/23/2016.
//

#ifndef CURVEASSIGNMENT_FREEFORM_H
#define CURVEASSIGNMENT_FREEFORM_H

#define SELECTION_DISTANCE .05

#include "float2.h"
#include "Curve.h"

class Freeform : public Curve {
protected:
    std::vector<float2> controlPoints = std::vector<float2>();
    int draggingControlPointIndex = -1;

public:
    void manipulateObjectConstructive(float2 pointClicked);

    void manipulateObjectDestructive(float2 pointClicked);

    void beginManipulateObjectDrag(float2 beginPoint);

    void manipulateObjectDrag(float2 destinationPoint);

    void endManipulateObjectDrag();

    int findNearControlPointIndex(float2 pointNearTo, float maxDistance);

    virtual void addControlPoint(float2 p);

    std::vector<float2> * getPointsToDraw();

    virtual bool canBeDrawn();

    int numControlPoints();

    virtual float2 getPoint(float t) = 0;

    virtual void setColor() = 0;

};

#endif //CURVEASSIGNMENT_FREEFORM_H
