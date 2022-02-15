#include "dungeoncontroller.h"
#include "iostream"
#include <QDebug>
#include "dungeonmodel.h"
#include "gamemanager.h"


DungeonController::DungeonController(){
    //this->View = new DungeonView2D();
    //this->Viewis3D = false;
    //this->Model = new DungeonModel(this);
}

DungeonController::DungeonController(CharacterController* character_controller)
{
    if(GameManager::IsView3D()){
        this->View = new DungeonView3D();
    }
    else{
        this->View = new DungeonView2D();
    }
    this->Model = new DungeonModel(this);
    this->m_characterController = character_controller;
}

DungeonController::~DungeonController(){
    delete this->Model;
    delete this->View;
}

void DungeonController::OnViewSwitched(){
    //PENSER A DESTROY LES OBJETS
    if(GameManager::IsView3D()){
        delete this->View;
        this->View = new DungeonView3D();
    }
    else{
        delete this->View;
        this->View = new DungeonView2D();
    }
}

void DungeonController::Render(void){
    if(((DungeonModel *)this->Model)->IsFinalRoom()){
        ((ADungeonView *)this->View)->DrawTreasure();
    }
    if(((DungeonModel *)this->Model)->TopDoor()){
        ((ADungeonView *)this->View)->DrawTopDoor();
    }
    if(((DungeonModel *)this->Model)->LeftDoor()){
        ((ADungeonView *)this->View)->DrawLeftDoor();
    }
    //if(!Viewis3D){
        if(((DungeonModel *)this->Model)->RightDoor()){
            ((ADungeonView *)this->View)->DrawRightDoor();
        }
        if(((DungeonModel *)this->Model)->BottomDoor()){
            ((ADungeonView *)this->View)->DrawBottomDoor();
        }
    //}
    AController::Render();
    if(GameManager::IsView3D()){
        if(((DungeonModel *)this->Model)->RightDoor()){
            ((ADungeonView *)this->View)->DrawRightDoor();
        }
        if(((DungeonModel *)this->Model)->BottomDoor()){
            ((ADungeonView *)this->View)->DrawBottomDoor();
        }
    }
}

void DungeonController::MoveRoom(short i)
{
    switch(i){
    case 0:
        this->m_characterController->OnRoomChange(((ADungeonView*)this->View)->GetBottomDoorEntrancePosition());
        break;
    case 1:
        this->m_characterController->OnRoomChange(((ADungeonView*)this->View)->GetTopDoorEntrancePosition());
        break;
    case 2:
        this->m_characterController->OnRoomChange(((ADungeonView*)this->View)->GetRightDoorEntrancePosition());
        break;
    case 3:
        this->m_characterController->OnRoomChange(((ADungeonView*)this->View)->GetLeftDoorEntrancePosition());
        break;
    }


}
