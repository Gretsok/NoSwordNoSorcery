#include "dungeonview2d.h"
#include <QDebug>

DungeonView2D::DungeonView2D()
{
   //qDebug()<< "constructor DungeonView2D";
}

DungeonView2D::~DungeonView2D()
{

}

void DungeonView2D::DrawTopDoor(void){
    glBegin(GL_QUADS);
        glColor3f(0.f,0.f,0.f);
        glVertex3f(-1,4,0);
        glVertex3f(1,4,0);
        glVertex3f(0.5,3.5,0);
        glVertex3f(-0.5,3.5,0);
    glEnd();
}

void DungeonView2D::DrawRightDoor(void){
    glBegin(GL_QUADS);
        glColor3f(0.f,0.f,0.f);
        glVertex3f(3.5,0.5,0);
        glVertex3f(4,1,0);
        glVertex3f(4,-1,0);
        glVertex3f(3.5,-0.5,0);
    glEnd();
}

void DungeonView2D::DrawLeftDoor(void){
    glBegin(GL_QUADS);
        glColor3f(0.f,0.f,0.f);
        glVertex3f(-3.5,0.5,0);
        glVertex3f(-4,1,0);
        glVertex3f(-4,-1,0);
        glVertex3f(-3.5,-0.5,0);
    glEnd();
}

void DungeonView2D::DrawBottomDoor(void){
    glBegin(GL_QUADS);
        glColor3f(0.f,0.f,0.f);
        glVertex3f(-1,-4,0);
        glVertex3f(1,-4,0);
        glVertex3f(0.5,-3.5,0);
        glVertex3f(-0.5,-3.5,0);
    glEnd();
}

void DungeonView2D::DrawTreasure(void){
    glBegin(GL_QUADS);
        glColor3f(1.f,215.f/255.f,0.f);
        glVertex3f(-1,1,0);
        glVertex3f(1,1,0);
        glVertex3f(1,-1,0);
        glVertex3f(-1,-1,0);
    glEnd();
}

void DungeonView2D::Render(void){

    //MURS
    glBegin(GL_LINE_STRIP);
        glColor3f(0.f,0.f,0.f);
        glVertex3f(-4,4,0);
        glVertex3f(4,4,0);
        glVertex3f(3.5,3.5,0);
        glVertex3f(-3.5,3.5,0);
        glVertex3f(-4,4,0);
    glEnd();
    glBegin(GL_QUADS);
    //rgb(57,162,219)
        glColor3f((57.f/255.f),(162.f/255.f),(219.f/255.f));
        glVertex3f(-4,4,0);
        glVertex3f(4,4,0);
        glVertex3f(3.5,3.5,0);
        glVertex3f(-3.5,3.5,0);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glColor3f(0.f,0.f,0.f);
        glVertex3f(-4,-4,0);
        glVertex3f(-4,4,0);
        glVertex3f(-3.5,3.5,0);
        glVertex3f(-3.5,-3.5,0);
        glVertex3f(-4,-4,0);
    glEnd();
    glBegin(GL_QUADS);
    //rgb(57,162,219)
        glColor3f((57.f/255.f),(162.f/255.f),(219.f/255.f));
        glVertex3f(-4,-4,0);
        glVertex3f(-4,4,0);
        glVertex3f(-3.5,3.5,0);
        glVertex3f(-3.5,-3.5,0);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glColor3f(0.f,0.f,0.f);
        glVertex3f(4,4,0);
        glVertex3f(4,-4,0);
        glVertex3f(3.5,-3.5,0);
        glVertex3f(3.5,3.5,0);
        glVertex3f(4,4,0);
    glEnd();
    glBegin(GL_QUADS);
    //rgb(57,162,219)
        glColor3f((57.f/255.f),(162.f/255.f),(219.f/255.f));
        glVertex3f(4,4,0);
        glVertex3f(4,-4,0);
        glVertex3f(3.5,-3.5,0);
        glVertex3f(3.5,3.5,0);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glColor3f(0.f,0.f,0.f);
        glVertex3f(4,-4,0);
        glVertex3f(-4,-4,0);
        glVertex3f(-3.5,-3.5,0);
        glVertex3f(3.5,-3.5,0);
        glVertex3f(4,-4,0);
    glEnd();
    glBegin(GL_QUADS);
    //rgb(57,162,219)
        glColor3f((57.f/255.f),(162.f/255.f),(219.f/255.f));
        glVertex3f(4,-4,0);
        glVertex3f(-4,-4,0);
        glVertex3f(-3.5,-3.5,0);
        glVertex3f(3.5,-3.5,0);
    glEnd();


    //SOL
    glBegin(GL_QUADS);
    //rgb(162, 219, 250)
        glColor3f((162.f/255.f),(219.f/255.f),(250.f/255.f));
        glVertex3f(-4,4,0);
        glVertex3f(4,4,0);
        glVertex3f(4,-4,0);
        glVertex3f(-4,-4,0);
    glEnd();

}

void DungeonView2D::DrawObstacles(std::vector<ObstacleModel> obstacles){
    float x;
    float y;
    for(unsigned long long i = 0;i<obstacles.size();i++){
        x = obstacles[i].xPosition;
        y = obstacles[i].yPosition;
        glBegin(GL_QUADS);
            glColor3f(0.f,1.f,0.f);
            glVertex3f(x-0.25,y-0.25,0);
            glVertex3f(x-0.25,y+0.25,0);
            glVertex3f(x+0.25,y+0.25,0);
            glVertex3f(x+0.25,y-0.25,0);
        glEnd();
    }
}
