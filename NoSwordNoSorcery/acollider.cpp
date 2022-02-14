#include "acollider.h"
#include "collidercontroller.h"
#include "QDebug"

bool ACollider::AreIntersected(QVector3D a_intersectorOrigin, QVector3D a_intersectorVector, QVector3D a_intersectedOrigin, QVector3D a_intersectedVector)
{
    /*QVector3D u = QVector3D::crossProduct(ACollider::GetVectorFromTwoPoints(a_intersectedOrigin, a_intersectedOrigin + a_intersectedVector),
                                          ACollider::GetVectorFromTwoPoints(a_intersectedOrigin, a_intersectorOrigin));
    QVector3D v = QVector3D::crossProduct(ACollider::GetVectorFromTwoPoints(a_intersectedOrigin, a_intersectorOrigin + a_intersectorVector),
                                          ACollider::GetVectorFromTwoPoints(a_intersectedOrigin, a_intersectedOrigin + a_intersectedVector));
*/
  //  float dotProduct = QVector3D::dotProduct(u, v);

    //return (dotProduct / (u.length() * v.length())) > 0.f;

    QVector3D CmP = ACollider::GetVectorFromTwoPoints(a_intersectedOrigin,a_intersectorOrigin);
    QVector3D r = ACollider::GetVectorFromTwoPoints(a_intersectedOrigin,a_intersectedOrigin+a_intersectedVector);
    QVector3D s = ACollider::GetVectorFromTwoPoints(a_intersectorOrigin,a_intersectorOrigin+a_intersectorVector);

    float CmPxr = CmP.x() * r.y() - CmP.y() * r.x();
    float CmPxs = CmP.x()*s.y() - CmP.y() * s.x();
    float rxs = r.x()*s.y() - r.y()*s.x();

    if(CmPxr==0.f){
        //Lines are collinear, and so intersect if they have any overlap
        return ((a_intersectorOrigin.x() - a_intersectedOrigin.x() < 0.f) != (a_intersectorOrigin.x()-(a_intersectedOrigin+a_intersectedVector).x() < 0.f))
                || ((a_intersectorOrigin.y() - a_intersectedOrigin.y() < 0.f) != (a_intersectorOrigin.y()-(a_intersectedOrigin+a_intersectedVector).y() < 0.f));
    }

    if(rxs==0.f){
        return false;
    }
    float rxsr = 1.f/rxs;
    float t = CmPxs * rxsr;
    float u = CmPxr * rxsr;
    return (t>=0.f) && (t <= 1.f) && (u>=0.f) && (u<=1.f);


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


ACollider::ACollider()
{
    this->m_origin = QVector3D(0, 0, 0);
}

ACollider::ACollider(QVector3D a_center)
{
    this->m_origin = a_center;
}

ACollider::~ACollider()
{
}

void ACollider::OnMove(QVector3D a_deltaToNewOrigin)
{
    this->m_origin += a_deltaToNewOrigin;
    this->ACollider::check_collisions();
}

Collision ACollider::IsCollidingWithMe(QVector3D a_intersectorOrigin, QVector3D a_intersectorVector)
{
   return Collision();
}

QVector3D ACollider::GetOrigin()
{
    return this->m_origin;
}

void ACollider::SetOrigin(QVector3D vector)
{
    this->m_origin.setX(vector.x());
    this->m_origin.setY(vector.y());
    this->m_origin.setZ(vector.z());
}

void ACollider::AddCollisionObserver(ACollisionObserver* a_collisionObserver)
{
    this->m_collisionObservers.push_back(a_collisionObserver);
   //qDebug()<< "just added a new collision observer" << ACollider::m_collisionObservers.size();
}

void ACollider::RemoveCollisionObserver(ACollisionObserver* a_collisionObserver)
{
    this->m_collisionObservers.remove(a_collisionObserver);
   //qDebug()<< "just removed a new collision observer" << this->m_collisionObservers.size();
}

std::list<OrientedLine> ACollider::Debug_GetLines()
{
    return this->get_intersectors();
}

void ACollider::check_collisions()
{
    std::list<OrientedLine>::iterator vIt;
    std::list<OrientedLine> intersectors= this->get_intersectors();

    for(vIt = intersectors.begin(); vIt != intersectors.end(); ++vIt)
    {
        std::list<ColliderController*>::iterator it;
        for(it = ColliderController::GetColliderControllers().begin(); it != ColliderController::GetColliderControllers().end(); ++it)
        {
            if((*it)->Model != this)
            {
                Collision collision = ((ACollider*)((*it)->Model))->IsCollidingWithMe((*vIt).GetOrigin(),
                                                                                   ACollider::GetVectorFromTwoPoints((*vIt).GetOrigin(), (*vIt).GetDestination()));

                if(collision.HasCollision)
                {
                    this->notify_collision(collision);
                    ((ACollider*)((*it)->Model))->notify_collision(collision);
                    return;
                }
            }
        }
    }
}

std::list<OrientedLine> ACollider::get_intersectors()
{
    return { OrientedLine() };
}

std::list<ACollisionObserver*>& ACollider::GetCollisionObservers()
{
    return m_collisionObservers;
}

void ACollider::notify_collision(Collision a_collision)
{
    //qDebug() << "oui" << this->m_collisionObservers.size();
    //std::list<ACollisionObserver*>::iterator it;
    (*this->m_collisionObservers.begin())->HandleCollision(a_collision);
    //for(it = m_collisionObservers.begin(); it != this->m_collisionObservers.end(); ++it)
    //{
    //    (*it)->HandleCollision(a_collision);
    //}
}

