#ifndef DUNGEONMODEL_H
#define DUNGEONMODEL_H

#include "amodel.h"
#include "collidercontroller.h"
#include "dungeongenerator.h"
#include "acollisionobserver.h"




class DungeonModel : public AModel, ACollisionObserver
{
public:
    DungeonModel();
    ~DungeonModel();
    DungeonGenerator dungeonGenerator;
    int xRoomIndex = dungeonGenerator.startRoomX;
    int yRoomIndex = dungeonGenerator.startRoomY;
    bool TopDoor(void);
    bool BottomDoor(void);
    bool LeftDoor(void);
    bool RightDoor(void);
    void MoveRightRoom(void);
    void MoveLeftRoom(void);
    void MoveTopRoom(void);
    void MoveBottomRoom(void);
    virtual void HandleCollision(Collision);
    void HandleTopDoorCollision(Collision);
protected:
    /*ColliderController* m_topCollider;
    ColliderController* m_rightCollider;
    ColliderController* m_botCollider;
    ColliderController* m_leftCollider;*/
    ColliderController* m_wallsCollider;
    ColliderController* m_topDoorCollider;
    ColliderController* m_bottomDoorCollider;
    ColliderController* m_leftDoorCollider;
    ColliderController* m_rightDoorCollider;
    ACollisionObserver* m_topDoorCollisionObserver;
    void SwitchView(bool a_to3D);

private:
    void switch_to_2D();
    void switch_to_3D();
};

class TopDoorCollisionObserver : public ACollisionObserver
{
public:
    TopDoorCollisionObserver();
    TopDoorCollisionObserver(DungeonModel *dungeon){
        this->dungeon = dungeon;
    }
    ~TopDoorCollisionObserver();
    DungeonModel* dungeon;
    virtual void HandleCollision(Collision collision){
        dungeon->HandleTopDoorCollision(collision);
    };
};

#endif // DUNGEONMODEL_H
