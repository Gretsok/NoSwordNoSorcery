#ifndef DUNGEONVIEW2D_H
#define DUNGEONVIEW2D_H

#include "adungeonview.h"
#include <QGLWidget>

class DungeonView2D : public ADungeonView
{
public:
    DungeonView2D();
    virtual ~DungeonView2D();
    virtual void Render(void);
    virtual void DrawTopDoor();
    virtual void DrawBottomDoor();
    virtual void DrawLeftDoor();
    virtual void DrawRightDoor();
    void DrawTreasure();
    QVector3D GetBottomDoorEntrancePosition();
    QVector3D GetTopDoorEntrancePosition();
    QVector3D GetRightDoorEntrancePosition();
    QVector3D GetLeftDoorEntrancePosition();
};

#endif // DUNGEONVIEW2D_H
