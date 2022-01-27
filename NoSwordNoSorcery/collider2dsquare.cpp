#include "collider2dsquare.h"

Collider2DSquare::Collider2DSquare() : ACollider {}
{
    this->m_cornerLocalPoint = QVector3D(0,0,0);
}

Collider2DSquare::Collider2DSquare(QVector3D a_center, QVector3D a_cornerLocalPoint) : ACollider {a_center}
{
    this->m_cornerLocalPoint = a_cornerLocalPoint;
}

Collision* Collider2DSquare::IsCollidingWithMe(QVector3D a_intersectorOrigin, QVector3D a_intersectorVector)
{
    std::list<QVector3D> borders = this-> get_borders();
    std::list<QVector3D>::iterator it;
    for(it = borders.begin(); it != borders.end(); ++it)
    {
        if(ACollider::AreIntersected(a_intersectorOrigin, a_intersectorVector, this->m_origin, (*it)))
        {
            Collision collision = Collision(QVector3D::crossProduct(QVector3D(0,0,1), a_intersectorVector));
            return &collision;
        }
    }
    return NULL;
}

std::list<QVector3D> Collider2DSquare::get_intersectors()
{
    return this->get_borders();
}

std::list<QVector3D> Collider2DSquare::get_borders()
{
    QVector3D corners [4] = { this->m_origin + this->m_cornerLocalPoint,
                this->m_origin + this->m_cornerLocalPoint + QVector3D::crossProduct(ACollider::GetVectorFromTwoPoints(this->m_cornerLocalPoint, this->m_origin), QVector3D(0, 0, 1)),
                this->m_origin + this->m_cornerLocalPoint + ACollider::GetVectorFromTwoPoints(this->m_cornerLocalPoint, this->m_origin) * 2,
                this->m_origin + this->m_cornerLocalPoint - QVector3D::crossProduct(ACollider::GetVectorFromTwoPoints(this->m_cornerLocalPoint, this->m_origin), QVector3D(0, 0, 1))};
    return {ACollider::GetVectorFromTwoPoints(corners[0], corners[1]),
                ACollider::GetVectorFromTwoPoints(corners[1], corners[2]),
                ACollider::GetVectorFromTwoPoints(corners[2], corners[3]),
                ACollider::GetVectorFromTwoPoints(corners[3], corners[0]),
    };
}
