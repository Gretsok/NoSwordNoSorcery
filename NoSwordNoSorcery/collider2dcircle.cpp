#include "collider2dcircle.h"

Collider2DCircle::Collider2DCircle()
{
    this->m_radius = 1.f;
}

Collider2DCircle::Collider2DCircle(QVector3D a_center, float a_radius, bool a_isTrigger) : ACollider {a_center}
{
    this->m_radius = a_radius;
    this->m_isTrigger = a_isTrigger;
}

Collider2DCircle::~Collider2DCircle()
{

}

Collision Collider2DCircle::IsCollidingWithMe(QVector3D a_intersectorOrigin, QVector3D a_intersectorVector)
{
    std::list<OrientedLine> borders = this-> get_intersectors();
    std::list<OrientedLine>::iterator it;
    for(it = borders.begin(); it != borders.end(); ++it)
    {
        if(ACollider::AreIntersected(a_intersectorOrigin, a_intersectorVector, (*it).GetOrigin(), ACollider::GetVectorFromTwoPoints((*it).GetOrigin(), (*it).GetDestination())))
        {
            Collision collision;
            collision = Collision(QVector3D::crossProduct(QVector3D(0,0,1), (*it).GetVector()));
            collision.HasCollision = true;
            collision.IsCollidingAgainstColliderTrigger = this->IsTrigger();
            return collision;
        }
    }
    return Collision();
    /*
    if(ACollider::AreIntersected(a_intersectorOrigin, a_intersectorVector, this->m_origin, this->m_radius))
    {
        Collision collision = Collision(ACollider::GetVectorFromTwoPoints(this->m_origin, a_intersectorOrigin + a_intersectorVector));
        collision.HasCollision = true;
        collision.IsTrigger = this->IsTrigger();
        return collision;
    }
    else
    {
        return Collision();
    }*/
}

std::list<OrientedLine> Collider2DCircle::get_intersectors()
{
    return {
            OrientedLine(this->m_origin, this->m_origin + QVector3D(1, 0, 0) * this->m_radius),
            OrientedLine(this->m_origin, this->m_origin + QVector3D(-1, 0, 0) * this->m_radius),
            OrientedLine(this->m_origin, this->m_origin + QVector3D(0, 1, 0) * this->m_radius),
            OrientedLine(this->m_origin, this->m_origin + QVector3D(0, -1, 0) * this->m_radius),
            OrientedLine(this->m_origin, this->m_origin + QVector3D(0.7, 0.7, 0) * this->m_radius),
            OrientedLine(this->m_origin, this->m_origin + QVector3D(0.7, -0.7, 0) * this->m_radius),
            OrientedLine(this->m_origin, this->m_origin + QVector3D(-0.7, 0.7, 0) * this->m_radius),
            OrientedLine(this->m_origin, this->m_origin + QVector3D(-0.7, -0.7, 0) * this->m_radius)
    };
}
