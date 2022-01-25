#ifndef CHARACTERMODEL_H
#define CHARACTERMODEL_H

#include "acombatmanagermodel.h"
#include "aphysicalobjectmodel.h"

class CharacterModel : public ACombatManagerModel, public APhysicalObjectModel
{
public:
    CharacterModel();
};

#endif // CHARACTERMODEL_H
