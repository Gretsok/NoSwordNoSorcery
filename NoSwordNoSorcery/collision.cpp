#include "collision.h"

Collision::Collision(QVector3D a_normal)
{
    this->m_normal = a_normal;
}
QVector3D Collision::GetNormal()
{
    return this->m_normal;
}

