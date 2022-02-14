#ifndef CHARACTERMODEL_H
#define CHARACTERMODEL_H

#include "aphysicalobjectmodel.h"
#include <QVector2D>

class CharacterModel : public APhysicalObjectModel
{
public:
    CharacterModel();
    virtual ~CharacterModel();
    void SetMovementInput(QVector2D a_inputs);
protected:
    float m_accelerationSpeed;

};

#endif // CHARACTERMODEL_H
