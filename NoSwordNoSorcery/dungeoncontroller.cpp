#include "dungeoncontroller.h"
#include "iostream"


DungeonController::DungeonController(){
    this->View = new DungeonView2D();
    this->Model = new DungeonModel();
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
