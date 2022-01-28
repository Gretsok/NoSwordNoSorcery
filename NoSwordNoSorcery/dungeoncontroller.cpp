#include "dungeoncontroller.h"
#include "iostream"


DungeonController::DungeonController(){
    this->View = new DungeonView2D();
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
