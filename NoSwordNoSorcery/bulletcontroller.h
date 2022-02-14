#ifndef BULLETCONTROLLER_H
#define BULLETCONTROLLER_H

#include "acontroller.h"
#include "abulletview.h"
#include "bulletmodel.h"

class BulletController : public AController
{
public:
    BulletController();
    virtual ~BulletController();
    virtual void OnViewSwitched();
    virtual void UpdateGameStates(void);
};

#endif // BULLETCONTROLLER_H
