#include "collider2dsquare.h"
#include <QDebug>

Collider2DSquare::Collider2DSquare() : ACollider {}
{
    this->m_cornerLocalPoint = QVector3D(0,0,0);
}

Collider2DSquare::Collider2DSquare(QVector3D a_center, QVector3D a_cornerLocalPoint, bool a_isTrigger) : ACollider {a_center}
{
    this->m_cornerLocalPoint = a_cornerLocalPoint;
    this->m_isTrigger = a_isTrigger;
}

Collider2DSquare::~Collider2DSquare()
{

}

Collision Collider2DSquare::IsCollidingWithMe(QVector3D a_intersectorOrigin, QVector3D a_intersectorVector)
{
    std::list<OrientedLine> borders = this-> get_borders();
    std::list<OrientedLine>::iterator it;
    for(it = borders.begin(); it != borders.end(); ++it)
    {
        if(ACollider::AreIntersected(a_intersectorOrigin, a_intersectorVector, (*it).GetOrigin(), ACollider::GetVectorFromTwoPoints((*it).GetOrigin(), (*it).GetDestination())))
        {
            Collision collision;
            //Tentative : savoir si on est au sein des murs pour avoir des normales correctement orientées
            /*if(this->is_in_square(a_intersectorOrigin))
            {
                collision = Collision(-QVector3D::crossProduct(QVector3D(0,0,1), (*it).GetVector()));
            }
            else
            {
                collision = Collision(QVector3D::crossProduct(QVector3D(0,0,1), (*it).GetVector()));
            }*/
            collision = Collision(QVector3D::crossProduct(QVector3D(0,0,1), (*it).GetVector()));
            collision.HasCollision = true;
            collision.IsCollidingAgainstColliderTrigger = this->IsTrigger();
            return collision;
        }
    }
    return Collision();
}

std::list<OrientedLine> Collider2DSquare::get_intersectors()
{
    return this->get_borders();
}

std::list<OrientedLine> Collider2DSquare::get_borders()
{
    QVector3D corners [4] = {
                this->m_origin + this->m_cornerLocalPoint,
                this->m_origin + QVector3D::crossProduct(-this->m_cornerLocalPoint, QVector3D(0, 0, 1)),
                this->m_origin - this->m_cornerLocalPoint,
                this->m_origin - QVector3D::crossProduct(-this->m_cornerLocalPoint, QVector3D(0, 0, 1))
    };

    //qDebug() << "Origin: " << this->m_origin << " | corner 1 : " << corners[0] << " | corner 2 : " << corners[1] << " | corner 3 : " << corners[2] << " | corner 4 : " << corners[3];

    return {
                OrientedLine(corners[0], corners[1]),
                OrientedLine(corners[1], corners[2]),
                OrientedLine(corners[2], corners[3]),
                OrientedLine(corners[3],corners[0])
    };
}




