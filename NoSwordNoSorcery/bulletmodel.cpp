#include "bulletmodel.h"
#include "gamemanager.h"

BulletModel::BulletModel()
{
    this->m_lifeTime = 5.f;
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
    m_timeOfExistence += GameManager::GetDeltaTime();
    if(m_timeOfExistence >= m_lifeTime)
    {
        m_isDead = true;
    }
}
