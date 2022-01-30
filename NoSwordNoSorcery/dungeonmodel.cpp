#include "dungeonmodel.h"
#include "collider2dsquare.h"
#include "QDebug"

DungeonModel::DungeonModel()
{
    /*this->m_topCollider = NULL;
    this->m_rightCollider = NULL;
    this->m_botCollider = NULL
    this->m_leftCollider = ne*/
    this->m_topDoorCollisionObserver = new TopDoorCollisionObserver(this);
    this->switch_to_2D();
    ((ACollider*)this->m_wallsCollider->Model)->AddCollisionObserver(this);
}

DungeonModel::~DungeonModel()
{
    /*delete this->m_topCollider;
    delete this->m_rightCollider;
    delete this->m_botCollider ;
    delete this->m_leftCollider ;*/
    delete this->m_wallsCollider;
    delete this->m_topDoorCollider;
    delete this->m_bottomDoorCollider;
    ((ACollider*)this->m_wallsCollider->Model)->RemoveCollisionObserver(this);
    if(this->TopDoor())
        ((ACollider*)this->m_topDoorCollider->Model)->RemoveCollisionObserver(m_topDoorCollisionObserver);
}

void DungeonModel::SwitchView(bool a_to3D)
{
    if(a_to3D)
    {

        /*delete this->m_topCollider;
        delete this->m_rightCollider;
        delete this->m_botCollider ;
        delete this->m_leftCollider ;*/
        delete this->m_wallsCollider;
        delete this->m_topDoorCollider;
        delete this->m_bottomDoorCollider;
        this->switch_to_3D();
    }
    else
    {
        /*
        delete this->m_topCollider;
        delete this->m_rightCollider;
        delete this->m_botCollider ;
        delete this->m_leftCollider ;*/
        delete this->m_wallsCollider;
        delete this->m_topDoorCollider;
        delete this->m_bottomDoorCollider;
        this->switch_to_2D();
    }
}

void DungeonModel::switch_to_2D()
{
    /*this->m_topCollider = new ColliderController(new Collider2DSquare(QVector3D(0, 8, 0), QVector3D(4, 4, 0)));
    this->m_rightCollider = new ColliderController(new Collider2DSquare(QVector3D(8, 0, 0), QVector3D(4, 4, 0)));
    this->m_botCollider = new ColliderController(new Collider2DSquare(QVector3D(0, -8, 0), QVector3D(-4, -4, 0)));
    this->m_leftCollider = new ColliderController(new Collider2DSquare(QVector3D(-8, 0, 0), QVector3D(-4, -4, 0)));*/
    this->m_wallsCollider = new ColliderController(new Collider2DSquare(QVector3D(0,0,0), QVector3D(4,4,0)));
    if(this->TopDoor()){
        this->m_topDoorCollider = new ColliderController(new Collider2DSquare(QVector3D(0,4,0),QVector3D(0.5,0.5,0)));
        ((ACollider*)this->m_topDoorCollider->Model)->AddCollisionObserver(m_topDoorCollisionObserver);
    }
    if(this->BottomDoor()){
        this->m_topDoorCollider = new ColliderController(new Collider2DSquare(QVector3D(0,-4,0),QVector3D(1,1,0)));
    }
}
void DungeonModel::switch_to_3D()
{
    qCritical() << "Implement dungeon walls 3D collider";
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
    this->yRoomIndex = this->yRoomIndex+1;
}
void DungeonModel::MoveLeftRoom(){
    this->yRoomIndex = this->yRoomIndex-1;
}
void DungeonModel::MoveTopRoom(){
    this->xRoomIndex = this->xRoomIndex-1;
}
void DungeonModel::MoveBottomRoom(){
    this->xRoomIndex = this->xRoomIndex+1;
}

void DungeonModel::HandleCollision(Collision a_collision)
{
   qDebug()<< "Implement dungeon wall collide";
}

void DungeonModel::HandleTopDoorCollision(Collision a_collision)
{
    qDebug() << "Switch Top Door";
}
