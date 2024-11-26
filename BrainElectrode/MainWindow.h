#pragma once

#include <QMainWindow>
class TopoWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void InitCtrl();
    QWidget *m_pWidget = nullptr;

    TopoWidget *m_pTopoWidget = nullptr;



};
