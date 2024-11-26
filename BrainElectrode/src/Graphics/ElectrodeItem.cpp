#include "ElectrodeItem.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QToolTip>
#include <QCursor>
#include <QKeyEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>


ElectrodeItem::ElectrodeItem(QGraphicsItem *parent)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setAcceptHoverEvents(true);
}

QRectF ElectrodeItem::boundingRect() const
{

    qreal adjust = 2;
    int halfsize = 0;
    return QRectF(-halfsize - adjust, -halfsize - adjust,
                  m_size + adjust, m_size + adjust);

}

void ElectrodeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
#if 1
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setRenderHint(QPainter::TextAntialiasing);


    //设置QPainter的绘图区
    // int side = qMin(width(), height());
    int side = qMin(m_size,m_size);
    // qDebug()<< "ori width(), height()" <<width() <<height();
    // 设置视口
    // painter->setViewport(0, 0, side, side);
    // painter->setWindow(0, 0, 100, 100);

    //设置画笔
    QPen pen;
    pen.setWidth(2);
    pen.setColor(mColorBorder);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter->setPen(pen);
    painter->setBrush(mColorBackGround);
    painter->save();

    //绘制大圆
    painter->setBrush(m_colorElectrode);
    painter->translate(side/2,side/2);
    pen.setWidth(2);
    painter->setPen(pen);
    qreal bigcircleradius = side/2 -2;
    QRectF bigCircle = QRectF(-bigcircleradius,-bigcircleradius,bigcircleradius * 2 ,bigcircleradius *2);
    painter->drawEllipse(bigCircle);



    //绘制小圆
    painter->setBrush(mColorBackGround);
    painter->translate(0,bigcircleradius/2);
    qreal smallcircleradius = bigcircleradius/2;
    QRectF smalCircle = QRectF(-smallcircleradius,-smallcircleradius,smallcircleradius * 2 ,smallcircleradius *2);
    painter->drawEllipse(smalCircle);

    // QFontMetrics textSize(this->font());
    QFont font("Microsoft YaHei", 7, QFont::Normal);
    QFontMetrics textSize(font);
    QString powerStr=QString::asprintf("CH1");
    QRect textRect=textSize.boundingRect(powerStr); //得到字符串的rect
    painter->drawText(smalCircle.center().x()-textRect.width()/2,smalCircle.center().y()+textRect.height()/2,powerStr);
    painter->restore();

    if(m_bIsSelected)
    {

        painter->save();
        //电刺激charge
        painter->translate(side/2,0);
        //有区别
        // float scale = height() * 1.0/width();
        // painter->scale(0.2,0.2);


        QPainterPath polygonPath;

        polygonPath.moveTo(-12, 0);
        polygonPath.lineTo(-40, 56);
        polygonPath.lineTo(-6, 55);
        polygonPath.lineTo(-21, 99);

        polygonPath.lineTo(38, 32);
        polygonPath.lineTo(1, 32);
        polygonPath.lineTo(21, 0);
        polygonPath.lineTo(-12, 0);

        //缩放比例
        float scale = side * 1.0 /polygonPath.boundingRect().width()/2.5;
        painter->scale(scale,scale);

        painter->setPen(QPen(QColor(79, 106, 25), 1, Qt::SolidLine,
                            Qt::FlatCap, Qt::MiterJoin));
        painter->setBrush(mColorStimulate);
        polygonPath.setFillRule(Qt::OddEvenFill);



        painter->drawPath(polygonPath);

        painter->restore();



        // qDebug()<<" scale "<< scale ;
        // qDebug()<<" side "<< side ;
        // qDebug()<<" bigCircle.width()/2 "<< bigCircle.width()/2 ;
        // qDebug()<< "polygonPath.boundingRect().width()"<< polygonPath.boundingRect().width();
        // qDebug()<<" polygonPath.boundingRect().center()"<<polygonPath.boundingRect().center();

    }
#else
    // if (hasFocus()) {
    //     painter->setPen(QPen(QColor(255, 255, 255, 200)));
    // } else {
        painter->setPen(QPen(QColor(100, 100, 100, 100)));
    // }
    painter->setBrush(Qt::red);
    painter->drawRect(-10, -10, 20, 20);
#endif
}

void ElectrodeItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    SetChecked(!m_bIsSelected);
}

// void ElectrodeItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
// {
//     QString pos = QString("%1,%2").arg(event->pos().x()).arg(event->pos().y());
//     // QToolTip::showText(event->screenPos(), pos, this);
// }

void ElectrodeItem::SetChecked(const bool &checked)
{
    if(checked != m_bIsSelected)
    {
        m_bIsSelected = checked;
        m_colorElectrode= checked ? mColorSelect :mColorDisanbleSelect;

        update();
    }
}



// 鼠标按下事件处理函数，设置被点击的图形项获得焦点，并改变光标外观
void ElectrodeItem::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    setFocus();
    setCursor(Qt::ClosedHandCursor);
}
// // 键盘按下事件处理函数，判断是否是向下方向键，如果是，则向下移动图形项
// void ElectrodeItem::keyPressEvent(QKeyEvent *event)
// {
//     if (event->key() == Qt::Key_Down)
//         moveBy(0, 10);
// }
// 悬停事件处理函数，设置光标外观和提示
void ElectrodeItem::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    setCursor(Qt::OpenHandCursor);
    setToolTip("I am item");
}
// // 右键菜单事件处理函数，为图形项添加一个右键菜单
// void ElectrodeItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
// {
//     QMenu menu;
//     QAction *moveAction = menu.addAction("move back");
//     QAction *selectedAction = menu.exec(event->screenPos());
//     if (selectedAction == moveAction) {
//         setPos(0, 0);
//     }
// }
