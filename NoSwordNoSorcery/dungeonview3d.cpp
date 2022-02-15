#include "dungeonview3d.h"
#include "utils.h"

const float wallHeight = 2.f;

DungeonView3D::DungeonView3D()
{

}

void sommetA(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-4,-4,layer));
    glVertex3f(point.x(),point.y(),point.z());
}
void sommetB(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-4,4,layer));
    glVertex3f(point.x(),point.y(),point.z());
    //glVertex3f(-4,(((1.f/3.f)*4))-4,layer);
}
void sommetC(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(4,4,layer));
    glVertex3f(point.x(),point.y(),point.z());
    //glVertex3f(0,(((2.f/3.f)*4))-4,layer);
}
void sommetD(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(4,-4,layer));
    glVertex3f(point.x(),point.y(),point.z());
    //glVertex3f(4,(((1.f/3.f)*4)-4),layer);
}
void sommetE(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-4,-4,layer));
    glVertex3f(point.x(),point.y()+wallHeight,point.z());
    //glVertex3f(0,(((2.f/3.f)*4)-4),layer);
}
void sommetF(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-4,4,layer));
    glVertex3f(point.x(),point.y()+wallHeight,point.z());
    //glVertex3f(-4,0,layer);
}
void sommetG(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(4,4,layer));
    glVertex3f(point.x(),point.y()+wallHeight,point.z());
    //glVertex3f(0,((1.f/3.f)*4),layer);
}
void sommetH(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(4,-4,layer));
    glVertex3f(point.x(),point.y()+wallHeight,point.z());
    //glVertex3f(4,0,layer);
}



void sommetI(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-4,-0.5,layer));
    glVertex3f(point.x(),point.y(),point.z());
    //glVertex3f(-(5.f/8.f)*4,-(1.f/3.f),layer);
}
void sommetJ(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-4,0.5,layer));
    glVertex3f(point.x(),point.y(),point.z());
    //glVertex3f(-(3.f/8.f)*4,0,layer);
}
void sommetK(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-4,0.5,layer));
    glVertex3f(point.x(),point.y()+wallHeight/2,point.z());
    //glVertex3f(-(3.f/8.f)*4,((((2.f/3.f)*4))-4)*(11.f/8.f),layer);
}
void sommetL(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-4,-0.5,layer));
    glVertex3f(point.x(),point.y()+wallHeight/2,point.z());
    //glVertex3f(-(5.f/8.f)*4,((((2.f/3.f)*4)-4)*(13.f/8.f)),layer);
}


void sommetM(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-0.5,4,layer));
    glVertex3f(point.x(),point.y(),point.z());
    //glVertex3f((3.f/8.f)*4,0,layer);
}
void sommetN(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(0.5,4,layer));
    glVertex3f(point.x(),point.y(),point.z());
    //glVertex3f((5.f/8.f)*4,-(1.f/3.f),layer);
}
void sommetO(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(0.5,4,layer));
    glVertex3f(point.x(),point.y()+wallHeight/2,point.z());
    //glVertex3f((5.f/8.f)*4,((((2.f/3.f)*4)-4)*(13.f/8.f)),layer);
}
void sommetP(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-0.5,4,layer));
    glVertex3f(point.x(),point.y()+wallHeight/2,point.z());
    //glVertex3f((3.f/8.f)*4,((((2.f/3.f)*4))-4)*(11.f/8.f),layer);
}



void sommetQ(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(4,0.5,layer));
    glVertex3f(point.x(),point.y(),point.z());
}
void sommetR(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(4,-0.5,layer));
    glVertex3f(point.x(),point.y(),point.z());
}
void sommetS(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(4,-0.5,layer));
    glVertex3f(point.x(),point.y()+wallHeight/2,point.z());
}
void sommetT(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(4,0.5,layer));
    glVertex3f(point.x(),point.y()+wallHeight/2,point.z());
}


void sommetU(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(0.5,-4,layer));
    glVertex3f(point.x(),point.y(),point.z());
}
void sommetV(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-0.5,-4,layer));
    glVertex3f(point.x(),point.y(),point.z());
}
void sommetW(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-0.5,-4,layer));
    glVertex3f(point.x(),point.y()+wallHeight/2,point.z());
}
void sommetX(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(0.5,-4,layer));
    glVertex3f(point.x(),point.y()+wallHeight/2,point.z());
}


void sommetY(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-4.5,4.5,0));
    glVertex3f(point.x(),point.y()+wallHeight,point.z());
}

