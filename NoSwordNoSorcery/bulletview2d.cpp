#include "bulletview2d.h"
#include <qdebug.h>

BulletView2D::BulletView2D()
{

}

BulletView2D::~BulletView2D()
{
    qDebug() << "deleting bullet view";
}

void BulletView2D::Render(void)
{
    glBegin(GL_POLYGON);
        glColor3f(0.5f, 0.5f,0.f);
        //glVertex3f(this->m_gamePositions.x() - 0.1, this->m_gamePositions.y() - 0.1,0);
        glVertex3f(this->m_gamePositions.x(), this->m_gamePositions.y() - 0.1,0);
        glVertex3f(this->m_gamePositions.x() + 0.075, this->m_gamePositions.y() - 0.075,0);
        glVertex3f(this->m_gamePositions.x() + 0.1, this->m_gamePositions.y(),0);
        glVertex3f(this->m_gamePositions.x() + 0.075, this->m_gamePositions.y() + 0.075,0);
        glVertex3f(this->m_gamePositions.x(), this->m_gamePositions.y() + 0.1,0);
        glVertex3f(this->m_gamePositions.x() - 0.075, this->m_gamePositions.y() + 0.075,0);
        glVertex3f(this->m_gamePositions.x() - 0.1, this->m_gamePositions.y(),0);
        glVertex3f(this->m_gamePositions.x() - 0.075, this->m_gamePositions.y() - 0.075,0);
    glEnd();
}
