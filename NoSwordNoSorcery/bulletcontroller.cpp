#include "bulletcontroller.h"
#include "bulletmodel.h"
#include "bulletview3d.h"
#include "bulletview2d.h"
#include "bulletsmanager.h"
#include "qdebug.h"

BulletController::BulletController()
{
    this->Model = new BulletModel();
    this->View = new BulletView2D();
}

BulletController::~BulletController()
{

}

void BulletController::OnViewSwitched()
{

}
void BulletController::UpdateGameStates(void)
{
    this->AController::UpdateGameStates();
    ((ABulletView*) this->View)->SetGamePositions(((BulletModel*) this->Model)->GetPositions());
    if(((BulletModel*) this->Model)->IsDead())
    {
        qDebug() << "AskToDestroyBullet";
        BulletsManager::DestroyBullet(this);
    }
}


