#ifndef APHYSICALOBJECTMODEL_H
#define APHYSICALOBJECTMODEL_H

#include "amodel.h"
#include "collidercontroller.h"
#include "QVector3D"

class APhysicalObjectModel : public AModel
{
public:
    APhysicalObjectModel();
    virtual ~APhysicalObjectModel();
    void ApplyAcceleration(QVector3D a_accelerationToAdd);
    virtual QVector3D GetPositions();
protected:
    ColliderController* m_2DCollider;
    QVector3D m_currentMovement;
    float m_deceleration;
    float m_speed;
    float m_maxSpeed;
    void HandlingCollision(Collision collision);
    virtual void UpdateGameStates(void);
};

#endif // APHYSICALOBJECTMODEL_H
