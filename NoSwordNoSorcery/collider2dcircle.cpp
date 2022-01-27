#include "collider2dcircle.h"

Collider2DCircle::Collider2DCircle()
{
this->m_radius = 1.f;
}

Collider2DCircle::Collider2DCircle(QVector3D a_center, float a_radius) : ACollider {a_center}
{
    this->m_radius = a_radius;
}

bool Collider2DCircle::IsCollidingWithMe(QVector3D a_intersectorOrigin, QVector3D a_intersectorVector)
{
    return ACollider::AreIntersected(a_intersectorOrigin, a_intersectorVector, this->m_origin, this->m_radius);
}

std::list<QVector3D> Collider2DCircle::get_intersectors()
{
    return {
                this->m_origin + QVector3D(1, 0, 0) * this->m_radius,
                this->m_origin + QVector3D(-1, 0, 0) * this->m_radius,
                this->m_origin + QVector3D(0, 1, 0) * this->m_radius,
                this->m_origin + QVector3D(0, -1, 0) * this->m_radius,
                this->m_origin + QVector3D(0.7, 0.7, 0) * this->m_radius,
                this->m_origin + QVector3D(0.7, -0.7, 0) * this->m_radius,
                this->m_origin + QVector3D(-0.7, 0.7, 0) * this->m_radius,
                this->m_origin + QVector3D(-0.7, -0.7, 0) * this->m_radius
    };
}
