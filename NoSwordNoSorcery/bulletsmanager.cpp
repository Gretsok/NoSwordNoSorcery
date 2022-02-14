#include "bulletsmanager.h"
#include "bulletmodel.h"
#include <qdebug.h>

std::list<BulletController*> BulletsManager::s_bullets = std::list<BulletController*>();

void BulletsManager::UpdateGameStates()
{
    std::list<BulletController*>::iterator vIt;
    std::list<BulletController*> intersectors = BulletsManager::s_bullets;
    for(vIt = intersectors.begin(); vIt != intersectors.end(); ++vIt)
    {
        (*vIt)->UpdateGameStates();
    }
}

void BulletsManager::Render()
{
    std::list<BulletController*>::iterator vIt;
    std::list<BulletController*> intersectors = BulletsManager::s_bullets;
    for(vIt = intersectors.begin(); vIt != intersectors.end(); ++vIt)
    {
        (*vIt)->Render();
    }
}

void BulletsManager::CreateNewBullet(QVector3D a_position, QVector3D a_direction, float a_force)
{
    BulletController* newBullet = new BulletController();
    BulletsManager::s_bullets.push_back(newBullet);
    ((BulletModel*) newBullet->Model)->SetPositions(a_position);
    ((BulletModel*) newBullet->Model)->SetAcceleration(a_direction * a_force);
}

void BulletsManager::DestroyBullet(BulletController* a_bulletToDestroy)
{
    std::list<BulletController*>::iterator vIt;
    std::list<BulletController*> intersectors = BulletsManager::s_bullets;
    for(vIt = intersectors.begin(); vIt != intersectors.end(); ++vIt)
    {
        if((*vIt) == a_bulletToDestroy)
        {
            qDebug() << "bullet found in list";
            BulletsManager::s_bullets.remove(a_bulletToDestroy);
            delete a_bulletToDestroy;
        }
    }
}
