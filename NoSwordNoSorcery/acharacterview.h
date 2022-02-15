#ifndef ACHARACTERVIEW_H
#define ACHARACTERVIEW_H

#include "acombatmanagerview.h"
#include "QVector2D"
#include "QVector3D"

class ACharacterView : public ACombatManagerView
{
public:
    ACharacterView();
    virtual ~ACharacterView();
    QVector2D GetInputs() const;
    bool IsShooting() const;
    void SetGamePositions(QVector3D a_gamePositions);
protected:
    QVector3D m_gamePositions;
};

#endif // ACHARACTERVIEW_H
