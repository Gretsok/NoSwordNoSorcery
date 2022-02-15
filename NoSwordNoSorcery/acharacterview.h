#ifndef ACHARACTERVIEW_H
#define ACHARACTERVIEW_H

#include "QVector2D"
#include "QVector3D"
#include "aview.h"

class ACharacterView : public AView
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
