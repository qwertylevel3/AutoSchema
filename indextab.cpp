#include "indextab.h"
#include<date/element.h>


IndexTab::IndexTab(XsdAnalyser *a, QWidget *parent) :
    QWidget(parent)
{
    analyser=a;

    scrollArea=new QScrollArea(this);

    nextButton=new QCommandLinkButton;
    nextButton->setIcon(QIcon(QString(":/resource/next.png")));
    nextButton->setMaximumWidth(120);
    nextButton->setText(tr("下一步"));

    chooseItemButton=new QCommandLinkButton;
    chooseItemButton->setIcon(QIcon(QString(":/resource/add.png")));
    chooseItemButton->setMaximumWidth(120);
    chooseItemButton->setText(tr("选择index项"));

    QVBoxLayout* vLayout=new QVBoxLayout();
    vLayout->addWidget(chooseItemButton);
    vLayout->addStretch();
    vLayout->addWidget(nextButton);

    QHBoxLayout* hLayout=new QHBoxLayout();
    hLayout->addWidget(scrollArea);
    hLayout->addLayout(vLayout);

    this->setLayout(hLayout);

    connect(chooseItemButton,SIGNAL(clicked(bool)),
            this,SLOT(createIndex()));
    connect(nextButton,SIGNAL(clicked(bool)),
            this,SLOT(sendNext()));
}

void IndexTab::createIndex()
{
    list=new QWidget();
    QVBoxLayout* listLayout=new QVBoxLayout();
    list->setLayout(listLayout);
    dialog=new ChooseItemDialog(analyser);

    if(dialog->exec())
    {
        model=dialog->getModel();
        for(int i=0;i<model->rowCount();i++)
        {
            Element* item=static_cast<Element*>(model->item(i));
            IndexWidget* indexItem=new IndexWidget(this);
            indexItem->setENameLabel(item->getName());
            indexItem->setCNameLabel(item->getId());
            indexItem->setPathLabel(item->getPath());

            QString annotation;
            for(int i=0;i<item->getAnnotation().size();i++)\
            {
                annotation.append(item->getAnnotation().at(i));
            }
            indexItem->setStatusTip(annotation);
            listLayout->addWidget(indexItem);
            indexList.push_back(indexItem);
        }
    }
    scrollArea->setWidget(list);
}

void IndexTab::sendNext()
{
    emit next();
}

