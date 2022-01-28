#include "characterview2d.h"

CharacterView2D::CharacterView2D()
{

}

void CharacterView2D::Render(void){
    glBegin(GL_LINES);
        glColor3f(1.f,0.f,0.f);
        glVertex3f(-1,-1,0);
        glVertex3f(-1,1,0);
        glVertex3f(1,1,0);
        glVertex3f(1,-1,0);
    glEnd();
}
