#include "acontroller.h"

AController::AController()
{

}

void AController::Render(void){
    View->Render();
}

void AController::UpdateGameStates(void)
{
    Model->UpdateGameStates();
    View->Update();
}
