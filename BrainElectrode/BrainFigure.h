#pragma once

#include <QWidget>
#include <QColor>
#include <QPainter>
#include "Global.h"
class Electrode;


class BrainFigure : public QWidget
{
    Q_OBJECT
public:
    explicit BrainFigure(QWidget *parent = nullptr);

private:
    QColor mColorBorder=Qt::black;
    QColor mColorBackGround=Qt::white;

    bool m_bIsSelected = false;

    Electrode *m_pElectrode[CHANNEL_NUM];
    QVector<QPointF> m_vecPointLocation;


protected:
    void paintEvent(QPaintEvent *event)Q_DECL_OVERRIDE; //绘图
    void mouseMoveEvent(QMouseEvent *event)override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
public:
    QSize sizeHint() const override; //返回组件的缺省大小



signals:
    //当电量值改变时发射此信号
    void powerLevelChanged(int);

private:
    void InitCtrl(void);

};
