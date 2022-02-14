#ifndef BULLETVIEW3D_H
#define BULLETVIEW3D_H

#include "abulletview.h"

class BulletView3D : public ABulletView
{
public:
    BulletView3D();
    virtual ~BulletView3D();
    virtual void Render(void);
};

#endif // BULLETVIEW3D_H
