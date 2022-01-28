#include "colliderview.h"

ColliderView::ColliderView()
{
}

ColliderView::~ColliderView()
{
}

void ColliderView::SetIntersectorsToDraw(std::list<OrientedLine> a_intersectors)
{
    this->m_intersectorsToDraw = a_intersectors;
}

void ColliderView::Render(void)
{
    std::list<OrientedLine>::iterator it;
    for(it = this->m_intersectorsToDraw.begin(); it != this->m_intersectorsToDraw.end(); ++it)
    {
        glBegin(GL_LINE_STRIP);
            glColor3f(0.f,1.f,0.f);
            glVertex3f((*it).GetOrigin().x(),(*it).GetOrigin().y(), (*it).GetOrigin().z());
            glVertex3f((*it).GetDestination().x(),(*it).GetDestination().y(), (*it).GetDestination().z());
        glEnd();
    }
}
