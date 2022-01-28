#ifndef DUNGEONMODEL_H
#define DUNGEONMODEL_H

#include "amodel.h"
#include "collidercontroller.h"

class DungeonModel : public AModel
{
public:
    DungeonModel();
    ~DungeonModel();
protected:
    ColliderController* m_topCollider;
    ColliderController* m_rightCollider;
    ColliderController* m_botCollider;
    ColliderController* m_leftCollider;
    void SwitchView(bool a_to3D);
private:
    void switch_to_2D();
    void switch_to_3D();

};

#endif // DUNGEONMODEL_H
