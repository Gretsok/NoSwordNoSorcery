#include "charactercontroller.h"
#include<QDebug>

CharacterController::CharacterController(){
    this->View = new CharacterView2D();
    this->Model = new CharacterModel();
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
}

void CharacterController::OnRoomChange(short pos)
{
    switch(pos){
        case 0:
            ((CharacterModel*) this->Model)->SetPositions(0.f,-3.f,0.f);
            break;
        case 1:
            ((CharacterModel*) this->Model)->SetPositions(0.f,3.f,0.f);
            break;
        case 2:
            ((CharacterModel*) this->Model)->SetPositions(3.f,0.f,0.f);
            break;
        case 3:
            ((CharacterModel*) this->Model)->SetPositions(-3.f,0.f,0.f);
            break;
        default:
            break;
    }


}
