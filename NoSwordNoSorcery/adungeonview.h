#ifndef ADUNGEONVIEW_H
#define ADUNGEONVIEW_H

#include "aview.h"

class ADungeonView : public AView
{
public:
    ADungeonView();
    void Render(void);
    virtual void DrawTopDoor() = 0;
    virtual void DrawBottomDoor() = 0;
    virtual void DrawLeftDoor() = 0;
    virtual void DrawRightDoor() = 0;
};

#endif // ADUNGEONVIEW_H
