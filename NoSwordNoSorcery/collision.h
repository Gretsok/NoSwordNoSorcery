#ifndef COLLISION_H
#define COLLISION_H

#include <QVector3D>

class Collision
{
public:
    Collision();
    Collision(QVector3D a_normal);
    QVector3D GetNormal();
    bool HasCollision = false;
private:
    QVector3D m_normal;
};

#endif // COLLISION_H
