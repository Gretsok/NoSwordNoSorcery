#ifndef ACOLLIDER_H
#define ACOLLIDER_H

#include "amodel.h"
#include "collision.h"
#include "line.h"
#include "acollisionobserver.h"
#include <QVector3D>

class ACollider : public AModel
{
public:
    static bool AreIntersected(QVector3D a_intersectorOrigin, QVector3D a_intersectorVector, QVector3D a_intersectedOrigin, QVector3D a_intersectedVector);
    static bool AreIntersected(QVector3D a_intersectorOrigin, QVector3D a_vectorIntersecter, QVector3D a_circleCenter, float a_circleRadius);
    static QVector3D GetVectorFromTwoPoints(QVector3D a_origin, QVector3D a_destionation);
    ACollider();
    ACollider(QVector3D a_center);
    virtual ~ACollider();
    void OnMove(QVector3D a_newOrigin);
    virtual Collision IsCollidingWithMe(QVector3D a_intersectorOrigin, QVector3D a_intersectorVector);
    QVector3D GetOrigin();
    void SetOrigin(QVector3D);
    virtual std::list<OrientedLine> Debug_GetLines();
    void AddCollisionObserver(ACollisionObserver* a_collisionObserver);
    void RemoveCollisionObserver(ACollisionObserver* a_collisionObserver);
    bool IsTrigger();

private:
    void check_collisions();

protected:
    QVector3D m_origin;
    virtual std::list<OrientedLine> get_intersectors();
    std::list<ACollisionObserver*> m_collisionObservers;
    std::list<ACollisionObserver*>& GetCollisionObservers();
    void notify_collision(Collision a_collision, bool a_startedCollision = false);
    bool m_isTrigger = false;

};

#endif // ACOLLIDER_H
