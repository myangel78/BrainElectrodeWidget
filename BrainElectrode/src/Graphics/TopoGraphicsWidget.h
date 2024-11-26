#pragma once

#include <QWidget>
#include <QGraphicsScene>
#include "Global.h"
class ElectrodeItem;
class HeadOutlineItem;
class TopoGraphicsView;


class TopoGraphicsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TopoGraphicsWidget(QWidget *parent = nullptr);
    ~TopoGraphicsWidget();

signals:
protected:
    void resizeEvent(QResizeEvent *event);
private:
    void InitCtrl(void);

private:
    // 新建场景
    QGraphicsScene *m_pScene = nullptr;
    ElectrodeItem *m_pElectrodeItem[CHANNEL_NUM];
    HeadOutlineItem *m_pHeadOutlineItem = nullptr;
    TopoGraphicsView *m_pView = nullptr;

};
