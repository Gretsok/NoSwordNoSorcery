#ifndef DUNGEONCONTROLLER_H
#define DUNGEONCONTROLLER_H

#include "acontroller.h"
#include "adungeonview.h"
#include "dungeonview2d.h"
#include "dungeonview3d.h"
#include "charactercontroller.h"

class DungeonController : public AController
{
public:
    DungeonController();
    DungeonController(CharacterController*);
    virtual ~DungeonController();
    void OnViewSwitched();
    void Render(void);
    void MoveRoom(short);
    CharacterController* m_characterController;
};

#endif // DUNGEONCONTROLLER_H
