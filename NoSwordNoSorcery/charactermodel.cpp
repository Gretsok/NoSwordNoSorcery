#include "charactermodel.h"

#include<QDebug>
CharacterModel::CharacterModel()
{
    this->m_accelerationSpeed = 8.f;
}

void CharacterModel::SetMovementInput(QVector2D a_inputs)
{
    qDebug() << "inputs : " << a_inputs;
    this->ApplyAcceleration(QVector3D(a_inputs.x(), a_inputs.y(), 0) * this->m_accelerationSpeed);
}
