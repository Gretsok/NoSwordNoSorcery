#include "acollider.h"

bool ACollider::AreIntersected(QVector3D a_intersectorOrigin, QVector3D a_intersectorVector, QVector3D a_intersectedOrigin, QVector3D a_intersectedVector)
{
    QVector3D u = QVector3D::crossProduct(ACollider::GetVectorFromTwoPoints(a_intersectedOrigin, a_intersectedOrigin + a_intersectedVector),
                                          ACollider::GetVectorFromTwoPoints(a_intersectedOrigin, a_intersectorOrigin));
    QVector3D v = QVector3D::crossProduct(ACollider::GetVectorFromTwoPoints(a_intersectedOrigin, a_intersectorOrigin + a_intersectorVector),
                                          ACollider::GetVectorFromTwoPoints(a_intersectedOrigin, a_intersectedOrigin + a_intersectedVector));

    float dotProduct = QVector3D::dotProduct(u, v);

    return (dotProduct / (u.length() * v.length())) > 0;
}
bool ACollider::AreIntersected(QVector3D a_intersectorOrigin, QVector3D a_vectorIntersecter, QVector3D a_circleCenter, float a_circleRadius)
{
    float dotProduct = QVector3D::dotProduct(ACollider::GetVectorFromTwoPoints(a_intersectorOrigin, a_circleCenter), a_vectorIntersecter);
    QVector3D projectedVector = dotProduct * a_vectorIntersecter / (a_vectorIntersecter.lengthSquared());
    QVector3D ProjectedPointToCenter = ACollider::GetVectorFromTwoPoints(a_intersectorOrigin, a_circleCenter) - projectedVector;
    if(ProjectedPointToCenter.length() < a_circleRadius)
    {
        return true;
    }
    else
    {
        return false;
    }
}

QVector3D ACollider::GetVectorFromTwoPoints(QVector3D a_origin, QVector3D a_destionation)
{
    return QVector3D(a_destionation.x() - a_origin.x(),
                     a_destionation.y() - a_origin.y(),
                     a_destionation.z() - a_origin.z());
}

std::list<ACollider*> ACollider::RegisteredColliders = std::list<ACollider*>();

ACollider::ACollider()
{
    ACollider::RegisteredColliders.push_front(this);
    this->m_origin = QVector3D(0, 0, 0);

}

ACollider::~ACollider()
{
    ACollider::RegisteredColliders.remove(this);
}

void ACollider::OnMove(QVector3D a_newOrigin)
{
    this->m_origin += a_newOrigin;
    this->ACollider::check_collisions();
}

bool ACollider::IsCollidingWithMe(QVector3D a_intersectorOrigin, QVector3D a_intersectorVector)
{
    return false;
}
void ACollider::check_collisions()
{
    for(int i = 0; i < (int) ACollider::RegisteredColliders.size() ; ++i)
    {
        // Iterate list to call IsCollidingWithMe OnEach
    }
}

