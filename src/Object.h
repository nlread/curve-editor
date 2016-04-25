//
// Created by Ned on 3/23/2016.
//

#ifndef CURVEASSIGNMENT_OBJECT_H
#define CURVEASSIGNMENT_OBJECT_H


#include <GL/gl.h>
#include <stddef.h>
#include <vector>
#include "float2.h"

/**
 * Generic Curve or other object
 */

class Object {
protected:
    bool selected = false;
public:

    /**
     * Draw the object if possible. Then draw the points used to define the object.
     * Set colors and width if object is the selected object.
     * Selected points are drawn in white
     */
    void draw();

    void drawPoints(std::vector<float2> *points);

    void setSelected(bool newVal);

    virtual std::vector<float2> *getPointsToDraw();

    virtual void drawObject() = 0;

    virtual void manipulateObjectConstructive(float2 pointClicked) = 0;

    virtual void manipulateObjectDestructive(float2 pointClicked) = 0;

    virtual void beginManipulateObjectDrag(float2 beginPoint) = 0;

    virtual void manipulateObjectDrag(float2 destinationPoint) = 0;

    virtual void endManipulateObjectDrag() = 0;

    virtual bool closeToPoint(float2 point, float maxDistance) = 0;

    virtual void setColor() = 0;

    virtual bool canBeDrawn() = 0;

};




#endif //CURVEASSIGNMENT_OBJECT_H
