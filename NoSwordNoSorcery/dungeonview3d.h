#ifndef DUNGEONVIEW3D_H
#define DUNGEONVIEW3D_H

#include "adungeonview.h"
#include <QGLWidget>

class DungeonView3D : public ADungeonView
{
public:
    DungeonView3D();
    void Render(void);
    void DrawTopDoor();
    void DrawBottomDoor();
    void DrawLeftDoor();
    void DrawRightDoor();
    void DrawTreasure();
    QVector3D GetBottomDoorEntrancePosition();
    QVector3D GetTopDoorEntrancePosition();
    QVector3D GetLeftDoorEntrancePosition();
    QVector3D GetRightDoorEntrancePosition();
};

#endif // DUNGEONVIEW3D_H
