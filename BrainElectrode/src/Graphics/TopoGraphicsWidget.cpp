#include "TopoGraphicsWidget.h"
#include <QDebug>
#include <QVBoxLayout>

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsWidget>
#include "ElectrodeItem.h"
#include "HeadOutlineItem.h"
#include "TopoGraphicsView.h"



TopoGraphicsWidget::TopoGraphicsWidget(QWidget *parent)
    : QWidget{parent}
{
    InitCtrl();
}

TopoGraphicsWidget::~TopoGraphicsWidget()
{
    delete m_pView;
    delete m_pScene;

}

void TopoGraphicsWidget::InitCtrl()
{
    // 新建场景
    m_pScene = new QGraphicsScene();


    m_pHeadOutlineItem = new HeadOutlineItem();

    for(int i = 0; i < CHANNEL_NUM; ++i)
    {
        m_pElectrodeItem[i] = new ElectrodeItem();
        m_pElectrodeItem[i]->setParentItem(m_pHeadOutlineItem);
        m_pElectrodeItem[i]->setPos(i*50,i*50);
    }


    // 将图形项添加到场景中
    m_pScene->addItem(m_pHeadOutlineItem);

    // 为场景创建视图
    m_pView = new TopoGraphicsView(this);
    m_pView->setScene(m_pScene);
    // m_pScene->setForegroundBrush(QColor(255, 255, 0, 100));
    m_pScene->setBackgroundBrush(QColor(255,255,255, 100));
    // m_pScene.setBackgroundBrush(QPixmap("../mym_pScene/background.png"));

}

void TopoGraphicsWidget::resizeEvent(QResizeEvent *event)
{
    //重新设置子控件的大小和位置
    //...
    QWidget::resizeEvent(event);
    if(m_pHeadOutlineItem)
    {
        int size = qMin(width(),height());
        m_pHeadOutlineItem->setWidth(size);
        m_pScene->setSceneRect(0,0,size,size);
        m_pView->resize(size +2,size+2);
    }
}
