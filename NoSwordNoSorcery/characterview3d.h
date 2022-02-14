#ifndef CHARACTERVIEW3D_H
#define CHARACTERVIEW3D_H

#include "acharacterview.h"
#include <QGLWidget>

class CharacterView3D : public ACharacterView
{
public:
    CharacterView3D();
    void Render(void);
};

#endif // CHARACTERVIEW3D_H
