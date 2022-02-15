#ifndef ADUNGEONVIEW_H
#define ADUNGEONVIEW_H

#include "aview.h"
#include "qvector3d.h"
class ADungeonView : public AView
{
public:
    ADungeonView();
    virtual ~ADungeonView();
    virtual void Render(void);
    virtual void DrawTopDoor() = 0;
    virtual void DrawBottomDoor() = 0;
    virtual void DrawLeftDoor() = 0;
    virtual void DrawRightDoor() = 0;
    virtual void DrawTreasure() = 0;
    QVector3D GetBottomDoorEntrancePosition();
    QVector3D GetTopDoorEntrancePosition();
    QVector3D GetRightDoorEntrancePosition();
    QVector3D GetLeftDoorEntrancePosition();
};

#endif // ADUNGEONVIEW_H
