#include "dungeonview3d.h"
#include "utils.h"

const float wallHeight = 2.f;

DungeonView3D::DungeonView3D()
{

}

DungeonView3D::~DungeonView3D()
{

}

void sommetA(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-4,-4,layer));
    glVertex3f(point.x(),point.y(),point.z());
}
void sommetB(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-4,4,layer));
    glVertex3f(point.x(),point.y(),point.z());
}
void sommetC(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(4,4,layer));
    glVertex3f(point.x(),point.y(),point.z());
}
void sommetD(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(4,-4,layer));
    glVertex3f(point.x(),point.y(),point.z());
}
void sommetE(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-4,-4,layer));
    glVertex3f(point.x(),point.y()+wallHeight,point.z());
}
void sommetF(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-4,4,layer));
    glVertex3f(point.x(),point.y()+wallHeight,point.z());
    //glVertex3f(-4,0,layer);
}
void sommetG(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(4,4,layer));
    glVertex3f(point.x(),point.y()+wallHeight,point.z());
}
void sommetH(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(4,-4,layer));
    glVertex3f(point.x(),point.y()+wallHeight,point.z());
}



void sommetI(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-4,-0.5,layer));
    glVertex3f(point.x(),point.y(),point.z());
}
void sommetJ(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-4,0.5,layer));
    glVertex3f(point.x(),point.y(),point.z());
}
void sommetK(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-4,0.5,layer));
    glVertex3f(point.x(),point.y()+wallHeight/2,point.z());
}
void sommetL(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-4,-0.5,layer));
    glVertex3f(point.x(),point.y()+wallHeight/2,point.z());
}


