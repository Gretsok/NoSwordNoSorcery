#include "collision.h"

Collision::Collision()
{
    this->m_normal = QVector3D(0, 0, 0);
}

Collision::~Collision()
{

}
Collision::Collision(QVector3D a_normal)
{
    this->m_normal = a_normal;
}
QVector3D Collision::GetNormal()
{
    return this->m_normal;
}

