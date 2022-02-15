#include "charactermodel.h"
#include "collider2dsquare.h"
#include "collider2dcircle.h"

#include<QDebug>
CharacterModel::CharacterModel() : APhysicalObjectModel()
{
    this->m_2DCollider = new ColliderController(new Collider2DSquare(QVector3D(0, 0, 0), QVector3D(0.25f, 0.25f, 0)));
    //this->m_2DCollider = new ColliderController(new Collider2DCircle(QVector3D(0, 0, 0), 0.5f));
    this->m_accelerationSpeed = 8.f;
    this->m_2DCollider->GetModel<ACollider*>()->AddCollisionObserver(this);
}

CharacterModel::~CharacterModel()
{
    this->m_2DCollider->GetModel<ACollider*>()->RemoveCollisionObserver(this);
    delete this->m_2DCollider;
}

void CharacterModel::SetMovementInput(QVector2D a_inputs)
{
    this->ApplyAcceleration(QVector3D(a_inputs.x(), a_inputs.y(), 0) * this->m_accelerationSpeed);
}
