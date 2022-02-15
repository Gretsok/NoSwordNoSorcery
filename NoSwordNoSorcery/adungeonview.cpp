#include "adungeonview.h"
#include <QDebug>

ADungeonView::ADungeonView() : AView {}
{

}

ADungeonView::~ADungeonView()
{

}

void ADungeonView::Render(){

}

QVector3D ADungeonView::GetBottomDoorEntrancePosition()
{
    return QVector3D(0,-3,0);
}
QVector3D ADungeonView::GetTopDoorEntrancePosition()
{
 return QVector3D(0,3,0);
}
QVector3D ADungeonView::GetLeftDoorEntrancePosition()
{
    return QVector3D(-3,0,0);
}
QVector3D ADungeonView::GetRightDoorEntrancePosition()
{
    return QVector3D(3,0,0);
}
