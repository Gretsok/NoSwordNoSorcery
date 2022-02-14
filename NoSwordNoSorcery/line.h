#ifndef LINE_H
#define LINE_H

#include <QVector3D>

class OrientedLine
{
public:
    OrientedLine();
    OrientedLine(QVector3D a_origin, QVector3D a_destination);
    virtual ~OrientedLine();
    QVector3D GetOrigin();
    QVector3D GetDestination();
    QVector3D GetVector();
protected:
    QVector3D m_origin;
    QVector3D m_destination;
};

#endif // LINE_H
