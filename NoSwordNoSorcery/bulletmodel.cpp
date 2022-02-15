#include "bulletmodel.h"
#include "gamemanager.h"
#include "collider2dcircle.h"
#include "qdebug.h"

BulletModel::BulletModel()
{
    this->m_2DCollider = new ColliderController(new Collider2DCircle(QVector3D(0, 0, 0), 0.1f, true));
    this->m_lifeTime = 10.f;
    ((ACollider*)this->m_2DCollider->Model)->AddCollisionObserver(this);
}

BulletModel::~BulletModel()
{

}

bool BulletModel::IsDead()
{
    return m_isDead;
}

void BulletModel::UpdateGameStates(void)
{
    APhysicalObjectModel::UpdateGameStates();
    m_timeOfExistence += GameManager::GetDeltaTime();
    if(m_timeOfExistence >= m_lifeTime)
    {
        m_isDead = true;
    }
}