void sommetM(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-0.5,4,layer));
    glVertex3f(point.x(),point.y(),point.z());
}
void sommetN(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(0.5,4,layer));
    glVertex3f(point.x(),point.y(),point.z());
}
void sommetO(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(0.5,4,layer));
    glVertex3f(point.x(),point.y()+wallHeight/2,point.z());
}
void sommetP(float layer=0){
    QVector3D point = Convert2Dto3DPoint(QVector3D(-0.5,4,layer));
    glVertex3f(point.x(),point.y()+wallHeight/2,point.z());
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

    glBegin(GL_LINE_STRIP);
        glColor3f(0,0,0);
        point = Convert2Dto3DPoint(QVector3D(-1,-1,0));
        glVertex3f(point.x(),point.y(),point.z());
        point = Convert2Dto3DPoint(QVector3D(1,-1,0));
        glVertex3f(point.x(),point.y(),point.z());
        point = Convert2Dto3DPoint(QVector3D(1,-1,0));
        glVertex3f(point.x(),point.y()+0.25,point.z());
        point = Convert2Dto3DPoint(QVector3D(-1,-1,0));
        glVertex3f(point.x(),point.y()+0.25,point.z());
        point = Convert2Dto3DPoint(QVector3D(-1,-1,0));
        glVertex3f(point.x(),point.y(),point.z());
    glEnd();

    glBegin(GL_LINE_STRIP);
        glColor3f(0,0,0);
        point = Convert2Dto3DPoint(QVector3D(1,1,0));
        glVertex3f(point.x(),point.y(),point.z());
        point = Convert2Dto3DPoint(QVector3D(1,-1,0));
        glVertex3f(point.x(),point.y(),point.z());
        point = Convert2Dto3DPoint(QVector3D(1,-1,0));
        glVertex3f(point.x(),point.y()+0.25,point.z());
        point = Convert2Dto3DPoint(QVector3D(1,1,0));
        glVertex3f(point.x(),point.y()+0.25,point.z());
        point = Convert2Dto3DPoint(QVector3D(1,1,0));
        glVertex3f(point.x(),point.y(),point.z());
    glEnd();

    glBegin(GL_LINE_STRIP);
        glColor3f(0,0,0);
        point = Convert2Dto3DPoint(QVector3D(-0.5,-0.5,0));
        glVertex3f(point.x(),point.y()+0.7,point.z());
        point = Convert2Dto3DPoint(QVector3D(0.5,-0.5,0));
        glVertex3f(point.x(),point.y()+0.7,point.z());
        point = Convert2Dto3DPoint(QVector3D(0.5,-0.5,0));
        glVertex3f(point.x(),point.y()+0.5,point.z());
        point = Convert2Dto3DPoint(QVector3D(-0.5,-0.5,0));
        glVertex3f(point.x(),point.y()+0.5,point.z());
        point = Convert2Dto3DPoint(QVector3D(-0.5,-0.5,0));
        glVertex3f(point.x(),point.y()+0.7,point.z());
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(0,0,0);
        point = Convert2Dto3DPoint(QVector3D(0.5,-0.5,0));
        glVertex3f(point.x(),point.y()+0.7,point.z());
        point = Convert2Dto3DPoint(QVector3D(0.5,0.5,0));
        glVertex3f(point.x(),point.y()+0.7,point.z());
        point = Convert2Dto3DPoint(QVector3D(0.5,0.5,0));
        glVertex3f(point.x(),point.y()+0.5,point.z());
        point = Convert2Dto3DPoint(QVector3D(0.5,-0.5,0));
        glVertex3f(point.x(),point.y()+0.5,point.z());
        point = Convert2Dto3DPoint(QVector3D(0.5,-0.5,0));
        glVertex3f(point.x(),point.y()+0.7,point.z());
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(0,0,0);
        point = Convert2Dto3DPoint(QVector3D(-0.5,0.5,0));
        glVertex3f(point.x(),point.y()+0.7,point.z());
        point = Convert2Dto3DPoint(QVector3D(0.5,0.5,0));
        glVertex3f(point.x(),point.y()+0.7,point.z());
        point = Convert2Dto3DPoint(QVector3D(0.5,-0.5,0));
        glVertex3f(point.x(),point.y()+0.7,point.z());
        point = Convert2Dto3DPoint(QVector3D(-0.5,-0.5,0));
        glVertex3f(point.x(),point.y()+0.7,point.z());
        point = Convert2Dto3DPoint(QVector3D(-0.5,0.5,0));
        glVertex3f(point.x(),point.y()+0.7,point.z());
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.f,215.f/255.f,0.f);
        point = Convert2Dto3DPoint(QVector3D(-0.5,0.5,0));
        glVertex3f(point.x(),point.y()+0.7,point.z());
        point = Convert2Dto3DPoint(QVector3D(0.5,0.5,0));
        glVertex3f(point.x(),point.y()+0.7,point.z());
        point = Convert2Dto3DPoint(QVector3D(0.5,-0.5,0));
        glVertex3f(point.x(),point.y()+0.7,point.z());
        point = Convert2Dto3DPoint(QVector3D(-0.5,-0.5,0));
        glVertex3f(point.x(),point.y()+0.7,point.z());
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(0,0,0);
        point = Convert2Dto3DPoint(QVector3D(-0.75,-0.75,0));
        glVertex3f(point.x(),point.y()+0.5,point.z());
        point = Convert2Dto3DPoint(QVector3D(0.75,-0.75,0));
        glVertex3f(point.x(),point.y()+0.5,point.z());
        point = Convert2Dto3DPoint(QVector3D(0.75,-0.75,0));
        glVertex3f(point.x(),point.y()+0.25,point.z());
        point = Convert2Dto3DPoint(QVector3D(-0.75,-0.75,0));
        glVertex3f(point.x(),point.y()+0.25,point.z());
        point = Convert2Dto3DPoint(QVector3D(-0.75,-0.75,0));
        glVertex3f(point.x(),point.y()+0.5,point.z());
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(0,0,0);
        point = Convert2Dto3DPoint(QVector3D(0.75,-0.75,0));
        glVertex3f(point.x(),point.y()+0.5,point.z());
        point = Convert2Dto3DPoint(QVector3D(0.75,0.75,0));
        glVertex3f(point.x(),point.y()+0.5,point.z());
        point = Convert2Dto3DPoint(QVector3D(0.75,0.75,0));
        glVertex3f(point.x(),point.y()+0.25,point.z());
        point = Convert2Dto3DPoint(QVector3D(0.75,-0.75,0));
        glVertex3f(point.x(),point.y()+0.25,point.z());
        point = Convert2Dto3DPoint(QVector3D(0.75,-0.75,0));
        glVertex3f(point.x(),point.y()+0.5,point.z());
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(0,0,0);
        point = Convert2Dto3DPoint(QVector3D(-0.75,0.75,0));
        glVertex3f(point.x(),point.y()+0.5,point.z());
        point = Convert2Dto3DPoint(QVector3D(0.75,0.75,0));
        glVertex3f(point.x(),point.y()+0.5,point.z());
        point = Convert2Dto3DPoint(QVector3D(0.75,-0.75,0));
        glVertex3f(point.x(),point.y()+0.5,point.z());
        point = Convert2Dto3DPoint(QVector3D(-0.75,-0.75,0));
        glVertex3f(point.x(),point.y()+0.5,point.z());
        point = Convert2Dto3DPoint(QVector3D(-0.75,0.75,0));
        glVertex3f(point.x(),point.y()+0.5,point.z());
    glEnd();





    glBegin(GL_QUADS);
        glColor3f(1.f,215.f/255.f,0.f);
        point = Convert2Dto3DPoint(QVector3D(-0.75,0.75,0));
        glVertex3f(point.x(),point.y()+0.5,point.z());
        point = Convert2Dto3DPoint(QVector3D(0.75,0.75,0));
        glVertex3f(point.x(),point.y()+0.5,point.z());
        point = Convert2Dto3DPoint(QVector3D(0.75,-0.75,0));
        glVertex3f(point.x(),point.y()+0.5,point.z());
        point = Convert2Dto3DPoint(QVector3D(-0.75,-0.75,0));
        glVertex3f(point.x(),point.y()+0.5,point.z());
    glEnd();

    glBegin(GL_LINE_STRIP);
        glColor3f(0,0,0);
        point = Convert2Dto3DPoint(QVector3D(-1,1,0));
        glVertex3f(point.x(),point.y()+0.25,point.z());
        point = Convert2Dto3DPoint(QVector3D(1,1,0));
        glVertex3f(point.x(),point.y()+0.25,point.z());
        point = Convert2Dto3DPoint(QVector3D(1,-1,0));
        glVertex3f(point.x(),point.y()+0.25,point.z());
        point = Convert2Dto3DPoint(QVector3D(-1,-1,0));
        glVertex3f(point.x(),point.y()+0.25,point.z());
        point = Convert2Dto3DPoint(QVector3D(-1,1,0));
        glVertex3f(point.x(),point.y()+0.25,point.z());
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.f,215.f/255.f,0.f);
        point = Convert2Dto3DPoint(QVector3D(-1,-1,0));
        glVertex3f(point.x(),point.y(),point.z());
        point = Convert2Dto3DPoint(QVector3D(1,-1,0));
        glVertex3f(point.x(),point.y(),point.z());
        point = Convert2Dto3DPoint(QVector3D(1,-1,0));
        glVertex3f(point.x(),point.y()+0.25,point.z());
        point = Convert2Dto3DPoint(QVector3D(-1,-1,0));
        glVertex3f(point.x(),point.y()+0.25,point.z());
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(1.f,215.f/255.f,0.f);
        point = Convert2Dto3DPoint(QVector3D(1,-1,0));
        glVertex3f(point.x(),point.y(),point.z());
        point = Convert2Dto3DPoint(QVector3D(1,1,0));
        glVertex3f(point.x(),point.y(),point.z());
        point = Convert2Dto3DPoint(QVector3D(1,1,0));
        glVertex3f(point.x(),point.y()+0.25,point.z());
        point = Convert2Dto3DPoint(QVector3D(1,-1,0));
        glVertex3f(point.x(),point.y()+0.25,point.z());
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(1.f,215.f/255.f,0.f);
        point = Convert2Dto3DPoint(QVector3D(-1,1,0));
        glVertex3f(point.x(),point.y()+0.25,point.z());
        point = Convert2Dto3DPoint(QVector3D(1,1,0));
        glVertex3f(point.x(),point.y()+0.25,point.z());
        point = Convert2Dto3DPoint(QVector3D(1,-1,0));
        glVertex3f(point.x(),point.y()+0.25,point.z());
        point = Convert2Dto3DPoint(QVector3D(-1,-1,0));
        glVertex3f(point.x(),point.y()+0.25,point.z());
    glEnd();


}

