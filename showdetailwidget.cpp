#include "showdetailwidget.h"

//------------------------showDetailItemWidget-----------------------//

ShowDetailItemWidget::ShowDetailItemWidget(QWidget *parent)
    :QWidget(parent)
{
    nameLabel=new QLabel();
    pathLabel=new QLabel();

    QHBoxLayout* layout=new QHBoxLayout();

    layout->addWidget(nameLabel);
    layout->addWidget(pathLabel);

    this->setLayout(layout);
}

//------------------------showDetailTableWidget----------------------//

ShowDetailTableWidget::ShowDetailTableWidget(QWidget *parent)
    :QWidget(parent)
{
    QVBoxLayout* vLayout=new QVBoxLayout();

    chooseItemButton=new QCommandLinkButton();
    chooseItemButton->setIcon(QIcon(QString(":/resource/choose.png")));
    chooseItemButton->setMaximumWidth(120);
    chooseItemButton->setText(tr("选择table项"));

    vLayout->addWidget(chooseItemButton);
    vLayout->addStretch();

    scrollArea=new QScrollArea();

    QHBoxLayout* hLayout=new QHBoxLayout();
    hLayout->addWidget(scrollArea);
    hLayout->addLayout(vLayout);
}

void ShowDetailTableWidget::createTable()
{

}


