#ifndef DUNGEONCONTROLLER_H
#define DUNGEONCONTROLLER_H

#include "acontroller.h"
#include "adungeonview.h"
#include "dungeonview2d.h"
#include "dungeonview3d.h"
#include "dungeonmodel.h"


class DungeonController : public AController
{
public:
    DungeonController();
    void OnViewSwitched();
};

#endif // DUNGEONCONTROLLER_H
