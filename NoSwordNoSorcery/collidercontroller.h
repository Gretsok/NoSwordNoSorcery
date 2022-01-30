#ifndef COLLIDERCONTROLLER_H
#define COLLIDERCONTROLLER_H

#include "acontroller.h"
#include "acollider.h"

class ColliderController : public AController
{
public:
    ColliderController();
    ColliderController(ACollider* a_colliderToUse);
    virtual ~ColliderController();
    void ChangeCollider(ACollider* a_colliderToUse);
    static std::list<ColliderController*>& GetColliderControllers();
    void UpdateGameStates(void);
    void OnViewSwitched();
protected:
    static std::list<ColliderController*> m_colliderControllers;

};

#endif // COLLIDERCONTROLLER_H
