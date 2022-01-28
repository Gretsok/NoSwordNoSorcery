#include "dungeoncontroller.h"
#include "iostream"
#include <QDebug>


DungeonController::DungeonController(){
    this->View = new DungeonView2D();
    qDebug() << "DungeonView2D created";
    this->Model = new DungeonModel();
    qDebug() << "Dungeonmodel created";
}

void DungeonController::OnViewSwitched(){
    //PENSER A DESTROY LES OBJETS
    if(this->Viewis3D){
        delete this->View;
        this->View = new DungeonView2D();
    }
    else{
        delete this->View;
        this->View = new DungeonView3D();
    }
}
