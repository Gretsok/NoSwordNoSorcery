#ifndef ACOLLISIONOBSERVER_H
#define ACOLLISIONOBSERVER_H
#include "collision.h"

class ACollisionObserver
{
public:
    ACollisionObserver();
    virtual ~ACollisionObserver();
    virtual void HandleCollision(Collision, bool a_startedCollision) = 0;
};

#endif // ACOLLISIONOBSERVER_H
