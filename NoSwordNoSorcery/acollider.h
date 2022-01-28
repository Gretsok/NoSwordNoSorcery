#ifndef ACOLLIDER_H
#define ACOLLIDER_H

#include "amodel.h"
#include "collision.h"
#include <QVector3D>

class ACollider : public AModel
{
    typedef void(*CollisionDelegate)(Collision);
public:
    static bool AreIntersected(QVector3D a_intersectorOrigin, QVector3D a_intersectorVector, QVector3D a_intersectedOrigin, QVector3D a_intersectedVector);
    static bool AreIntersected(QVector3D a_intersectorOrigin, QVector3D a_vectorIntersecter, QVector3D a_circleCenter, float a_circleRadius);
    static QVector3D GetVectorFromTwoPoints(QVector3D a_origin, QVector3D a_destionation);
    static std::list<ACollider*> RegisteredColliders;
    ACollider();
    ACollider(QVector3D a_center);
    ~ACollider();
    void OnMove(QVector3D a_newOrigin);
    Collision* IsCollidingWithMe(QVector3D a_intersectorOrigin, QVector3D a_intersectorVector);
    CollisionDelegate OnCollision;
    QVector3D GetOrigin();

private:
    void check_collisions();

protected:
    QVector3D m_origin;
    std::list<QVector3D> get_intersectors();
};

#endif // ACOLLIDER_H
