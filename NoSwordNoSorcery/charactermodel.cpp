#include "charactermodel.h"

#include<QDebug>
CharacterModel::CharacterModel() : APhysicalObjectModel()
{
    this->m_2DCollider = new ColliderController(new Collider2DSquare(QVector3D(0, 0, 0), QVector3D(0.25f, 0.25f, 0)));
    this->m_accelerationSpeed = 8.f;
}

CharacterModel::~CharacterModel()
{
    delete this->m_2DCollider;
}

void CharacterModel::SetMovementInput(QVector2D a_inputs)
{
    this->ApplyAcceleration(QVector3D(a_inputs.x(), a_inputs.y(), 0) * this->m_accelerationSpeed);
}
