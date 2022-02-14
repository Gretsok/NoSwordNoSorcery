#ifndef COLLISION_H
#define COLLISION_H

#include <QVector3D>

class Collision
{
public:
    Collision();
    Collision(QVector3D a_normal);
    virtual ~Collision();
    QVector3D GetNormal();
    bool HasCollision = false;
    bool IsTrigger = false;
private:
    QVector3D m_normal;
};

#endif // COLLISION_H
