#include "dungeonmodel.h"

DungeonModel::DungeonModel()
{

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
