#include "charactercontroller.h"

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
