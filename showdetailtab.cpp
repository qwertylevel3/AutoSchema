#include "showdetailtab.h"


ShowDetailTab::ShowDetailTab(XsdAnalyser *a, QWidget *parent) :
    QWidget(parent)
{
    analyser=a;

    QHBoxLayout* hLayout=new QHBoxLayout();

    tableNameLineEdit=new QLineEdit();

    addTableLinkButton=new QCommandLinkButton;
    addTableLinkButton->setIcon(QIcon(QString(":/resource/add.png")));
    addTableLinkButton->setMaximumWidth(120);
    addTableLinkButton->setText(tr("增加table"));

    deleteTableLinkButton=new QCommandLinkButton;
    deleteTableLinkButton->setIcon(QIcon(QString(":/resource/delete.png")));
    deleteTableLinkButton->setMaximumWidth(120);
    deleteTableLinkButton->setText(tr("删除当前table"));

    hLayout->addStretch();
    hLayout->addWidget(tableNameLineEdit);
    hLayout->addWidget(addTableLinkButton);
    hLayout->addWidget(deleteTableLinkButton);

    tabWidget=new QTabWidget();


    previousLinkButton=new QCommandLinkButton;
    previousLinkButton->setIcon(QIcon(QString(":/resource/previous.png")));
    previousLinkButton->setMaximumWidth(120);
    previousLinkButton->setText(tr("上一步"));

    completeLinkButton=new QCommandLinkButton;
    completeLinkButton->setIcon(QIcon(QString(":/resource/complete.png")));
    completeLinkButton->setMaximumWidth(120);
    completeLinkButton->setText(tr("完成"));

    QHBoxLayout* hLayout2=new QHBoxLayout();
    hLayout2->addStretch();
    hLayout2->addWidget(previousLinkButton);
    hLayout2->addWidget(completeLinkButton);

    QVBoxLayout* vLayout=new QVBoxLayout();
    vLayout->addLayout(hLayout);
    vLayout->addWidget(tabWidget);
    vLayout->addLayout(hLayout2);

    this->setLayout(vLayout);

    connect(addTableLinkButton,SIGNAL(clicked(bool)),
            this,SLOT(addTable()));
    connect(deleteTableLinkButton,SIGNAL(clicked(bool)),
            this,SLOT(deleteTable()));
    connect(previousLinkButton,SIGNAL(clicked(bool)),
            this,SLOT(sendPrevious()));
    connect(completeLinkButton,SIGNAL(clicked(bool)),
            this,SLOT(sendComplete()));

}

void ShowDetailTab::addTable()
{

}

void ShowDetailTab::deleteTable()
{

}

void ShowDetailTab::sendPrevious()
{
    emit previous();
}

void ShowDetailTab::sendComplete()
{
    emit complete();
}


