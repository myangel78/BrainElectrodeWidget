#pragma once

#include <QGraphicsItem>
#include <QWidget>
#include <QColor>
#include <QPainter>

class ElectrodeItem : public QGraphicsItem
{
public:
    ElectrodeItem(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    QColor mColorDisanbleSelect=Qt::white;
    QColor mColorSelect=QColor(0,255,255);
    QColor mColorStimulate=QColor(0,206,209);
    QColor mColorBorder=Qt::black;
    QColor mColorBackGround=Qt::white;

    bool m_bIsSelected = false;

    QColor m_colorElectrode=Qt::white;

    const int m_size = 50;
protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    // void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    // void keyPressEvent(QKeyEvent *event)override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event)override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event)override;
    // void contextMenuEvent(QGraphicsSceneContextMenuEvent *event)override;

public:
    QSize sizeHint(); //返回组件的缺省大小
    void SetChecked(const bool &checked);
signals:


};
