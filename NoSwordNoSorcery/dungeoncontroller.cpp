#include "dungeoncontroller.h"
#include "iostream"
#include <QDebug>
#include "dungeonmodel.h"
#include "gamemanager.h"


DungeonController::DungeonController(){

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

}

void DungeonController::OnViewSwitched(){
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
    ((ADungeonView *)this->View)->DrawObstacles(((DungeonModel *)this->Model)->GetObstaclesInRoom());

    if(((DungeonModel *)this->Model)->IsFinalRoom()){
        ((ADungeonView *)this->View)->DrawTreasure();
    }
    if(((DungeonModel *)this->Model)->HasTopDoor()){
        ((ADungeonView *)this->View)->DrawTopDoor();
    }
    if(((DungeonModel *)this->Model)->HasLeftDoor()){
        ((ADungeonView *)this->View)->DrawLeftDoor();
    }
    if(((DungeonModel *)this->Model)->HasRightDoor()){
        ((ADungeonView *)this->View)->DrawRightDoor();
    }
    if(((DungeonModel *)this->Model)->HasBottomDoor()){
        ((ADungeonView *)this->View)->DrawBottomDoor();
    }
    AController::Render();
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
