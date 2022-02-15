#include "aphysicalobjectmodel.h"
#include "collider2dsquare.h"
#include "gamemanager.h"
#include <cmath>
#include<QDebug>
#include<QQuaternion>

APhysicalObjectModel::APhysicalObjectModel()
{
    this->m_2DCollider = new ColliderController(new Collider2DSquare());
    this->m_currentMovement = QVector3D();
    this->m_deceleration = 3.f;
    this->m_maxSpeed = 5.f;
    this->m_speed = 0.f;
    ((ACollider*)this->m_2DCollider->Model)->AddCollisionObserver(this);
   //qDebug()<< "Collision observer added";
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

void APhysicalObjectModel::SetAcceleration(QVector3D a_acceleration)
{
    m_currentMovement = a_acceleration.normalized();
    m_speed = a_acceleration.length();
}

void APhysicalObjectModel::UpdateGameStates(void)
{
    if(GetPositions().z() != 0)
    {
        QVector3D pos = GetPositions();

        pos.setZ(0.f);

        SetPositions(pos);
    }
    ((ACollider*) this->m_2DCollider->Model)->OnMove(m_currentMovement * this->m_speed * GameManager::GetDeltaTime());
    this->m_speed -= this->m_deceleration * GameManager::GetDeltaTime();
    if(this->m_speed < 0.f)
    {
        m_speed = 0.f;
    }

}

QVector3D APhysicalObjectModel::GetPositions()
{
    return ((ACollider*) this->m_2DCollider->Model)->GetOrigin();
}

void APhysicalObjectModel::SetPositions(QVector3D vector)
{
    ((ACollider*) this->m_2DCollider->Model)->SetOrigin(vector);
}

QVector3D APhysicalObjectModel::GetDirection()
{
    if(m_currentMovement.length() == 0.f)
    {
        return QVector3D(0, 1.f, 0);
    }
    return this->m_currentMovement.normalized();
}

void APhysicalObjectModel::HandleCollision(Collision a_collision, bool a_startedCollision)
{
    if(!a_collision.IsCollidingAgainstColliderTrigger)
    {

        float theta = acos(QVector3D::dotProduct(-(this->GetDirection()), a_collision.GetNormal().normalized()));
        theta = (theta * 180.f) / 3.1415926f;

        QVector3D normalToSign = QVector3D::crossProduct(-(this->GetDirection()), a_collision.GetNormal());

        if(normalToSign.z() < 0)
        {
            theta = -theta;
        }

        qDebug() << theta;
        QQuaternion q = QQuaternion::fromEulerAngles(0.f, 0.f, 2 * theta);
        QVector3D newDirection = q.rotatedVector(-(this->GetDirection()));
        this->m_currentMovement = newDirection;
        if(this->m_speed < 1.f)
        {
            this->m_speed = 1.f;
        }
    }
}
