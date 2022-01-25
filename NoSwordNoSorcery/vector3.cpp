#include "vector3.h"
#include <cmath>

Vector3 Vector3::GetZero()
{
    return Vector3(0, 0, 0);
}
Vector3 Vector3::GetOne()
{
    return Vector3(1, 1, 1);
}
Vector3 Vector3::GetUp()
{
    return Vector3(0, 0, 1);
}
Vector3 Vector3::GetDown()
{
    return Vector3(0, 0, -1);
}
Vector3 Vector3::GetRight()
{
    return Vector3(1, 0, 0);
}
Vector3 Vector3::GetLeft()
{
    return Vector3(-1, 0, 0);
}
Vector3 Vector3::GetForward()
{
    return Vector3(0, 1, 0);
}
Vector3 Vector3::GetBackward()
{
    return Vector3(0, -1, 0);
}

Vector3::Vector3()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector3::Vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vector3::Normalize()
{

}

float Vector3::GetMagnitude()
{
    return sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
}
float Vector3::DotProduct(Vector3)
{

}
Vector3 Vector3::CrossProduct(Vector3)
{

}
Vector3& Vector3::operator+(const Vector3&)
{

}
Vector3& Vector3::operator-(const Vector3&)
{

}
Vector3& Vector3::operator*(const float)
{

}
Vector3& Vector3::operator/(const float)
{

}


