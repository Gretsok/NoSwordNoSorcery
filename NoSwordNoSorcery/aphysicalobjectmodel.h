#ifndef APHYSICALOBJECTMODEL_H
#define APHYSICALOBJECTMODEL_H

#include "amodel.h"
#include "acollider.h"
#include "QVector3D"

class APhysicalObjectModel : public AModel
{
public:
    APhysicalObjectModel();
    void ApplyAcceleration(QVector3D a_accelerationToAdd);
protected:
    ACollider m_2DCollider;
    QVector3D m_currentMovement;
    float m_deceleration;
    float m_maxSpeed;
    void HandlingCollision(Collision collision);
};

#endif // APHYSICALOBJECTMODEL_H
