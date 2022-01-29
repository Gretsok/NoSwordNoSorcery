#include "aphysicalobjectmodel.h"
#include "collider2dsquare.h"
#include "gamemanager.h"
#include<QDebug>

APhysicalObjectModel::APhysicalObjectModel()
{
    this->m_2DCollider = new ColliderController(new Collider2DSquare());
    this->m_currentMovement = QVector3D();
    this->m_deceleration = 3.f;
    this->m_maxSpeed = 5.f;
    this->m_speed = 0.f;
    ((ACollider*)this->m_2DCollider->Model)->AddCollisionObserver(this);
    qDebug() << "Collision observer added";
}

APhysicalObjectModel::~APhysicalObjectModel()
{
    ((ACollider*)this->m_2DCollider->Model)->RemoveCollisionObserver(this);
    delete this->m_2DCollider;
}

void APhysicalObjectModel::ApplyAcceleration(QVector3D a_accelerationToAdd)
{
    m_currentMovement *= m_speed;
    m_currentMovement += a_accelerationToAdd * GameManager::GetDeltaTime();
    m_speed = m_currentMovement.length();
    m_currentMovement.normalize();
}

void APhysicalObjectModel::UpdateGameStates(void)
{
    ((ACollider*) this->m_2DCollider->Model)->OnMove(m_currentMovement * this->m_speed * GameManager::GetDeltaTime());
    this->m_speed -= this->m_deceleration * GameManager::GetDeltaTime();

}

QVector3D APhysicalObjectModel::GetPositions()
{
    return ((ACollider*) this->m_2DCollider->Model)->GetOrigin();
}

void APhysicalObjectModel::HandleCollision(Collision a_collision)
{
    qDebug() << "On est des boss";
}
