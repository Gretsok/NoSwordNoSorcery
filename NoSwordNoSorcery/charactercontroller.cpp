#include "charactercontroller.h"
#include "gamemanager.h"
#include "bulletsmanager.h"
#include<QDebug>

CharacterController::CharacterController(){
    this->View = new CharacterView3D();
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
    }
    else{
        delete this->View;
        this->View = new CharacterView3D();
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
                                            15.f);

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
    /*switch(pos){
        case 0:
            ((CharacterModel*) this->Model)->SetPositions(QVector3D(0.f,-3.f,0.f));
            break;
        case 1:
            ((CharacterModel*) this->Model)->SetPositions(QVector3D(0.f,3.f,0.f));
            break;
        case 2:
            ((CharacterModel*) this->Model)->SetPositions(QVector3D(3.f,0.f,0.f));
            break;
        case 3:
            ((CharacterModel*) this->Model)->SetPositions(QVector3D(-3.f,0.f,0.f));
            break;
        default:
            break;
    }*/


}
