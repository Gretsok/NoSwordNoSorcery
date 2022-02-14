#ifndef DUNGEONVIEW2D_H
#define DUNGEONVIEW2D_H

#include "adungeonview.h"
#include <QGLWidget>

class DungeonView2D : public ADungeonView
{
public:
    DungeonView2D();
    void Render(void);
    void DrawTopDoor();
    void DrawBottomDoor();
    void DrawLeftDoor();
    void DrawRightDoor();
    QVector3D GetBottomDoorEntrancePosition();
    QVector3D GetTopDoorEntrancePosition();
    QVector3D GetRightDoorEntrancePosition();
    QVector3D GetLeftDoorEntrancePosition();
};

#endif // DUNGEONVIEW2D_H
