#ifndef VECTOR3_H
#define VECTOR3_H

/*
 * x and y coordinates represent the ground while the y coordinate represents height
 * */
class Vector3
{
public:
    static Vector3 GetZero();
    static Vector3 GetOne();
    static Vector3 GetUp();
    static Vector3 GetDown();
    static Vector3 GetRight();
    static Vector3 GetLeft();
    static Vector3 GetForward();
    static Vector3 GetBackward();

    Vector3();
    Vector3(float, float, float);
    void Normalize();
    float GetMagnitude();
    float DotProduct(Vector3);
    Vector3 CrossProduct(Vector3);
    Vector3& operator+(const Vector3&);
    Vector3& operator-(const Vector3&);
    Vector3& operator*(const float);
    Vector3& operator/(const float);
    float x;
    float y;
    float z;
};

#endif // VECTOR3_H
