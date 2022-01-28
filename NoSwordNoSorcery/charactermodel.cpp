#include "charactermodel.h"

#include<QDebug>
CharacterModel::CharacterModel()
{

}

void CharacterModel::SetMovementInput(QVector2D a_inputs)
{
    qDebug() << "inputs : " << a_inputs;
    this->ApplyAcceleration(QVector3D(a_inputs.x(), a_inputs.y(), 0));
}
