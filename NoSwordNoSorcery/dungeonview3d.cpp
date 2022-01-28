#include "dungeonview3d.h"

DungeonView3D::DungeonView3D()
{

}

void sommetA(float layer=0){
    glVertex3f(0,-4,layer);
}
void sommetB(float layer=0){
    glVertex3f(-4,(((1.f/3.f)*4))-4,layer);
}
void sommetC(float layer=0){
    glVertex3f(0,(((2.f/3.f)*4))-4,layer);
}
void sommetD(float layer=0){
    glVertex3f(4,(((1.f/3.f)*4)-4),layer);
}
void sommetE(float layer=0){
    glVertex3f(0,(((2.f/3.f)*4)-4),layer);
}
void sommetF(float layer=0){
    glVertex3f(-4,0,layer);
}
void sommetG(float layer=0){
    glVertex3f(0,((1.f/3.f)*4),layer);
}
void sommetH(float layer=0){
    glVertex3f(4,0,layer);
}
void sommetI(float layer=0){
    glVertex3f(-(5.f/8.f)*4,(((1.f/3.f)*4)*(3.f/8.f)),layer);
}
void sommetJ(float layer=0){
    glVertex3f(-(3.f/8.f)*4,(((1.f/3.f)*4)*(5.f/8.f)),layer);
}
void sommetK(float layer=0){
    glVertex3f(-(3.f/8.f)*4,((((2.f/3.f)*4))-4)*(11.f/8.f),layer);
}
void sommetL(float layer=0){
    glVertex3f(-(5.f/8.f)*4,((((2.f/3.f)*4)-4)*(13.f/8.f)),layer);
}
void sommetM(float layer=0){
    glVertex3f((3.f/8.f)*4,(((1.f/3.f)*4)*(5.f/8.f)),layer);
}
void sommetN(float layer=0){
    glVertex3f((5.f/8.f)*4,(((1.f/3.f)*4)*(3.f/8.f)),layer);
}
void sommetO(float layer=0){
    glVertex3f((5.f/8.f)*4,((((2.f/3.f)*4)-4)*(13.f/8.f)),layer);
}
void sommetP(float layer=0){
    glVertex3f((3.f/8.f)*4,((((2.f/3.f)*4))-4)*(11.f/8.f),layer);
}
void sommetQ(float layer=0){
    glVertex3f((3.f/8.f)*4,(((2.f/3.f)*4)-4)+(3.f/8.f)*(-(((2.f/3.f)*4)-4)),layer);
}
void sommetR(float layer=0){
    glVertex3f((5.f/8.f)*4,(((2.f/3.f)*4)-4)+(5.f/8.f)*(-(((2.f/3.f)*4)-4)),layer);
}
/*
 * PLUS PETITE PORTE
void sommetQ(float layer=0){
    glVertex3f((3.f/8.f)*4,-(5.f/3.f),layer);
}
void sommetR(float layer=0){
    glVertex3f((5.f/8.f)*4,-(4.f/3.f),layer);
}*/
void sommetS(float layer=0){
    glVertex3f((5.f/8.f)*4,-4 + (5.f/8.f)*(1.f/3.f)*4,layer);
}
void sommetT(float layer=0){
    glVertex3f((3.f/8.f)*4,-4 + (3.f/8.f)*(1.f/3.f)*4,layer);
}
void sommetU(float layer=0){
    glVertex3f(-(5.f/8.f)*4,(((2.f/3.f)*4)-4)+(5.f/8.f)*(-(((2.f/3.f)*4)-4)),layer);
}
void sommetV(float layer=0){
    glVertex3f(-(3.f/8.f)*4,(((2.f/3.f)*4)-4)+(3.f/8.f)*(-(((2.f/3.f)*4)-4)),layer);
}
void sommetW(float layer=0){
    glVertex3f(-(3.f/8.f)*4,-4 + (3.f/8.f)*(1.f/3.f)*4,layer);
}
void sommetX(float layer=0){
    glVertex3f(-(5.f/8.f)*4,-4 + (5.f/8.f)*(1.f/3.f)*4,layer);
}
void sommetY(float layer=0){
    glVertex3f(0,((1.f/3.f)*4)+(1.f/4.f),layer);
}

