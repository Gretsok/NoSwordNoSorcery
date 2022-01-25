#ifndef BADBLOBMODEL_H
#define BADBLOBMODEL_H

#include "acombatmanagermodel.h"
#include "aphysicalobjectmodel.h"
#include "adamagedealermodel.h"

class BadBlobModel : public ACombatManagerModel, public APhysicalObjectModel, public ADamageDealerModel
{
public:
    BadBlobModel();
};

#endif // BADBLOBMODEL_H
