#include "line.h"

OrientedLine::OrientedLine()
{
    this->m_origin = QVector3D(0, 0, 0);
    this->m_destination = QVector3D(0, 0, 0);
}

OrientedLine::OrientedLine(QVector3D a_origin, QVector3D a_destination)
{
    this->m_origin = a_origin;
    this->m_destination = a_destination;
}

QVector3D OrientedLine::GetOrigin()
{
    return this->m_origin;
}

QVector3D OrientedLine::GetDestination()
{
    return this->m_destination;
}
