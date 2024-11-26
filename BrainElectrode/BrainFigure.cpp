#include "BrainFigure.h"
#include <QToolTip>
#include <QMouseEvent>
#include <QDebug>
#include <QPainterPath>
#include <QGridLayout>
#include "Electrode.h"

BrainFigure::BrainFigure(QWidget *parent)
    : QWidget{parent}
{
    setMouseTracking(true);
    InitCtrl();
}

void BrainFigure::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);

    //设置QPainter的绘图区
    int side = qMin(width(), height());
    // 设置视口
    // painter.setViewport(0, 0, side, side);
    // painter.setWindow(0, 0, 100, 100);

    //设置画笔
    QPen pen;
    pen.setWidth(1);
    pen.setColor(mColorBorder);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter.setPen(pen);
    painter.setBrush(mColorBackGround);

    //画大圆
    painter.save();
    painter.translate(side/2,side/2);
    pen.setWidth(2);
    painter.setPen(pen);
    qreal bigcircleradius = side/2 -20;
    QRectF bigCircle = QRectF(-bigcircleradius,-bigcircleradius,bigcircleradius * 2 ,bigcircleradius *2);
    painter.drawEllipse(bigCircle);
    //画边圆
    qreal smallcircleradius = side/2.3;
    QRectF smalCircle = QRectF(-smallcircleradius,-smallcircleradius,smallcircleradius * 2 ,smallcircleradius *2);
    painter.drawEllipse(smalCircle);

    //画鼻子
    painter.save();
    QPainterPath polygonNosePath;
    polygonNosePath.moveTo(-20, bigCircle.top());
    polygonNosePath.lineTo(20, bigCircle.top());
    polygonNosePath.lineTo(0, bigCircle.top() -20);
    polygonNosePath.closeSubpath();
    painter.setBrush(Qt::yellow);
    painter.drawPath(polygonNosePath);
    painter.restore();

    //画耳朵
    painter.save();
    QPainterPath polygonEarPath;
    painter.translate(-bigcircleradius,0);
    polygonEarPath.moveTo(0,0);
    QRectF rectEar(-10,-30,10,60);
    polygonEarPath.arcTo(rectEar,16 * 0 ,16 *180);
    // polygonEarPath.closeSubpath();
    painter.setBrush(QColor(255,182,193));
    painter.drawPath(polygonEarPath);
    painter.translate(2 * bigcircleradius,0);

    painter.save();
    painter.rotate(180);
    painter.drawPath(polygonEarPath);
    painter.restore();
    painter.restore();

    //画十字线
    QPainterPath path;
    path.moveTo(0,bigCircle.top());
    path.lineTo(0,bigCircle.bottom());

    path.moveTo(bigCircle.left(),0);
    path.lineTo(bigCircle.right(),0);


    // path.closeSubpath();
    pen.setWidthF(1.0);
    pen.setStyle(Qt::DashLine);
    painter.setPen(pen);
    painter.drawPath(path);
    painter.restore();



    m_vecPointLocation.clear();

    path.translate(side/2,side/2);
    for(float i = 0.1; i< 1; )
    {
        m_vecPointLocation.push_back(path.pointAtPercent(i));
        i += 0.1;
    }

    float size = 40;
    float halfsize = size/2;

    for(int i = 0; i < CHANNEL_NUM; ++i)
    {
        m_pElectrode[i]->setGeometry(m_vecPointLocation[i].x() -halfsize,m_vecPointLocation[i].y()-halfsize,size,size);
    }
}



void BrainFigure::mouseMoveEvent(QMouseEvent *event)
{
    QString pos = QString("%1,%2").arg(event->pos().x()).arg(event->pos().y());
    QToolTip::showText(event->globalPos(), pos, this);
}


void BrainFigure::mouseDoubleClickEvent(QMouseEvent *event)
{
}

QSize BrainFigure::sizeHint()const
{
    int H=this->height();
    int W=H*12/5;
    QSize size(W,H);
    return size;
}

void BrainFigure::InitCtrl()
{

    QGridLayout *pgridlayout = new QGridLayout();

    int row = 2;
    int col = 4;

    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            int chn = i * col + j;
            m_pElectrode[chn] = new Electrode(this);
            pgridlayout->addWidget(m_pElectrode[chn],i,j);

            m_pElectrode[chn]->setMinimumSize(20,20);
            m_pElectrode[chn]->setMaximumSize(1000,1000);
                // m_pElectrode[chn]->setGeometry(QRect(i*5,i*5,40,40));
        }
    }
    setLayout(pgridlayout);
}



