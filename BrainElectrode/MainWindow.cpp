#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include "TopoWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    InitCtrl();
}

MainWindow::~MainWindow()
{

}


void MainWindow::InitCtrl()
{
    m_pWidget = new QWidget(this);

    m_pTopoWidget = new TopoWidget(this);
    QVBoxLayout *vertlayout = new QVBoxLayout();
    vertlayout->addWidget(m_pTopoWidget);
    m_pWidget->setLayout(vertlayout);

    m_pWidget->setMinimumSize(QSize(600,600));

    setCentralWidget(m_pWidget);
}
