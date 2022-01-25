#ifndef ACOLLIDER_H
#define ACOLLIDER_H

#include "amodel.h"
#include <QVector3D>

class ACollider : public AModel
{
public:
    static bool AreIntersected(QVector3D a_intersectorOrigin, QVector3D a_intersectorVector, QVector3D a_intersectedOrigin, QVector3D a_intersectedVector);
    static bool AreIntersected(QVector3D a_intersectorOrigin, QVector3D a_vectorIntersecter, QVector3D a_circleCenter, float a_circleRadius);
    static QVector3D GetVectorFromTwoPoints(QVector3D a_origin, QVector3D a_destionation);
    static std::list<ACollider*> RegisteredColliders;
    ACollider();
    ~ACollider();
    void OnMove(QVector3D a_newOrigin);
    bool IsCollidingWithMe(QVector3D a_intersectorOrigin, QVector3D a_intersectorVector);
private:
    void check_collisions();

protected:
    QVector3D m_origin;
};

#endif // ACOLLIDER_H