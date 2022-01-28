#include "aphysicalobjectmodel.h"
#include "collider2dsquare.h"


APhysicalObjectModel::APhysicalObjectModel()
{
    this->m_2DCollider = Collider2DSquare();
    this->m_currentMovement = QVector3D();
    this->m_deceleration = 3.f;
    this->m_deceleration = 5.f;
}

void APhysicalObjectModel::ApplyAcceleration(QVector3D a_accelerationToAdd)
{

}

void APhysicalObjectModel::HandlingCollision(Collision collision)
{

}
