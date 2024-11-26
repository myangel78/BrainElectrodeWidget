#pragma once

#include <QObject>
#include <QGraphicsView>

class TopoGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit TopoGraphicsView(QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
signals:
};
