//
// Created by Ned on 3/18/2016.
//

#ifndef CURVEASSIGNMENT_FLOAT2_H
#define CURVEASSIGNMENT_FLOAT2_H
class float2
{
public:
    float x;
    float y;

    float2();

    float2(float x, float y);

    float2 operator-() const;

    float2 operator+(const float2& addOperand) const;

    float2 operator-(const float2& operand) const;

    float2 operator*(const float2& operand) const;

    float2 operator*(float operand) const;

    void operator-=(const float2& a);

    void operator+=(const float2& a);

    void operator*=(const float2& a);

    void operator*=(float a);

    float norm();

    float norm2();

    float2 normalize();

    static float2 random();
};

#endif //CURVEASSIGNMENT_FLOAT2_H
