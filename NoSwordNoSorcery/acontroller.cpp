#include "acontroller.h"
#include <QDebug>
AController::AController()
{

}


AController::~AController()
{
    qDebug() << "Deleting Model";
    delete this->Model;
    qDebug() << "Deleting View";
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
