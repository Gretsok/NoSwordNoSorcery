#include "dungeonmodel.h"
#include "collider2dsquare.h"
#include "QDebug"

DungeonModel::DungeonModel()
{
    this->m_topDoorCollisionObserver = new TopDoorCollisionObserver(this);
    this->m_bottomDoorCollisionObserver = new BottomDoorCollisionObserver(this);
    this->m_leftDoorCollisionObserver = new LeftDoorCollisionObserver(this);
    this->m_rightDoorCollisionObserver = new RightDoorCollisionObserver(this);
    this->m_wallsCollider = new ColliderController(new Collider2DSquare(QVector3D(0,0,0), QVector3D(4,4,0)));
    this->generate_door_colliders();
    ((ACollider*)this->m_wallsCollider->Model)->AddCollisionObserver(this);
}

DungeonModel::DungeonModel(DungeonController* controller)
{
    this->dungeonController = controller;
    this->m_topDoorCollisionObserver = new TopDoorCollisionObserver(this);
    this->m_bottomDoorCollisionObserver = new BottomDoorCollisionObserver(this);
    this->m_leftDoorCollisionObserver = new LeftDoorCollisionObserver(this);
    this->m_rightDoorCollisionObserver = new RightDoorCollisionObserver(this);
    this->m_wallsCollider = new ColliderController(new Collider2DSquare(QVector3D(0,0,0), QVector3D(4,4,0)));
    this->generate_door_colliders();
    ((ACollider*)this->m_wallsCollider->Model)->AddCollisionObserver(this);
}

DungeonModel::~DungeonModel()
{
    ((ACollider*)this->m_wallsCollider->Model)->RemoveCollisionObserver(this);
    if(this->TopDoor())
        ((ACollider*)this->m_topDoorCollider->Model)->RemoveCollisionObserver(m_topDoorCollisionObserver);
    if(this->BottomDoor())
        ((ACollider*)this->m_bottomDoorCollider->Model)->RemoveCollisionObserver(m_bottomDoorCollisionObserver);
    if(this->LeftDoor())
        ((ACollider*)this->m_leftDoorCollider->Model)->RemoveCollisionObserver(m_leftDoorCollisionObserver);
    if(this->RightDoor())
        ((ACollider*)this->m_rightDoorCollider->Model)->RemoveCollisionObserver(m_rightDoorCollisionObserver);
    delete this->m_wallsCollider;
    delete this->m_topDoorCollider;
    delete this->m_bottomDoorCollider;
    delete this->m_leftDoorCollider;
    delete this->m_rightDoorCollider;
}

void DungeonModel::generate_door_colliders()
{
    if(this->TopDoor()){
        this->m_topDoorCollider = new ColliderController(new Collider2DSquare(QVector3D(0,4.2,0),QVector3D(0.5,0.5,0), true));
        ((ACollider*)this->m_topDoorCollider->Model)->AddCollisionObserver(m_topDoorCollisionObserver);
    }
    if(this->BottomDoor()){
        this->m_bottomDoorCollider = new ColliderController(new Collider2DSquare(QVector3D(0,-4.2,0),QVector3D(0.5,0.5,0), true));
        ((ACollider*)this->m_bottomDoorCollider->Model)->AddCollisionObserver(m_bottomDoorCollisionObserver);
    }
    if(this->LeftDoor()){
        this->m_leftDoorCollider = new ColliderController(new Collider2DSquare(QVector3D(-4.2,0,0),QVector3D(0.5,0.5,0), true));
        ((ACollider*)this->m_leftDoorCollider->Model)->AddCollisionObserver(m_leftDoorCollisionObserver);
    }
    if(this->RightDoor()){
        this->m_rightDoorCollider = new ColliderController(new Collider2DSquare(QVector3D(4.2,0,0),QVector3D(0.5,0.5,0), true));
        ((ACollider*)this->m_rightDoorCollider->Model)->AddCollisionObserver(m_rightDoorCollisionObserver);
    }
}

bool DungeonModel::TopDoor(){
    if(this->xRoomIndex>0){
        return dungeonGenerator.dungeonLayout[this->xRoomIndex-1][this->yRoomIndex]!=0;
    }
    else return false;
}
bool DungeonModel::BottomDoor(){
    if(this->xRoomIndex<4){
        return dungeonGenerator.dungeonLayout[this->xRoomIndex+1][this->yRoomIndex]!=0;
    }
    else return false;
}
bool DungeonModel::LeftDoor(){
    if(this->yRoomIndex>0){
        return dungeonGenerator.dungeonLayout[this->xRoomIndex][this->yRoomIndex-1]!=0;
    }
    else return false;
}
bool DungeonModel::RightDoor(){
    if(this->yRoomIndex<4){
        return dungeonGenerator.dungeonLayout[this->xRoomIndex][this->yRoomIndex+1]!=0;
    }
    else return false;
}

void DungeonModel::MoveRightRoom(){
    this->ClearRoomColliders();
    this->yRoomIndex = this->yRoomIndex+1;
    this->MoveRoom(3);
}
void DungeonModel::MoveLeftRoom(){
    this->ClearRoomColliders();
    this->yRoomIndex = this->yRoomIndex-1;
    this->MoveRoom(2);
}
void DungeonModel::MoveTopRoom(){
    this->ClearRoomColliders();
    this->xRoomIndex = this->xRoomIndex-1;
    this->MoveRoom(0);
}
void DungeonModel::MoveBottomRoom(){
    this->ClearRoomColliders();
    this->xRoomIndex = this->xRoomIndex+1;
    this->MoveRoom(1);
}

void DungeonModel::ClearRoomColliders(){
    if(this->TopDoor()){
        ((ACollider*)this->m_topDoorCollider->Model)->RemoveCollisionObserver(m_topDoorCollisionObserver);
        delete this->m_topDoorCollider;
    }
    if(this->BottomDoor()){
        ((ACollider*)this->m_bottomDoorCollider->Model)->RemoveCollisionObserver(m_bottomDoorCollisionObserver);
        delete this->m_bottomDoorCollider;
    }
    if(this->LeftDoor()){
        ((ACollider*)this->m_leftDoorCollider->Model)->RemoveCollisionObserver(m_leftDoorCollisionObserver);
        delete this->m_leftDoorCollider;
    }
    if(this->RightDoor()){
        ((ACollider*)this->m_rightDoorCollider->Model)->RemoveCollisionObserver(m_rightDoorCollisionObserver);
        delete this->m_rightDoorCollider;
    }
}

void DungeonModel::HandleCollision(Collision)
{

}

void DungeonModel::MoveRoom(short i){
    this->generate_door_colliders();
    this->dungeonController->MoveRoom(i);
}

void DungeonModel::HandleTopDoorCollision(Collision a_collision)
{
    this->MoveTopRoom();
}

void DungeonModel::HandleBottomDoorCollision(Collision a_collision)
{
    this->MoveBottomRoom();
}

void DungeonModel::HandleLeftDoorCollision(Collision a_collision)
{
    this->MoveLeftRoom();
}

void DungeonModel::HandleRightDoorCollision(Collision a_collision)
{
    this->MoveRightRoom();
}
