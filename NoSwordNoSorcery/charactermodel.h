#ifndef CHARACTERMODEL_H
#define CHARACTERMODEL_H

#include "acombatmanagermodel.h"
#include "aphysicalobjectmodel.h"
#include "collider2dsquare.h"

class CharacterModel : public ACombatManagerModel, public APhysicalObjectModel
{
public:
    CharacterModel();
    void SetMovementInput();
};

#endif // CHARACTERMODEL_H
