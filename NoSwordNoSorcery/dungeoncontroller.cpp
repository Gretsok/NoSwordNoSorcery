#include "dungeoncontroller.h"
#include "iostream"
#include <QDebug>


DungeonController::DungeonController(){
    this->View = new DungeonView2D();
    this->Viewis3D = false;
    this->Model = new DungeonModel();
}

void DungeonController::OnViewSwitched(){
    //PENSER A DESTROY LES OBJETS
    if(this->Viewis3D){
        delete this->View;
        this->View = new DungeonView2D();
        this->Viewis3D = false;
    }
    else{
        delete this->View;
        this->View = new DungeonView3D();
        this->Viewis3D = true;
    }
}

void DungeonController::Render(void){
    if(((DungeonModel *)this->Model)->TopDoor()){
        ((ADungeonView *)this->View)->DrawTopDoor();
    }
    if(((DungeonModel *)this->Model)->LeftDoor()){
        ((ADungeonView *)this->View)->DrawLeftDoor();
    }
    if(!Viewis3D){
        if(((DungeonModel *)this->Model)->RightDoor()){
            ((ADungeonView *)this->View)->DrawRightDoor();
        }
        if(((DungeonModel *)this->Model)->BottomDoor()){
            ((ADungeonView *)this->View)->DrawBottomDoor();
        }
    }
    AController::Render();
    if(Viewis3D){
        if(((DungeonModel *)this->Model)->RightDoor()){
            ((ADungeonView *)this->View)->DrawRightDoor();
        }
        if(((DungeonModel *)this->Model)->BottomDoor()){
            ((ADungeonView *)this->View)->DrawBottomDoor();
        }
    }
}
