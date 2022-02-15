#include "acontroller.h"
#include <QDebug>
AController::AController()
{

}


AController::~AController()
{
    qDebug() << "On vient ici ?";
    //delete this->Model;
    delete this->View;
}

void AController::Render(void){
    View->Render();
}

void AController::UpdateGameStates(void)
{
    Model->UpdateGameStates();
    View->Update();
}
