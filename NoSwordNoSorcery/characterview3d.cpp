#include "characterview3d.h"
#include <QDebug>
#include "utils.h"

bool loadOBJ(const char * path,
             std::vector < QVector3D > & out_vertices,
             std::vector < QVector2D > & out_uvs,
             std::vector < QVector3D > & out_normals)
{
    std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
    std::vector<QVector3D> temp_vertices;
    std::vector<QVector2D > temp_uvs;
    std::vector<QVector3D> temp_normals;
    FILE * file = fopen("../Drill_01.obj", "r");
    if( file == NULL ){
        printf("Impossible to open the file !\n");
        return false;
    }
    while( 1 ){

        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break; // EOF = End Of File. Quit the loop.

        // else : parse lineHeader
        if ( strcmp( lineHeader, "v" ) == 0 ){
            QVector3D vertex;
            float x,y,z;
            fscanf(file, "%f %f %f\n", &x, &y, &z );
            vertex.setX(x);
            vertex.setY(y);
            vertex.setZ(z);
            temp_vertices.push_back(vertex);
        }else if ( strcmp( lineHeader, "vt" ) == 0 ){
            QVector2D uv;
            float x,y;
            fscanf(file, "%f %f\n", &x, &y );
            uv.setX(x);
            uv.setY(y);
            temp_uvs.push_back(uv);
        }else if ( strcmp( lineHeader, "vn" ) == 0 ){
            QVector3D normal;
            float x,y,z;
            fscanf(file, "%f %f %f\n", &x, &y, &z );
            normal.setX(x);
            normal.setY(y);
            normal.setZ(z);
            temp_normals.push_back(normal);
        }else if ( strcmp( lineHeader, "f" ) == 0 ){
            std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[4], uvIndex[4], normalIndex[4];
            int matches = fscanf(file, "%d//%d %d//%d %d//%d %d//%d\n", &vertexIndex[0], &normalIndex[0], &vertexIndex[1], &normalIndex[1], &vertexIndex[2], &normalIndex[2],&vertexIndex[3], &normalIndex[3] );
            if (matches != 8 && matches!=6){
                printf("File can't be read by our simple parser : ( Try exporting with other options\n");
                return false;
            }
            vertexIndices.push_back(vertexIndex[0]);
            vertexIndices.push_back(vertexIndex[1]);
            vertexIndices.push_back(vertexIndex[2]);
            uvIndices    .push_back(uvIndex[0]);
            uvIndices    .push_back(uvIndex[1]);
            uvIndices    .push_back(uvIndex[2]);
            normalIndices.push_back(normalIndex[0]);
            normalIndices.push_back(normalIndex[1]);
            normalIndices.push_back(normalIndex[2]);
        }
    }
    // For each vertex of each triangle
    for( unsigned int i=0; i<vertexIndices.size(); i++ ){
        unsigned int vertexIndex = vertexIndices[i];

        QVector3D vertex = temp_vertices[ vertexIndex-1 ];
        out_vertices.push_back(vertex);
    }
    fclose(file);
    return true;
}


CharacterView3D::CharacterView3D()
{
    //std::vector<QVector3D> vertices;
    //std::vector<QVector2D> uvs;
    //std::vector<QVector3D> normals; // Won't be used at the moment.
    //bool res = loadOBJ("cube.obj", vertices, uvs, normals);
    //glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(QVector3D), &vertices[0], GL_STATIC_DRAW);
    //glFlush();
}

CharacterView3D::~CharacterView3D()
{
}


void CharacterView3D::Render(void){
    glBegin(GL_QUADS);
        glColor3f(1.f, 0.f,0.f);
        //glVertex3f(this->m_gamePositions.x(), this->m_gamePositions.y() +(1.f/3.f)*0.5,0);
        //glVertex3f(this->m_gamePositions.x()+0.25, this->m_gamePositions.y(),0);
        //glVertex3f(this->m_gamePositions.x(), this->m_gamePositions.y() - 0.25,0);
        //glVertex3f(this->m_gamePositions.x() -0.25, this->m_gamePositions.y(),0);
        /*glVertex3f(this->m_gamePositions.x()-0.25f, this->m_gamePositions.y()-0.25f - (this->m_gamePositions.x()-0.25f)/3.f -2,0);
        glVertex3f(this->m_gamePositions.x()-0.25f, this->m_gamePositions.y()+0.25f - (this->m_gamePositions.x()-0.25f)/3.f -2,0);
        glVertex3f(this->m_gamePositions.x()+0.25f, this->m_gamePositions.y()+0.25f - (this->m_gamePositions.x()+0.25f)/3.f -2,0);
        glVertex3f(this->m_gamePositions.x()+0.25f, this->m_gamePositions.y()-0.25f - (this->m_gamePositions.x()+0.25f)/3.f -2,0);*/
        QVector3D point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()-0.25f,m_gamePositions.y()-0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y(),point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()-0.25f,m_gamePositions.y()+0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y(),point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()+0.25f,m_gamePositions.y()+0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y(),point3D.z());
        point3D = Convert2Dto3DPoint(QVector3D(m_gamePositions.x()+0.25f,m_gamePositions.y()-0.25f,m_gamePositions.z()));
        glVertex3f(point3D.x(),point3D.y(),point3D.z());
    glEnd();
}
