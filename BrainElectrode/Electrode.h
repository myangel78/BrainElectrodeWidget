#pragma once

#include <QWidget>
#include <QColor>
#include <QPainter>


class Electrode : public QWidget
{
    Q_OBJECT
public:
    explicit Electrode(QWidget *parent = nullptr);

private:
    QColor mColorDisanbleSelect=Qt::white;
    QColor mColorSelect=QColor(0,255,255);
    QColor mColorStimulate=QColor(0,206,209);
    QColor mColorBorder=Qt::black;
    QColor mColorBackGround=Qt::white;

    bool m_bIsSelected = false;

    QColor m_colorElectrode=Qt::white;
protected:
    void paintEvent(QPaintEvent *event)Q_DECL_OVERRIDE; //绘图
    void mouseMoveEvent(QMouseEvent *event)override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
public:
    QSize sizeHint(); //返回组件的缺省大小
    void SetChecked(const bool &checked);

    void SetPosition(const QPointF &center, const int width);
signals:
    //当电量值改变时发射此信号
    void powerLevelChanged(int);

};
