#include "charactercontroller.h"
#include "gamemanager.h"
#include "bulletsmanager.h"
#include<QDebug>

CharacterController::CharacterController(){
    this->View = new CharacterView3D();
    this->Viewis3D = true;
    this->Model = new CharacterModel();
    this->m_timeSinceLastShot = 0.f;
    this->m_shootingCooldown = 0.5f;

}

CharacterController::~CharacterController(){

}

void CharacterController::OnViewSwitched()
{    //PENSER A DESTROY LES OBJETS
    if(this->Viewis3D){
        delete this->View;
        this->View = new CharacterView2D();
        this->Viewis3D = false;
    }
    else{
        delete this->View;
        this->View = new CharacterView3D();
        this->Viewis3D = true;
    }
}

void CharacterController::UpdateGameStates(void)
{
    this->AController::UpdateGameStates();
    ((CharacterModel*) this->Model)->SetMovementInput(((ACharacterView*) this->View)->GetInputs());
    ((ACharacterView*) this->View)->SetGamePositions(((CharacterModel*) this->Model)->GetPositions());
    this->m_timeSinceLastShot += GameManager::GetDeltaTime();
    if(((ACharacterView*) this->View)->IsShooting())
    {
        if(this->m_timeSinceLastShot > this->m_shootingCooldown)
        {
            qDebug() << "SHOOT";
            BulletsManager::CreateNewBullet(((CharacterModel*) this->Model)->GetPositions() + ((CharacterModel*) this->Model)->GetDirection() * 0.5f,
                                            ((CharacterModel*) this->Model)->GetDirection(),
                                            10.f);

            this->m_timeSinceLastShot = 0.f;
        }

    }
}

void CharacterController::Render(void)
{
    this->View->Render();
}

void CharacterController::OnRoomChange(QVector3D newCharacterPosition)
{
    ((CharacterModel*)this->Model)->SetPositions(newCharacterPosition);
}
