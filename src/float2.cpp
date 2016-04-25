//
// Created by Ned on 2/19/2016.
//

#include <stdlib.h>
#include <math.h>
#include "float2.h"

    float2::float2()
    {
        x = 0.0f;
        y = 0.0f;
    }

    float2::float2 (float x, float y) :x(x), y(y) {}

    float2 float2::operator-() const
    {
        return float2(-x, -y);
    }


    float2 float2::operator+(const float2& addOperand) const
    {
        return float2(x + addOperand.x, y + addOperand.y);
    }

    float2 float2::operator-(const float2& operand) const
    {
        return float2(x - operand.x, y - operand.y);
    }

    float2 float2::operator*(const float2& operand) const
    {
        return float2(x * operand.x, y * operand.y);
    }

    float2 float2::operator*(float operand) const
    {
        return float2(x * operand, y * operand);
    }

    void float2::operator-=(const float2& a)
    {
        x -= a.x;
        y -= a.y;
    }

    void float2::operator+=(const float2& a)
    {
        x += a.x;
        y += a.y;
    }

    void float2::operator*=(const float2& a)
    {
        x *= a.x;
        y *= a.y;
    }

    void float2::operator*=(float a)
    {
        x *= a;
        y *= a;
    }

    float float2::norm()
    {
        return sqrtf(x*x + y*y);
    }

    float float2::norm2()
    {
        return x*x + y*y;
    }

    float2 float2::normalize()
    {
        float oneOverLength = 1.0f / norm();
        x *= oneOverLength;
        y *= oneOverLength;
        return *this;
    }