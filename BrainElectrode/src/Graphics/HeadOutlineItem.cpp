#include "HeadOutlineItem.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QToolTip>
#include <QCursor>
#include <QKeyEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>


HeadOutlineItem::HeadOutlineItem(QGraphicsItem *parent)
{
    // setFlag(QGraphicsItem::ItemIsFocusable);
    // setFlag(QGraphicsItem::ItemIsMovable);
    setAcceptHoverEvents(true);
}

QRectF HeadOutlineItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth / 2, 0 - penWidth / 2,
                  m_size + penWidth, m_size + penWidth);
}

void HeadOutlineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setRenderHint(QPainter::TextAntialiasing);

    //设置QPainter的绘图区
    // int side = qMin(width(), height());
    int side = qMin(m_size, m_size);
    // 设置视口
    // painter->setViewport(0, 0, side, side);
    // painter->setWindow(0, 0, 100, 100);

    //设置画笔
    QPen pen;
    pen.setWidth(1);
    pen.setColor(mColorBorder);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter->setPen(pen);
    painter->setBrush(mColorBackGround);

    //画大圆
    painter->save();
    painter->translate(side/2,side/2);
    pen.setWidth(2);
    painter->setPen(pen);
    qreal bigcircleradius = side/2 -20;
    QRectF bigCircle = QRectF(-bigcircleradius,-bigcircleradius,bigcircleradius * 2 ,bigcircleradius *2);
    painter->drawEllipse(bigCircle);
    //画边圆
    qreal smallcircleradius = side/2.3;
    QRectF smalCircle = QRectF(-smallcircleradius,-smallcircleradius,smallcircleradius * 2 ,smallcircleradius *2);
    painter->drawEllipse(smalCircle);

    //画鼻子
    painter->save();
    QPainterPath polygonNosePath;
    polygonNosePath.moveTo(-20, bigCircle.top());
    polygonNosePath.lineTo(20, bigCircle.top());
    polygonNosePath.lineTo(0, bigCircle.top() -20);
    polygonNosePath.closeSubpath();
    painter->setBrush(Qt::yellow);
    painter->drawPath(polygonNosePath);
    painter->restore();

    //画耳朵
    painter->save();
    QPainterPath polygonEarPath;
    painter->translate(-bigcircleradius,0);
    polygonEarPath.moveTo(0,0);
    QRectF rectEar(-10,-30,10,60);
    polygonEarPath.arcTo(rectEar,16 * 0 ,16 *180);
    // polygonEarPath.closeSubpath();
    painter->setBrush(QColor(255,182,193));
    painter->drawPath(polygonEarPath);
    painter->translate(2 * bigcircleradius,0);

    painter->save();
    painter->rotate(180);
    painter->drawPath(polygonEarPath);
    painter->restore();
    painter->restore();

    //画十字线
    QPainterPath path;
    path.moveTo(0,bigCircle.top());
    path.lineTo(0,bigCircle.bottom());

    path.moveTo(bigCircle.left(),0);
    path.lineTo(bigCircle.right(),0);


    // path.closeSubpath();
    pen.setWidthF(1.0);
    pen.setStyle(Qt::DashLine);
    painter->setPen(pen);
    painter->drawPath(path);
    painter->restore();

}







// // 鼠标按下事件处理函数，设置被点击的图形项获得焦点，并改变光标外观
// void HeadOutlineItem::mousePressEvent(QGraphicsSceneMouseEvent *)
// {
//     setFocus();
//     setCursor(Qt::ClosedHandCursor);
// }
// // 键盘按下事件处理函数，判断是否是向下方向键，如果是，则向下移动图形项
// void HeadOutlineItem::keyPressEvent(QKeyEvent *event)
// {
//     if (event->key() == Qt::Key_Down)
//         moveBy(0, 10);
// }
// // 悬停事件处理函数，设置光标外观和提示
// void HeadOutlineItem::hoverEnterEvent(QGraphicsSceneHoverEvent *)
// {
//     setCursor(Qt::OpenHandCursor);
//     setToolTip("I am item");
// }
// // 右键菜单事件处理函数，为图形项添加一个右键菜单
// void HeadOutlineItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
// {
//     QMenu menu;
//     QAction *moveAction = menu.addAction("move back");
//     QAction *selectedAction = menu.exec(event->screenPos());
//     if (selectedAction == moveAction) {
//         setPos(0, 0);
//     }
// }
