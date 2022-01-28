#ifndef DUNGEONVIEW2D_H
#define DUNGEONVIEW2D_H

#include "adungeonview.h"
#include <QGLWidget>

class DungeonView2D : public ADungeonView
{
public:
    DungeonView2D();
    void Render(void);
   // ~DungeonView2D();
};

#endif // DUNGEONVIEW2D_H