void DungeonView3D::DrawObstacles(std::vector<ObstacleModel> obstacles){
    QVector3D point3D;
    float x;
    float y;
    for(unsigned long long i = 0;i<obstacles.size();i++){
        x = obstacles[i].xPosition;
        y = obstacles[i].yPosition;
        glBegin(GL_LINE_STRIP);
            glColor3f(0.f, 0.f,0.f);
            point3D = Convert2Dto3DPoint(QVector3D(x+0.25f,y+0.25f,0));
            glVertex3f(point3D.x(),point3D.y(),point3D.z());
            point3D = Convert2Dto3DPoint(QVector3D(x+0.25f,y-0.25f,0));
            glVertex3f(point3D.x(),point3D.y(),point3D.z());
            point3D = Convert2Dto3DPoint(QVector3D(x+0.25f,y-0.25f,0));
            glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
            point3D = Convert2Dto3DPoint(QVector3D(x+0.25f,y+0.25f,0));
            glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
            point3D = Convert2Dto3DPoint(QVector3D(x+0.25f,y+0.25f,0));
            glVertex3f(point3D.x(),point3D.y(),point3D.z());
        glEnd();
        glBegin(GL_LINE_STRIP);
            glColor3f(0.f, 0.f,0.f);
            point3D = Convert2Dto3DPoint(QVector3D(x+0.25f,y-0.25f,0));
            glVertex3f(point3D.x(),point3D.y(),point3D.z());
            point3D = Convert2Dto3DPoint(QVector3D(x-0.25f,y-0.25f,0));
            glVertex3f(point3D.x(),point3D.y(),point3D.z());
            point3D = Convert2Dto3DPoint(QVector3D(x-0.25f,y-0.25f,0));
            glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
            point3D = Convert2Dto3DPoint(QVector3D(x+0.25f,y-0.25f,0));
            glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
            point3D = Convert2Dto3DPoint(QVector3D(x+0.25f,y-0.25f,0));
            glVertex3f(point3D.x(),point3D.y(),point3D.z());
        glEnd();
        glBegin(GL_LINE_STRIP);
            glColor3f(0.f, 0.f,0.f);
            point3D = Convert2Dto3DPoint(QVector3D(x-0.25f,y-0.25f,0));
            glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
            point3D = Convert2Dto3DPoint(QVector3D(x-0.25f,y+0.25f,0));
            glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
            point3D = Convert2Dto3DPoint(QVector3D(x+0.25f,y+0.25f,0));
            glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
            point3D = Convert2Dto3DPoint(QVector3D(x+0.25f,y-0.25f,0));
            glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
        glEnd();
        glBegin(GL_QUADS);
            glColor3f(0.f, 1.f,0.f);
            point3D = Convert2Dto3DPoint(QVector3D(x-0.25f,y-0.25f,0));
            glVertex3f(point3D.x(),point3D.y(),point3D.z());
            point3D = Convert2Dto3DPoint(QVector3D(x-0.25f,y+0.25f,0));
            glVertex3f(point3D.x(),point3D.y(),point3D.z());
            point3D = Convert2Dto3DPoint(QVector3D(x+0.25f,y+0.25f,0));
            glVertex3f(point3D.x(),point3D.y(),point3D.z());
            point3D = Convert2Dto3DPoint(QVector3D(x+0.25f,y-0.25f,0));
            glVertex3f(point3D.x(),point3D.y(),point3D.z());
        glEnd();
        glBegin(GL_QUADS);
            glColor3f(0.f, 1.f,0.f);
            point3D = Convert2Dto3DPoint(QVector3D(x-0.25f,y-0.25f,0));
            glVertex3f(point3D.x(),point3D.y(),point3D.z());
            point3D = Convert2Dto3DPoint(QVector3D(x-0.25f,y+0.25f,0));
            glVertex3f(point3D.x(),point3D.y(),point3D.z());
            point3D = Convert2Dto3DPoint(QVector3D(x-0.25f,y+0.25f,0));
            glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
            point3D = Convert2Dto3DPoint(QVector3D(x-0.25f,y-0.25f,0));
            glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
        glEnd();
        glBegin(GL_QUADS);
            glColor3f(0.f, 1.f,0.f);
            point3D = Convert2Dto3DPoint(QVector3D(x-0.25f,y+0.25f,0));
            glVertex3f(point3D.x(),point3D.y(),point3D.z());
            point3D = Convert2Dto3DPoint(QVector3D(x+0.25f,y+0.25f,0));
            glVertex3f(point3D.x(),point3D.y(),point3D.z());
            point3D = Convert2Dto3DPoint(QVector3D(x+0.25f,y+0.25f,0));
            glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
            point3D = Convert2Dto3DPoint(QVector3D(x-0.25f,y+0.25f,0));
            glVertex3f(point3D.x(),point3D.y()+0.4,point3D.z());
        glEnd();
    }
}
