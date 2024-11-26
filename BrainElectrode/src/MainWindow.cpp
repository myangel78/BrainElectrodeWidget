#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include "TopoWidget.h"
#include "TopoGraphicsWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    InitCtrl();
    setMinimumSize(800,800);
}

MainWindow::~MainWindow()
{
    if(m_pTopoWidget)
    {
        delete m_pTopoWidget;
    }
    if(m_pTopoGraphicsView)
    {
        delete m_pTopoGraphicsView;
    }
    delete  m_pWidget;
}


void MainWindow::InitCtrl()
{

    m_pWidget = new QWidget(this);
#if 0
    m_pTopoWidget = new TopoWidget(this);
    QVBoxLayout *vertlayout = new QVBoxLayout();
    vertlayout->addWidget(m_pTopoWidget);
#else
    m_pTopoGraphicsView = new TopoGraphicsWidget(this);
    QVBoxLayout *vertlayout = new QVBoxLayout();
    vertlayout->addWidget(m_pTopoGraphicsView);
#endif
    m_pWidget->setLayout(vertlayout);

    m_pWidget->setMinimumSize(QSize(600,600));
    setCentralWidget(m_pWidget);

}
