#include "utils.h"

utils::utils()
{

}

QVector3D Convert2Dto3DPoint(QVector3D point2D)
{
    QVector3D point;
    float height=1.f;
    float width=2.f;
    point.setX(((point2D.x()*width/2) + (point2D.y()*width/2))/1.5);
    point.setY((((point2D.y()*height/2) - (point2D.x()*height/2))/1.5)-1);
    point.setZ(point2D.z());
    return point;
}
