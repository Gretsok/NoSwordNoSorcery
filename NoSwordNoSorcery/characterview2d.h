#ifndef CHARACTERVIEW2D_H
#define CHARACTERVIEW2D_H

#include "acharacterview.h"
#include <QGLWidget>

class CharacterView2D : public ACharacterView
{
public:
    CharacterView2D();
    virtual ~CharacterView2D();
    virtual void Render(void);
    float m_redValue;
    float m_greenValue;
    float m_blueValue;
    void ChangeColor();
};

#endif // CHARACTERVIEW2D_H
