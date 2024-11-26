#pragma once

#include <QWidget>
#include "Global.h"
class Electrode;
class BrainFigure;


class TopoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TopoWidget(QWidget *parent = nullptr);
    ~TopoWidget();

signals:
private:
    void InitCtrl(void);

private:
    Electrode *m_pElectrode[CHANNEL_NUM];
    BrainFigure *m_pBrainFigure = nullptr;

};
