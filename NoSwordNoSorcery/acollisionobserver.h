#ifndef ACOLLISIONOBSERVER_H
#define ACOLLISIONOBSERVER_H
#include "collision.h"

class ACollisionObserver
{
public:
    ACollisionObserver();
    virtual void HandleCollision(Collision) = 0;
};

#endif // ACOLLISIONOBSERVER_H