void DungeonView3D::Render(){


    //LIGNES MURS TRANSPARENTS
    glBegin(GL_LINE_STRIP);
        glColor4f((220.f/255.f),(220.f/255.f),(220.f/255.f),0.1f);
        sommetA(0.001);
        sommetB(0.001);
        sommetF(0.001);
        sommetE(0.001);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glColor4f((220.f/255.f),(220.f/255.f),(220.f/255.f),0.1f);
        sommetA(0.001);
        sommetE(0.001);
        sommetH(0.001);
        sommetD(0.001);
    glEnd();


    //DESSUS DES MURS
    glBegin(GL_LINE_STRIP);
        glColor3f(0.f,0.f,0.f);
        //glVertex3f(-(1.f/3.f),((1.f/3.f)*4)+(1.f/8.f),0);
        sommetF();
        sommetG();
        sommetH();
        glVertex3f(4+(1.f/3.f),(1.f/8.f),0);
        sommetY();
        glVertex3f(-4-(1.f/3.f),(1.f/8.f),0);
        sommetF();
    glEnd();
    glBegin(GL_POLYGON);
    //rgb(30,130,150)
        glColor3f((30.f/255.f),(130.f/255.f),(150.f/255.f));
        sommetG();
        sommetH();
        glVertex3f(4+(1.f/3.f),(1.f/8.f),0);
        sommetY();
        glVertex3f(-4-(1.f/3.f),(1.f/8.f),0);
        sommetF();
    glEnd();

    //MUR GAUCHE
    glBegin(GL_LINE_STRIP);
        glColor3f(0.f,0.f,0.f);
        sommetB();
        sommetF();
        sommetG();
        sommetC();
    glEnd();
    glBegin(GL_QUADS);
    //rgb(57,162,219)
        glColor3f((57.f/255.f),(162.f/255.f),(219.f/255.f));
        sommetB();
        sommetF();
        sommetG();
        sommetC();
    glEnd();

    //COTE DU MUR GAUCHE
    glBegin(GL_LINE_STRIP);
        glColor3f(0.f,0.f,0.f);
        sommetF();
        glVertex3f(-4-(1.f/3.f),(1.f/8.f),0);
        glVertex3f(-4-(1.f/3.f),(((1.f/3.f)*4))-4 + (1.f/8.f),0);
        sommetB();
        sommetF();
    glEnd();
    glBegin(GL_QUADS);
    //rgb(30,130,150)
        glColor3f((30.f/255.f),(130.f/255.f),(150.f/255.f));
        sommetF();//glVertex3f(-4,0,layer);
        glVertex3f(-4-(1.f/3.f),(1.f/8.f),0);
        glVertex3f(-4-(1.f/3.f),(((1.f/3.f)*4))-4 + (1.f/8.f),0);
        sommetB();
    glEnd();

    //MUR DROIT
    glBegin(GL_LINE_STRIP);
        glColor3f(0.f,0.f,0.f);
        sommetC();
        sommetG();
        sommetH();
        sommetD();
    glEnd();
    glBegin(GL_QUADS);
    //rgb(57,162,219)
        glColor3f((57.f/255.f),(162.f/255.f),(219.f/255.f));
        sommetC();
        sommetG();
        sommetH();
        sommetD();
    glEnd();
    //COTE DU MUR DROIT
    glBegin(GL_LINE_STRIP);
        glColor3f(0.f,0.f,0.f);
        sommetH();
        glVertex3f(4+(1.f/3.f),(1.f/8.f),0);
        glVertex3f(4+(1.f/3.f),(((1.f/3.f)*4))-4 + (1.f/8.f),0);
        sommetD();
        sommetH();
    glEnd();
    glBegin(GL_QUADS);
    //rgb(30,130,150)
        glColor3f((30.f/255.f),(130.f/255.f),(150.f/255.f));
        sommetH();
        glVertex3f(4+(1.f/3.f),(1.f/8.f),0);
        glVertex3f(4+(1.f/3.f),(((1.f/3.f)*4))-4 + (1.f/8.f),0);
        sommetD();
    glEnd();


    //SOL
    glBegin(GL_QUADS);
        glColor3f((162.f/255.f),(219.f/255.f),(250.f/255.f));
        sommetA();
        sommetB();
        sommetC();
        sommetD();
    glEnd();


    //MURS TRANSPARENTS
    glBegin(GL_QUADS);
    //rgb(57,162,219)
        glColor4f((57.f/255.f),(162.f/255.f),(219.f/255.f),0.1f);
        sommetA(0.001);
        sommetB(0.001);
        sommetF(0.001);
        sommetE(0.001);
    glEnd();

    glBegin(GL_QUADS);
    //rgb(57,162,219)
        glColor4f((57.f/255.f),(162.f/255.f),(219.f/255.f),0.1f);
        sommetA(0.001);
        sommetE(0.001);
        sommetH(0.001);
        sommetD(0.001);
    glEnd();
}

void DungeonView3D::DrawTopDoor(){
    glBegin(GL_QUADS);
        glColor3f(0.f,0.f,0.f);
        sommetI();
        sommetJ();
        sommetK();
        sommetL();
    glEnd();
}

void DungeonView3D::DrawBottomDoor(){
    glBegin(GL_QUADS);
        glColor4f(0.f,0.f,0.f,0.1f);
        sommetQ(0.001);
        sommetR(0.001);
        sommetS(0.001);
        sommetT(0.001);
    glEnd();
}

void DungeonView3D::DrawLeftDoor(){
    glBegin(GL_QUADS);
        glColor4f(0.f,0.f,0.f,0.1f);
        sommetU(0.001);
        sommetV(0.001);
        sommetW(0.001);
        sommetX(0.001);
    glEnd();
}

void DungeonView3D::DrawRightDoor(){
    glBegin(GL_QUADS);
        glColor3f(0.f,0.f,0.f);
        sommetM();
        sommetN();
        sommetO();
        sommetP();
    glEnd();
}
