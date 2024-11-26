#include "TopoWidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include "Electrode.h"
#include "BrainFigure.h"

TopoWidget::TopoWidget(QWidget *parent)
    : QWidget{parent}
{
    InitCtrl();

}

TopoWidget::~TopoWidget()
{
    delete m_pBrainFigure;
}


#if 1
void TopoWidget::InitCtrl(void)
{

    m_pBrainFigure = new BrainFigure(this);

    QGridLayout *pgridlayout = new QGridLayout();

#if 1
    int row = CHANNEL_NUM/2;
    int col = CHANNEL_NUM/row;
#else
    int row = 1;
    int col = 1;
#endif
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            int chn = i * col + j;
            m_pElectrode[chn] = new Electrode(this);
            pgridlayout->addWidget(m_pElectrode[chn],i,j);
        }
    }

    QHBoxLayout *vertlayot = new QHBoxLayout();
    vertlayot->addWidget(m_pBrainFigure);
    vertlayot->addLayout(pgridlayout);
    vertlayot->setStretch(0,2);
    vertlayot->setStretch(1,1);
    setLayout(vertlayot);

}
#else
void TopoWidget::InitCtrl(void)
{
    m_pBrainFigure = new BrainFigure(this);

    QHBoxLayout *vertlayot = new QHBoxLayout();
    vertlayot->addWidget(m_pBrainFigure);
    setLayout(vertlayot);

}
#endif
