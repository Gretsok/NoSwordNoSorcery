#ifndef CHARACTERVIEW3D_H
#define CHARACTERVIEW3D_H

#include "acharacterview.h"
#include <QGLWidget>

class CharacterView3D : public ACharacterView
{
public:
    CharacterView3D();
    virtual ~CharacterView3D();
    virtual void Render(void);
};

#endif // CHARACTERVIEW3D_H
