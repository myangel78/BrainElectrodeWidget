#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include "TopoWidget.h"
#include "TopoGraphicsWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    InitConfig();
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




