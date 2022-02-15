#include "acontroller.h"
#include <QDebug>
AController::AController()
{

}


AController::~AController()
{
    qDebug() << "Deleting Model";
    delete this->Model;
    this->Model = NULL;
    qDebug() << "Deleting View";
    delete this->View;
    this->View = NULL;
}

void AController::Render(void){
    View->Render();
}

void AController::UpdateGameStates(void)
{
    Model->UpdateGameStates();
    View->Update();
}