void DungeonView3D::Render(){

    QVector3D point;
    //LIGNES MURS TRANSPARENTS
    glBegin(GL_LINE_STRIP);
        glColor4f((220.f/255.f),(220.f/255.f),(220.f/255.f),0.1f);
        sommetA(0.001);
        sommetE(0.001);
        sommetH(0.001);
        sommetD(0.001);
        sommetA(0.001);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glColor4f((220.f/255.f),(220.f/255.f),(220.f/255.f),0.1f);
        sommetH(0.001);
        sommetG(0.001);
        sommetC(0.001);
        sommetD(0.001);
        sommetH(0.001);
    glEnd();


    //DESSUS DES MURS
    glBegin(GL_LINE_STRIP);
        glColor3f(0.f,0.f,0.f);
        sommetE();
        sommetF();
        sommetG();
        point = Convert2Dto3DPoint(QVector3D(4,4.5,0));
        glVertex3f(point.x(),point.y()+wallHeight,point.z());
        sommetY();
        point = Convert2Dto3DPoint(QVector3D(-4.5,-4,0));
        glVertex3f(point.x(),point.y()+wallHeight,point.z());
        sommetE();
    glEnd();
    glBegin(GL_QUADS);
        glColor3f((30.f/255.f),(130.f/255.f),(150.f/255.f));
        sommetE();
        sommetF();
        sommetY();
        point = Convert2Dto3DPoint(QVector3D(-4.5,-4,0));
        glVertex3f(point.x(),point.y()+wallHeight,point.z());
    glEnd();
    glBegin(GL_QUADS);
        glColor3f((30.f/255.f),(130.f/255.f),(150.f/255.f));
        sommetF();
        sommetG();
        point = Convert2Dto3DPoint(QVector3D(4,4.5,0));
        glVertex3f(point.x(),point.y()+wallHeight,point.z());
        sommetY();
    glEnd();

    //MUR GAUCHE
    glBegin(GL_LINE_STRIP);
        glColor3f(0.f,0.f,0.f);
        sommetA();
        sommetE();
        sommetF();
        sommetB();
        sommetA();
    glEnd();
    glBegin(GL_QUADS);
    //rgb(57,162,219)
        glColor3f((57.f/255.f),(162.f/255.f),(219.f/255.f));
        sommetA();
        sommetE();
        sommetF();
        sommetB();
    glEnd();

    //COTE DU MUR GAUCHE
    glBegin(GL_LINE_STRIP);
        glColor3f(0.f,0.f,0.f);
        sommetE();
        point = Convert2Dto3DPoint(QVector3D(-4.5,-4,0));
        glVertex3f(point.x(),point.y()+wallHeight,point.z());
        glVertex3f(point.x(),point.y(),point.z());
        sommetA();
        sommetE();
    glEnd();
    glBegin(GL_QUADS);
    //rgb(30,130,150)
        glColor3f((30.f/255.f),(130.f/255.f),(150.f/255.f));
        sommetE();//glVertex3f(-4,0,layer);
        point = Convert2Dto3DPoint(QVector3D(-4.5,-4,0));
        glVertex3f(point.x(),point.y()+wallHeight,point.z());
        glVertex3f(point.x(),point.y(),point.z());
        sommetA();
    glEnd();

    //MUR DROIT
    glBegin(GL_LINE_STRIP);
        glColor3f(0.f,0.f,0.f);
        sommetF();
        sommetG();
        sommetC();
        sommetB();
        sommetF();
    glEnd();
    glBegin(GL_QUADS);
    //rgb(57,162,219)
        glColor3f((57.f/255.f),(162.f/255.f),(219.f/255.f));
        sommetF();
        sommetG();
        sommetC();
        sommetB();
    glEnd();
    //COTE DU MUR DROIT
    glBegin(GL_LINE_STRIP);
        glColor3f(0.f,0.f,0.f);
        sommetC();
        point = Convert2Dto3DPoint(QVector3D(4,4.5,0));
        glVertex3f(point.x(),point.y(),point.z());
        glVertex3f(point.x(),point.y()+wallHeight,point.z());
        sommetG();
        sommetC();
    glEnd();
    glBegin(GL_QUADS);
    //rgb(30,130,150)
        glColor3f((30.f/255.f),(130.f/255.f),(150.f/255.f));
        sommetC();
        point = Convert2Dto3DPoint(QVector3D(4,4.5,0));
        glVertex3f(point.x(),point.y(),point.z());
        glVertex3f(point.x(),point.y()+wallHeight,point.z());
        sommetG();
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
        sommetE(0.001);
        sommetH(0.001);
        sommetD(0.001);
        sommetA(0.001);
    glEnd();

    glBegin(GL_QUADS);
    //rgb(57,162,219)
        glColor4f((57.f/255.f),(162.f/255.f),(219.f/255.f),0.1f);
        sommetH(0.001);
        sommetG(0.001);
        sommetC(0.001);
        sommetD(0.001);
    glEnd();
}

void DungeonView3D::DrawTopDoor(){
    glBegin(GL_QUADS);
        glColor3f(0.f,0.f,0.f);
        sommetM();
        sommetN();
        sommetO();
        sommetP();
    glEnd();
}

void DungeonView3D::DrawBottomDoor(){
    glBegin(GL_QUADS);
        glColor4f(0.f,0.f,0.f,0.1f);
        sommetU(0.001);
        sommetV(0.001);
        sommetW(0.001);
        sommetX(0.001);
    glEnd();
}

void DungeonView3D::DrawLeftDoor(){
    glBegin(GL_QUADS);
        glColor3f(0.f,0.f,0.f);
        sommetI();
        sommetJ();
        sommetK();
        sommetL();
    glEnd();
}

void DungeonView3D::DrawRightDoor(){
    glBegin(GL_QUADS);
        glColor4f(0.f,0.f,0.f,0.1f);
        sommetQ(0.001);
        sommetR(0.001);
        sommetS(0.001);
        sommetT(0.001);
    glEnd();
}

void DungeonView3D::DrawTreasure(){
    QVector3D point;
    glBegin(GL_QUADS);
        glColor3f(1.f,215.f/255.f,0.f);
        point = Convert2Dto3DPoint(QVector3D(-1,1,0));
        glVertex3f(point.x(),point.y(),point.z());
        point = Convert2Dto3DPoint(QVector3D(1,1,0));
        glVertex3f(point.x(),point.y(),point.z());
        point = Convert2Dto3DPoint(QVector3D(1,-1,0));
        glVertex3f(point.x(),point.y(),point.z());
        point = Convert2Dto3DPoint(QVector3D(-1,-1,0));
        glVertex3f(point.x(),point.y(),point.z());
    glEnd();
}

