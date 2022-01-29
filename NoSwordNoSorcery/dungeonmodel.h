#ifndef DUNGEONMODEL_H
#define DUNGEONMODEL_H

#include "amodel.h"
#include "collidercontroller.h"
#include "dungeongenerator.h"

class DungeonModel : public AModel
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
protected:
    ColliderController* m_topCollider;
    ColliderController* m_rightCollider;
    ColliderController* m_botCollider;
    ColliderController* m_leftCollider;
    void SwitchView(bool a_to3D);

private:
    void switch_to_2D();
    void switch_to_3D();

};

#endif // DUNGEONMODEL_H
