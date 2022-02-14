#ifndef COLLIDER2DCIRCLE_H
#define COLLIDER2DCIRCLE_H

#include "acollider.h"

class Collider2DCircle : public ACollider
{
public:
    Collider2DCircle();
    Collider2DCircle(QVector3D a_center, float a_radius, bool a_isTrigger = false);
    virtual ~Collider2DCircle();
    Collision IsCollidingWithMe(QVector3D a_intersectorOrigin, QVector3D a_intersectorVector);

protected:
    float m_radius;
    virtual std::list<OrientedLine> get_intersectors();
};

#endif // COLLIDER2DCIRCLE_H
