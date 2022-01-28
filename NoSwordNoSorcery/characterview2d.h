#ifndef CHARACTERVIEW2D_H
#define CHARACTERVIEW2D_H

#include "acharacterview.h"
#include <QGLWidget>

class CharacterView2D : public ACharacterView
{
public:
    CharacterView2D();
    void Render(void);
};

#endif // CHARACTERVIEW2D_H
