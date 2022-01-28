#ifndef CHARACTERCONTROLLER_H
#define CHARACTERCONTROLLER_H

#include "acontroller.h"
#include "charactermodel.h"
#include "acharacterview.h"
#include "characterview2d.h"
#include "characterview3d.h"

class CharacterController : public AController
{
public:
    CharacterController();
    virtual void OnViewSwitched();
    virtual void UpdateGameStates(void);
};

#endif // CHARACTERCONTROLLER_H
