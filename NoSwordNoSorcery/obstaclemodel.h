#ifndef OBSTACLEMODEL_H
#define OBSTACLEMODEL_H

#include "amodel.h"

class ObstacleModel : public AModel
{
public:
    ObstacleModel();
    ObstacleModel(float,float);
    float xPosition;
    float yPosition;
};

#endif // OBSTACLEMODEL_H
