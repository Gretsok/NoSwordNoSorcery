#ifndef ACONTROLLER_H
#define ACONTROLLER_H

#include "aview.h"
#include "amodel.h"
class AController
{
public:
    AView * View;
    AModel* Model;
    AController();

    virtual void UpdateGameStates(void);
    virtual void Render(void);
    bool Viewis3D;
    virtual void OnViewSwitched() = 0;
};

#endif // ACONTROLLER_H
