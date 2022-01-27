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
};

#endif // ACONTROLLER_H
