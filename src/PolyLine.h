//
// Created by Ned on 3/23/2016.
//

#ifndef CURVEASSIGNMENT_POLYLINE_H
#define CURVEASSIGNMENT_POLYLINE_H

#define _USE_MATH_DEFINES
#define SELECTION_DISTANCE 0.05

#include <math.h>
#include "Object.h"

/**
 * Points connected in order by straight lines.
 */
class PolyLine : public Object {
    std::vector<float2> points = std::vector<float2>();
    int draggingPointIndex = -1;

public:
    /**
     * Draw the Polyline with lines connecting the points in order.
     */
    void drawObject() {
        glBegin(GL_LINE_STRIP);
        {
            for (int i = 0; i < points.size(); i++) {
                glVertex2f(points[i].x, points[i].y);
            }
        }
        glEnd();
    }

    /**
     * Add the provided point to the polyline.
     */
    void manipulateObjectConstructive(float2 pointClicked) {
        points.push_back(pointClicked);
    }

    /**
     * Remove a point (if any) near the given point.
     */
    void manipulateObjectDestructive(float2 pointClicked) {
        int index = findNearPointIndex(pointClicked, SELECTION_DISTANCE);
        if (index != -1)
            points.erase(points.begin() + index);

    }

    /**
     * Mark a point near the given point, to be dragged.
     */
    void beginManipulateObjectDrag(float2 beginPoint) {
        int index = findNearPointIndex(beginPoint, SELECTION_DISTANCE);
        draggingPointIndex = index;
    }

    /**
     * Move the point marked for dragging to the specified point
     */
    void manipulateObjectDrag(float2 destinationPoint) {
        if (draggingPointIndex != -1) {
            points[draggingPointIndex] = destinationPoint;
        }
    }

    /**
     * Mark that no point is being dragged.
     */
    void endManipulateObjectDrag() {
        draggingPointIndex = -1;
    }

    /**
     * Finds the index of a point near the specified point.
     * Returns -1 if none is found.
     */
    int findNearPointIndex(float2 nearPoint, float maxDistance) {
        for (int i = 0; i < points.size(); i++) {
            if ((nearPoint - points[i]).norm() < maxDistance) {
                return i;
            }
        }
        return -1;
    }

    bool closeToPoint(float2 point, float maxDistance) {
        for (int i = 1; i < points.size(); i++) {
            float dist = distToLine(point, points[i - 1], points[i]);
            if (dist <= maxDistance) {
                return true;
            }
        }
        return false;
    }

    /**
     * Calculates the distance from a point to the line segment formed points provided.
     *
     */
    float distToLine(float2 point, float2 l1, float2 l2) {
        if((point.x > l1.x && point.x > l2.x) || (point.y > l1.y && point.y > l2.y) ||
           (point.x < l1.x && point.x < l2.x) || (point.y < l1.y && point.y < l2.y))
            return 1000000;

        double alpha = atan((point.y - l1.y) / (point.x - l1.x));
        double beta = atan((l1.x - l2.x) / (l1.y - l2.y));
        double theta = M_PI / 2 - alpha - beta;

        if(theta < 0) {
            alpha = atan((point.x - l1.x) / (point.y - l1.y));
            beta = atan((l1.y - l2.y) / (l1.x - l2.x));
            theta = M_PI / 2 - alpha - beta;
        }
        return (float) (sin(theta) * (point - l1).norm());
    }

    void addPoint(float2 point) {
        points.push_back(point);
    }

    /**
     * Polylines are drawn in Yellow
     */
    void setColor() {
        glColor3d(1.0, 1.0, 0.0);
    }

    /**
     * Polylines with less than two points cannot be drawn
     */
    bool canBeDrawn() {
        return points.size() >= 2;
    }

    std::vector<float2> *getPointsToDraw() {
        return &points;
    }

};


#endif //CURVEASSIGNMENT_POLYLINE_H
