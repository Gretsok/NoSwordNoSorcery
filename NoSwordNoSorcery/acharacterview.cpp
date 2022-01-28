#include "acharacterview.h"
#include "windows.h"
#include "charactermodel.h"

ACharacterView::ACharacterView()
{

}


QVector2D ACharacterView::GetInputs() const
{
    QVector2D inputs = QVector2D(0, 0);
    if (GetKeyState('S') < 0)
    {
        inputs += QVector2D(0, -1);
    }
    else if (GetKeyState('Z') < 0)
    {
        inputs += QVector2D(0, 1);
    }
    if (GetKeyState('Q') < 0)
    {
        inputs += QVector2D(-1, 0);
    }
    else if (GetKeyState('D') < 0)
    {
        inputs += QVector2D(1, 0);
    }

    if(inputs.lengthSquared() > 1)
    {
        inputs.normalize();
    }

    return inputs;
}

void ACharacterView::SetGamePositions(QVector3D a_gamePositions)
{
    this->m_gamePositions = a_gamePositions;
}

