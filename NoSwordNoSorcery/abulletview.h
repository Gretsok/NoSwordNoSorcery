#ifndef ABULLETVIEW_H
#define ABULLETVIEW_H

#include "aview.h"
#include "QVector3D"
#include <QGLWidget>

class ABulletView : public AView
{
public:
    ABulletView();
    virtual ~ABulletView();
    void SetGamePositions(QVector3D a_gamePositions);
protected:
    QVector3D m_gamePositions;
};

#endif // ABULLETVIEW_H
