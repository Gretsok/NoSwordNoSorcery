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
    virtual ~CharacterController();
    virtual void OnViewSwitched();
    virtual void UpdateGameStates(void);
    virtual void Render(void);
    void OnRoomChange(QVector3D);
private:
    float m_shootingCooldown;
    float m_timeSinceLastShot;
};

#endif // CHARACTERCONTROLLER_H
