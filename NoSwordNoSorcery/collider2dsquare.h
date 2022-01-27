#ifndef COLLIDER2DSQUARE_H
#define COLLIDER2DSQUARE_H

#include "acollider.h"

class Collider2DSquare : public ACollider
{
public:
    Collider2DSquare();
    Collider2DSquare(QVector3D a_center, QVector3D a_cornerLocalPoint);
    Collision* IsCollidingWithMe(QVector3D a_intersectorOrigin, QVector3D a_intersectorVector);

protected:
    QVector3D m_cornerLocalPoint;
    std::list<QVector3D> get_intersectors();
    std::list<QVector3D> get_borders();
};

#endif // COLLIDER2DSQUARE_H
