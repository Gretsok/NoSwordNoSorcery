#ifndef APHYSICALOBJECTMODEL_H
#define APHYSICALOBJECTMODEL_H

#include "amodel.h"
#include "collidercontroller.h"
#include "QVector3D"

class APhysicalObjectModel : public AModel, public ACollisionObserver
{
public:
    APhysicalObjectModel();
    virtual ~APhysicalObjectModel();
    void ApplyAcceleration(QVector3D a_accelerationToAdd);
    virtual QVector3D GetPositions();
    virtual void HandleCollision(Collision);
    void SetPositions(QVector3D);
protected:
    ColliderController* m_2DCollider;
    QVector3D m_currentMovement;
    float m_deceleration;
    float m_speed;
    float m_maxSpeed;
    virtual void UpdateGameStates(void);
};

#endif // APHYSICALOBJECTMODEL_H
