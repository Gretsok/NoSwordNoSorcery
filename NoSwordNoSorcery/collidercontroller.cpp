#include "collidercontroller.h"
#include "colliderview.h"
#include "QDebug"

ColliderController::ColliderController()
{
    ColliderController::m_colliderControllers.push_back(this);
    this->View = new ColliderView();
}

ColliderController::ColliderController(ACollider* a_colliderToUse)
{
    ColliderController::m_colliderControllers.push_back(this);
    this->View = new ColliderView();
    this->Model = a_colliderToUse;
}

ColliderController::~ColliderController()
{
    delete this->View;
    delete this->Model;
    ColliderController::m_colliderControllers.remove(this);
}

void ColliderController::ChangeCollider(ACollider *a_colliderToUse)
{
    delete this->Model;
    this->Model = a_colliderToUse;
}

void ColliderController::UpdateGameStates(void)
{
    ((ColliderView*)this->View)->SetIntersectorsToDraw(((ACollider*)this->Model)->Debug_GetLines());
}

void ColliderController::OnViewSwitched()
{

}

std::list<ColliderController*> ColliderController::m_colliderControllers = std::list<ColliderController*>();
std::list<ColliderController*>& ColliderController::GetColliderControllers()
{
    return m_colliderControllers;
}
