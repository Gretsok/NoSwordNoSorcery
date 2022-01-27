#include "dungeonview2d.h"
#include "gldisplaywidget.h"
#include <GL/glu.h>
#include "iostream"
DungeonView2D::DungeonView2D()
{

}

void DungeonView2D::Render(void){
    glBegin(GL_QUADS);
        glColor3f((57.f/255.f),(162.f/255.f),(219.f/255.f));
        glVertex3f(-4,4,0);
        glVertex3f(4,4,0);
        glVertex3f(4,-4,0);
        glVertex3f(-4,-4,0);
    glEnd();
}
