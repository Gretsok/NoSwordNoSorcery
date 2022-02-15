#include "bulletview3d.h"
#include "utils.h"


BulletView3D::BulletView3D()
{

}

BulletView3D::~BulletView3D()
{

}

void BulletView3D::Render(void)
{
    QVector3D gamePosition3D = Convert2Dto3DPoint(this->m_gamePositions);
    glBegin(GL_POLYGON);
        glColor3f(0.5f, 0.5f,0.f);
        glVertex3f(gamePosition3D.x(), gamePosition3D.y() - 0.1,0);
        glVertex3f(gamePosition3D.x() + 0.075, gamePosition3D.y() - 0.075,0);
        glVertex3f(gamePosition3D.x() + 0.1, gamePosition3D.y(),0);
        glVertex3f(gamePosition3D.x() + 0.075, gamePosition3D.y() + 0.075,0);
        glVertex3f(gamePosition3D.x(), gamePosition3D.y() + 0.1,0);
        glVertex3f(gamePosition3D.x() - 0.075, gamePosition3D.y() + 0.075,0);
        glVertex3f(gamePosition3D.x() - 0.1, gamePosition3D.y(),0);
        glVertex3f(gamePosition3D.x() - 0.075, gamePosition3D.y() - 0.075,0);
    glEnd();
}
