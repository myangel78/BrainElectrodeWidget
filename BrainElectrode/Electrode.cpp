#include "Electrode.h"
#include <QToolTip>
#include <QMouseEvent>
#include <QDebug>
#include <QPainterPath>

Electrode::Electrode(QWidget *parent)
    : QWidget{parent}
{
    setMouseTracking(true);
}


#if 1
void Electrode::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);


    //设置QPainter的绘图区
    int side = qMin(width(), height());
    // qDebug()<< "ori width(), height()" <<width() <<height();
    // 设置视口
    // painter.setViewport(0, 0, side, side);
    // painter.setWindow(0, 0, 100, 100);

    //设置画笔
    QPen pen;
    pen.setWidth(2);
    pen.setColor(mColorBorder);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);
    painter.setBrush(mColorBackGround);
    painter.save();

    //绘制大圆
    painter.setBrush(m_colorElectrode);
    painter.translate(side/2,side/2);
    pen.setWidth(2);
    painter.setPen(pen);
    qreal bigcircleradius = side/2 -2;
    QRectF bigCircle = QRectF(-bigcircleradius,-bigcircleradius,bigcircleradius * 2 ,bigcircleradius *2);
    painter.drawEllipse(bigCircle);



    //绘制小圆
    painter.setBrush(mColorBackGround);
    painter.translate(0,bigcircleradius/2);
    qreal smallcircleradius = bigcircleradius/2;
    QRectF smalCircle = QRectF(-smallcircleradius,-smallcircleradius,smallcircleradius * 2 ,smallcircleradius *2);
    painter.drawEllipse(smalCircle);

    QFontMetrics textSize(this->font());
    QString powerStr=QString::asprintf("CH1");
    QRect textRect=textSize.boundingRect(powerStr); //得到字符串的rect
    painter.drawText(smalCircle.center().x()-textRect.width()/2,smalCircle.center().y()+textRect.height()/2,powerStr);
    painter.restore();

    if(m_bIsSelected)
    {

        painter.save();
        //电刺激charge
        painter.translate(side/2,0);
        //有区别
        // float scale = height() * 1.0/width();
        // painter.scale(0.2,0.2);


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
        painter.scale(scale,scale);

        painter.setPen(QPen(QColor(79, 106, 25), 1, Qt::SolidLine,
                            Qt::FlatCap, Qt::MiterJoin));
        painter.setBrush(mColorStimulate);
        polygonPath.setFillRule(Qt::OddEvenFill);



        painter.drawPath(polygonPath);

        painter.restore();



        // qDebug()<<" scale "<< scale ;
        // qDebug()<<" side "<< side ;
        // qDebug()<<" bigCircle.width()/2 "<< bigCircle.width()/2 ;
        // qDebug()<< "polygonPath.boundingRect().width()"<< polygonPath.boundingRect().width();
        // qDebug()<<" polygonPath.boundingRect().center()"<<polygonPath.boundingRect().center();
    }


}

#else
void Electrode::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);


    //设置QPainter的绘图区
    int side = qMin(width(), height());
    // 设置视口
    painter.setViewport(0, 0, side, side);
    painter.setWindow(0, 0, 100, 100);

    //设置画笔
    QPen pen;
    pen.setWidth(2);
    pen.setColor(mColorBorder);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);
    painter.setBrush(mColorBackGround);

    painter.save();

    painter.setBrush(m_colorElectrode);
    int circleradius = 48;
    QRectF bigCircle = QRectF(50 - circleradius ,50 - circleradius,circleradius * 2 ,circleradius *2);
    painter.drawEllipse(bigCircle);


    painter.restore();
    circleradius = 20;
    QRectF smalCircle = QRectF(50 - circleradius ,99 - circleradius *2 ,circleradius * 2 ,circleradius *2);
    painter.drawEllipse(smalCircle);

    // qDebug()<<"bigCircle.center()"<<bigCircle.center();
    // qDebug()<<"smalCircle.center()"<<smalCircle.center();


    QFontMetrics textSize(this->font());
    QString powerStr=QString::asprintf("CH1");
    QRect textRect=textSize.boundingRect(powerStr); //得到字符串的rect
    painter.drawText(smalCircle.center().x()-textRect.width()/2,smalCircle.center().y()+textRect.height()/2,powerStr);

    if(m_bIsSelected)
    {
        painter.save();
        //电刺激charge
        QPainterPath polygonPath;
        polygonPath.moveTo(40, 5);
        polygonPath.lineTo(10, 50);
        polygonPath.lineTo(45, 50);
        polygonPath.lineTo(30, 90);

        polygonPath.lineTo(90, 30);
        polygonPath.lineTo(55, 30);
        polygonPath.lineTo(70, 5);
        polygonPath.lineTo(40, 5);

        // polygonPath.closeSubpath();

        painter.setPen(QPen(QColor(79, 106, 25), 1, Qt::SolidLine,
                            Qt::FlatCap, Qt::MiterJoin));
        painter.setBrush(mColorStimulate);
        polygonPath.setFillRule(Qt::OddEvenFill);
        painter.scale(0.5,0.5);
        // qDebug()<< bigCircle.width()/2 ;
        // qDebug()<< polygonPath.boundingRect().width();
        // qDebug()<< polygonPath.boundingRect().center();
        int offset = bigCircle.x() +  (bigCircle.width()/2- polygonPath.boundingRect().width()*0.5/2)*2;
        painter.translate(offset,0);

        painter.drawPath(polygonPath);

        painter.restore();
    }

}

#endif

void Electrode::mouseMoveEvent(QMouseEvent *event)
{
    QString pos = QString("%1,%2").arg(event->pos().x()).arg(event->pos().y());
    QToolTip::showText(event->globalPos(), pos, this);
}


void Electrode::mouseDoubleClickEvent(QMouseEvent *event)
{
    SetChecked(!m_bIsSelected);
}



QSize Electrode::sizeHint()
{
    int H=this->height();
    int W=H*12/5;
    // int W=this->width();
    QSize size(W,H);
    return size;
}

void Electrode::SetChecked(const bool &checked)
{
    if(checked != m_bIsSelected)
    {
        m_bIsSelected = checked;
        m_colorElectrode= checked ? mColorSelect :mColorDisanbleSelect;

        update();
    }
}


void Electrode::SetPosition(const QPointF &center,const int len)
{
    QRect rect(center.x() -len ,center.y() -len,len,len);
    this->setGeometry(rect);
}
