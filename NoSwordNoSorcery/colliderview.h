#ifndef COLLIDERVIEW_H
#define COLLIDERVIEW_H

#include "aview.h"
#include "line.h"
#include <QVector3D>
#include <QGLWidget>

class ColliderView : public AView
{
public:
    ColliderView();
    ~ColliderView();
    void SetIntersectorsToDraw(std::list<OrientedLine> a_intersectors);
    virtual void Render(void);

protected:
    std::list<OrientedLine> m_intersectorsToDraw;
};

#endif // COLLIDERVIEW_H
