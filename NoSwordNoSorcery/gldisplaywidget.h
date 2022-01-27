#ifndef GLDISPLAYWIDGET_H
#define GLDISPLAYWIDGET_H

#include <QGLWidget> // Module QtOpengL (classes QGLxxx in Qt4),
                     // with widget and rendering classes descending from QGLWidget,
                     // deprecated for module QtGui (classes QOpenGLxxx )
                     // and module widgets (QWidget, QGraphicsView).
#include <QtWidgets>
#include <QTimer>
#include "dungeoncontroller.h"
#include "dungeonview2d.h"
#include "dungeonmodel.h"
#include "adungeonview.h"

class GLDisplayWidget : public QGLWidget
{
    friend class QMainWindow;
    friend class MainWindow;
public:
    explicit GLDisplayWidget(QWidget *parent = 0);

    void initializeGL();
    void paintGL(); // Display the scene Gl
    void resizeGL(int width, int height);

protected:
    // Mouse Management
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

private:

    QTimer _timer; // To update the scene
    float _X, _Y ,_Z; // Translation

    QPoint _lastPosMouse; // To keep the last position of the mouse
    DungeonController dungeonController;
};

#endif // GLDISPLAYWIDGET_H
