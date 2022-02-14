#ifndef BULLETVIEW2D_H
#define BULLETVIEW2D_H

#include "abulletview.h"

class BulletView2D : public ABulletView
{
public:
    BulletView2D();
    virtual ~BulletView2D();
    virtual void Render(void);
};

#endif // BULLETVIEW2D_H
