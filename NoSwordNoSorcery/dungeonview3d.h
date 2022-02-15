#ifndef DUNGEONVIEW3D_H
#define DUNGEONVIEW3D_H

#include "adungeonview.h"
#include <QGLWidget>

class DungeonView3D : public ADungeonView
{
public:
    DungeonView3D();
    virtual ~DungeonView3D();
    virtual void Render(void);
    virtual void DrawTopDoor();
    virtual void DrawBottomDoor();
    virtual void DrawLeftDoor();
    virtual void DrawRightDoor();
    void DrawTreasure();
    QVector3D GetBottomDoorEntrancePosition();
    QVector3D GetTopDoorEntrancePosition();
    QVector3D GetLeftDoorEntrancePosition();
    QVector3D GetRightDoorEntrancePosition();
};

#endif // DUNGEONVIEW3D_H
