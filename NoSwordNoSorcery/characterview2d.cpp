#include "characterview2d.h"

CharacterView2D::CharacterView2D()
{

}

void CharacterView2D::Render(void){
    glBegin(GL_QUADS);
        glColor3f(1.f,0.f,0.f);
        glVertex3f(-0.25,-0.25,0);
        glVertex3f(-0.25,0.25,0);
        glVertex3f(0.25,0.25,0);
        glVertex3f(0.25,-0.25,0);
    glEnd();
}
