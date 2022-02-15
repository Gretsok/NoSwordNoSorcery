#ifndef BULLETSMANAGER_H
#define BULLETSMANAGER_H

#include "QVector3D"
#include "bulletcontroller.h"

class BulletsManager
{
public:
    static void UpdateGameStates();
    static void Render();
    static void CreateNewBullet(QVector3D a_position, QVector3D a_direction, float a_force);
    static void DestroyBullet(BulletController* a_bulletToDestroy);
    static void DestroyAllBullets();
private:
    static std::list<BulletController*> s_bullets;
};

#endif // BULLETSMANAGER_H
