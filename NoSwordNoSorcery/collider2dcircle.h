#ifndef COLLIDER2DCIRCLE_H
#define COLLIDER2DCIRCLE_H

#include "acollider.h"

class Collider2DCircle : public ACollider
{
public:
    Collider2DCircle();
    Collider2DCircle(QVector3D a_center, float a_radius);
    bool IsCollidingWithMe(QVector3D a_intersectorOrigin, QVector3D a_intersectorVector);

protected:
    float m_radius;
    std::list<QVector3D> get_intersectors();
};

#endif // COLLIDER2DCIRCLE_H
