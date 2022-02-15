#ifndef DUNGEONMODEL_H
#define DUNGEONMODEL_H

#include "amodel.h"
#include "collidercontroller.h"
#include "dungeongenerator.h"
#include "acollisionobserver.h"
#include "dungeoncontroller.h"



class DungeonModel : public AModel, ACollisionObserver
{
public:
    DungeonModel();
    DungeonModel(DungeonController*);
    virtual ~DungeonModel();
    DungeonGenerator dungeonGenerator;
    DungeonController* dungeonController;
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
    void ClearRoomColliders(void);
    void MoveRoom(short);
    virtual void HandleCollision(Collision, bool a_startedCollision);
    void HandleTopDoorCollision(Collision);
    void HandleBottomDoorCollision(Collision);
    void HandleLeftDoorCollision(Collision);
    void HandleRightDoorCollision(Collision);
protected:
    ColliderController* m_wallsCollider;
    ColliderController* m_topDoorCollider;
    ColliderController* m_bottomDoorCollider;
    ColliderController* m_leftDoorCollider;
    ColliderController* m_rightDoorCollider;
    ACollisionObserver* m_topDoorCollisionObserver;
    ACollisionObserver* m_bottomDoorCollisionObserver;
    ACollisionObserver* m_leftDoorCollisionObserver;
    ACollisionObserver* m_rightDoorCollisionObserver;
private:
    void generate_door_colliders();
};

class TopDoorCollisionObserver : public ACollisionObserver
{
public:
    TopDoorCollisionObserver();
    TopDoorCollisionObserver(DungeonModel *dungeon){
        this->dungeon = dungeon;
    }
    virtual ~TopDoorCollisionObserver();
    DungeonModel* dungeon;
    virtual void HandleCollision(Collision collision, bool a_startedCollision){
        if(!collision.IsCollidingColliderTrigger)
            dungeon->HandleTopDoorCollision(collision);
    };
};

class BottomDoorCollisionObserver : public ACollisionObserver
{
public:
    BottomDoorCollisionObserver();
    BottomDoorCollisionObserver(DungeonModel *dungeon){
        this->dungeon = dungeon;
    }
    virtual ~BottomDoorCollisionObserver();
    DungeonModel* dungeon;
    virtual void HandleCollision(Collision collision, bool a_startCollision){
        if(!collision.IsCollidingColliderTrigger)
            dungeon->HandleBottomDoorCollision(collision);
    };
};

class LeftDoorCollisionObserver : public ACollisionObserver
{
public:
    LeftDoorCollisionObserver();
    LeftDoorCollisionObserver(DungeonModel *dungeon){
        this->dungeon = dungeon;
    }
    virtual ~LeftDoorCollisionObserver();
    DungeonModel* dungeon;
    virtual void HandleCollision(Collision collision, bool a_startedCollision){
        if(!collision.IsCollidingColliderTrigger)
            dungeon->HandleLeftDoorCollision(collision);
    };
};

class RightDoorCollisionObserver : public ACollisionObserver
{
public:
    RightDoorCollisionObserver();
    RightDoorCollisionObserver(DungeonModel *dungeon){
        this->dungeon = dungeon;
    }
    virtual ~RightDoorCollisionObserver();
    DungeonModel* dungeon;
    virtual void HandleCollision(Collision collision, bool a_startedCollision){
        if(!collision.IsCollidingColliderTrigger)
            dungeon->HandleRightDoorCollision(collision);
    };
};

#endif // DUNGEONMODEL_H
