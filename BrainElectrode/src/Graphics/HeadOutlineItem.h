#pragma once

#include <QGraphicsItem>
#include <QWidget>
#include <QColor>
#include <QPainter>

class HeadOutlineItem : public QGraphicsItem
{
public:
    HeadOutlineItem(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget)override;

private:
    QColor mColorBorder=Qt::black;
    QColor mColorBackGround=Qt::white;

    int m_size = 500;
protected:

    // void keyPressEvent(QKeyEvent *event)override;
    // void mousePressEvent(QGraphicsSceneMouseEvent *event)override;
    // void hoverEnterEvent(QGraphicsSceneHoverEvent *event)override;
    // void contextMenuEvent(QGraphicsSceneContextMenuEvent *event)override;

public:
    QSize sizeHint(); //返回组件的缺省大小

    void setWidth(const int &size){m_size = size;}
signals:


};
