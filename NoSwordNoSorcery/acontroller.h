#ifndef ACONTROLLER_H
#define ACONTROLLER_H

#include "aview.h"
#include "amodel.h"
class AController
{
public:
    AController();
    AView * View;
    AModel Model;
    void Render(void);
    bool Viewis3D;
};

#endif // ACONTROLLER_H
