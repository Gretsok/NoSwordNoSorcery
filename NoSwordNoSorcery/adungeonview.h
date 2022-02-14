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
    virtual QVector3D GetBottomDoorEntrancePosition() = 0;
    virtual QVector3D GetTopDoorEntrancePosition() = 0;
    virtual QVector3D GetRightDoorEntrancePosition() = 0;
    virtual QVector3D GetLeftDoorEntrancePosition() = 0;
};

#endif // ADUNGEONVIEW_H
