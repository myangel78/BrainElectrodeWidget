#include "TopoGraphicsView.h"
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsItem>

TopoGraphicsView::TopoGraphicsView(QWidget *parent)
    : QGraphicsView{parent}
{

}

void TopoGraphicsView::mousePressEvent(QMouseEvent *event)
{
    // 分别获取鼠标点击处在视图、场景和图形项中的坐标，并输出
    QPoint viewPos = event->pos();
    qDebug() << "viewPos: " << viewPos;
    QPointF scenePos = mapToScene(viewPos);
    qDebug() << "scenePos: " << scenePos;
    QGraphicsItem *item = scene()->itemAt(scenePos, QTransform());
    if (item) {
        QPointF itemPos = item->mapFromScene(scenePos);
        qDebug() << "itemPos: " << itemPos;
    }

    QGraphicsView::mousePressEvent(event);
}

void TopoGraphicsView::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Plus :
        scale(1.2, 1.2);
        break;
    case Qt::Key_Minus :
        scale(1 / 1.2, 1 / 1.2);
        break;
    case Qt::Key_Right :
        rotate(30);
        break;
    }
    QGraphicsView::keyPressEvent(event);

}

