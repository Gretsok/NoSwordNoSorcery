#ifndef BULLETMODEL_H
#define BULLETMODEL_H

#include "aphysicalobjectmodel.h"

class BulletModel : public APhysicalObjectModel
{
public:
    BulletModel();
    ~BulletModel();
    bool IsDead();
private:
    float m_lifeTime;
    float m_timeOfExistence;
    bool m_isDead = false;
protected:
    virtual void UpdateGameStates(void);
};

#endif // BULLETMODEL_H
