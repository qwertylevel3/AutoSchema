#include "resulttab.h"
#include<QLayout>

ResultTab::ResultTab(XsdAnalyser *a, QWidget *parent) :
    QWidget(parent)
{
    analyser=a;

    scrollArea=new QScrollArea(this);

    nextButton=new QCommandLinkButton;
    nextButton->setIcon(QIcon(QString(":/resource/next.png")));
    nextButton->setMaximumWidth(120);
    nextButton->setText(tr("下一步"));

    previousButton=new QCommandLinkButton;
    previousButton->setIcon(QIcon(QString(":/resource/previous.png")));
    previousButton->setMaximumWidth(120);
    previousButton->setText(tr("上一步"));

    QVBoxLayout* vLayout=new QVBoxLayout();
    vLayout->addStretch();
    vLayout->addWidget(previousButton);
    vLayout->addWidget(nextButton);

    QHBoxLayout* hLayout=new QHBoxLayout();
    hLayout->addWidget(scrollArea);
    hLayout->addLayout(vLayout);

    this->setLayout(hLayout);

    connect(nextButton,SIGNAL(clicked(bool)),
            this,SLOT(sendNext()));
    connect(previousButton,SIGNAL(clicked(bool)),
            this,SLOT(sendPrevious()));

}

void ResultTab::createResult()
{

}

void ResultTab::sendNext()
{
    emit next();
}

void ResultTab::sendPrevious()
{
    emit previous();
}

