#include "characterview3d.h"
#include <QDebug>
#include "utils.h"

CharacterView3D::CharacterView3D()
{

}

void CharacterView3D::Render(void){
    QVector3D point3D;


    glBegin(GL_LINE_STRIP);
        glColor3f(0.f, 0.f,0.f);
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()+0.25f,m_gamePositions.y()+0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y(),point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()+0.25f,m_gamePositions.y()-0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y(),point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()+0.25f,m_gamePositions.y()-0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()+0.25f,m_gamePositions.y()+0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()+0.25f,m_gamePositions.y()+0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y(),point3D.z());
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(0.f, 0.f,0.f);
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()+0.25f,m_gamePositions.y()-0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y(),point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()-0.25f,m_gamePositions.y()-0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y(),point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()-0.25f,m_gamePositions.y()-0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()+0.25f,m_gamePositions.y()-0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()+0.25f,m_gamePositions.y()-0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y(),point3D.z());
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(0.f, 0.f,0.f);
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()-0.25f,m_gamePositions.y()-0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()-0.25f,m_gamePositions.y()+0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()+0.25f,m_gamePositions.y()+0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()+0.25f,m_gamePositions.y()-0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
    glEnd();


    glBegin(GL_QUADS);
        glColor3f(1.f, 0.f,0.f);
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()-0.25f,m_gamePositions.y()-0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y(),point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()-0.25f,m_gamePositions.y()+0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y(),point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()+0.25f,m_gamePositions.y()+0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y(),point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()+0.25f,m_gamePositions.y()-0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y(),point3D.z());
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(1.f, 0.f,0.f);
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()-0.25f,m_gamePositions.y()-0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y(),point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()-0.25f,m_gamePositions.y()+0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y(),point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()-0.25f,m_gamePositions.y()+0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()-0.25f,m_gamePositions.y()-0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(1.f, 0.f,0.f);
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()-0.25f,m_gamePositions.y()+0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y(),point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()+0.25f,m_gamePositions.y()+0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y(),point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()+0.25f,m_gamePositions.y()+0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()-0.25f,m_gamePositions.y()+0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
    glEnd();

}
