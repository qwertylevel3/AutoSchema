#include "showdetailwidget.h"
#include"date/element.h"

//------------------------showDetailItemWidget-----------------------//

ShowDetailItemWidget::ShowDetailItemWidget(QWidget *parent)
    :QWidget(parent)
{
    nameLineEdit=new QLineEdit();
    pathLabel=new QLabel();

    QHBoxLayout* layout=new QHBoxLayout();

    layout->addWidget(nameLineEdit);
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

    this->setLayout(hLayout);

    connect(chooseItemButton,SIGNAL(clicked(bool)),
            this,SLOT(createTable()));
}

void ShowDetailTableWidget::createTable()
{
    itemListWidget=new QWidget();
    QVBoxLayout* listLayout=new QVBoxLayout();
    itemListWidget->setLayout(listLayout);

    dialog.exec();

    QStandardItemModel* model=dialog.getModel();
    if(model)
    {

        for(int i=0;i<model->rowCount();i++)
        {
            Element* item=static_cast<Element*>(model->item(i));
            ShowDetailItemWidget* showDetailItem=new ShowDetailItemWidget();
            showDetailItem->setNameLabel(item->getId());
            showDetailItem->setPathLabel(item->getPath());

            listLayout->addWidget(showDetailItem);
            list.push_back(showDetailItem);
        }
        scrollArea->setWidget(itemListWidget);
    }

}


