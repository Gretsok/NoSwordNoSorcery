#include "characterview2d.h"
#include <thread>         // std::thread
#include <unistd.h>
#include "windows.h"
#include <iostream>
#include <cstdlib>

void CharacterView2D::ChangeColor(){
    while(this->m_redValue<1.f || this->m_greenValue>0.f || this->m_blueValue>0.f){
        this->m_redValue = this->m_redValue+0.05f;
        this->m_greenValue = this->m_greenValue-0.05f;
        this->m_blueValue = this->m_blueValue-0.05f;
        sleep(1);
    }
}

CharacterView2D::CharacterView2D()
{
    this->m_redValue = 0;
    this->m_greenValue = 1;
    this->m_blueValue = 1;
}

CharacterView2D::~CharacterView2D()
{

}



void CharacterView2D::Render(void){
    glBegin(GL_QUADS);
        glColor3f(this->m_redValue,this->m_greenValue,this->m_blueValue);
        glVertex3f(this->m_gamePositions.x() - 0.25, this->m_gamePositions.y() - 0.25,0);
        glVertex3f(this->m_gamePositions.x() - 0.25, this->m_gamePositions.y() + 0.25,0);
        glVertex3f(this->m_gamePositions.x() + 0.25, this->m_gamePositions.y() + 0.25,0);
        glVertex3f(this->m_gamePositions.x() + 0.25, this->m_gamePositions.y() - 0.25,0);
    glEnd();
}
