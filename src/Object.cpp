//
// Created by Ned on 3/23/2016.
//

#include "Object.h"

/**
 * Draw the object if possible. Then draw the points used to define the object.
 * Set colors and width if object is the selected object.
 * Selected points are drawn in white
 */
void Object::draw() {
    if (!canBeDrawn())
        return;

    if (selected) {                 //Use Selected Colors/Width
        glColor3d(0.0, 0.0, 1.0);
        glLineWidth(5.0);
    } else {                        //Use Object Type Colors/Width
        setColor();
        glLineWidth(1.0);
    }

    drawObject();

    std::vector<float2> *points = getPointsToDraw();
    if (points != NULL) {
        if (selected)
            glColor3d(1.0, 1.0, 1.0);
        drawPoints(points);
    }
}

void Object::drawPoints(std::vector <float2> *points) {
    glBegin(GL_TRIANGLES);
    {
        for (int i = 0; i < points->size(); i++) {
            float2 point = points->at(i);
            glVertex2f(point.x, point.y + .015f);
            glVertex2f(point.x - .015f, point.y - .015f);
            glVertex2f(point.x + .015f, point.y - .015f);
        }
    }
    glEnd();
}

std::vector<float2> *Object::getPointsToDraw() {
    return NULL;
}

void Object::setSelected(bool newVal) {
    selected = newVal;
}