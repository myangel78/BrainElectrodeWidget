#pragma once

#include <QMainWindow>
class Electrode;
class BrainFigure;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void InitCtrl();
    static const int CHANNEL_NUM = 8;
    QWidget *m_pWidget = nullptr;


private:
    Electrode *m_pElectrode[CHANNEL_NUM];

    BrainFigure *m_pBrainFigure = nullptr;
};
