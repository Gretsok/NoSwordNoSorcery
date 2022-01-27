#include "collider2dsquare.h"

Collider2DSquare::Collider2DSquare() : ACollider {}
{
    this->m_cornerLocalPoint = QVector3D(0,0,0);
}

Collider2DSquare::Collider2DSquare(QVector3D a_center, QVector3D a_cornerLocalPoint) : ACollider {a_center}
{
    this->m_cornerLocalPoint = a_cornerLocalPoint;
}

bool Collider2DSquare::IsCollidingWithMe(QVector3D a_intersectorOrigin, QVector3D a_intersectorVector)
{
    std::list<QVector3D> borders = this-> get_borders();
    bool isColliding = false;
    std::list<QVector3D>::iterator it;
    for(it = borders.begin(); it != borders.end(); ++it)
    {
        if(ACollider::AreIntersected(a_intersectorOrigin, a_intersectorVector, this->m_origin, (*it)))
        {
            isColliding = true;
            break;
        }
    }
    return isColliding;
}

std::list<QVector3D> Collider2DSquare::get_intersectors()
{
    return this->get_borders();
}

std::list<QVector3D> Collider2DSquare::get_borders()
{
    return { this->m_origin + this->m_cornerLocalPoint,
                this->m_origin + this->m_cornerLocalPoint + ACollider::GetVectorFromTwoPoints(this->m_cornerLocalPoint, this->m_origin) * 2,
                this->m_origin + this->m_cornerLocalPoint + QVector3D::crossProduct(ACollider::GetVectorFromTwoPoints(this->m_cornerLocalPoint, this->m_origin), QVector3D(0, 0, 1)),
                this->m_origin + this->m_cornerLocalPoint - QVector3D::crossProduct(ACollider::GetVectorFromTwoPoints(this->m_cornerLocalPoint, this->m_origin), QVector3D(0, 0, 1))};
}
