#include "bulletcontroller.h"
#include "bulletmodel.h"
#include "bulletview3d.h"
#include "bulletview2d.h"
#include "bulletsmanager.h"
#include "gamemanager.h"
#include "qdebug.h"

BulletController::BulletController()
{
    if(GameManager::IsView3D()){
        this->View = new BulletView3D();
    }
    else{
        this->View = new BulletView2D();
    }
    this->Model = new BulletModel();
}

BulletController::~BulletController()
{

}

void BulletController::OnViewSwitched()
{
    if(GameManager::IsView3D()){
        delete this->View;
        this->View = new BulletView3D();
    }
    else{
        delete this->View;
        this->View = new BulletView2D();
    }
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


