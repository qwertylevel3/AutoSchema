#include "resulttab.h"
#include<QLayout>
#include<QDebug>
#include<QXmlStreamWriter>
#include<QFile>
#include<QMessageBox>

ResultTab::ResultTab(XsdAnalyser *a, QWidget *parent) :
    QWidget(parent)
{
    analyser=a;

    scrollArea=new QScrollArea();

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

void ResultTab::initResult(QList<IndexWidget*>& indexList)
{
    list=new QWidget();
    QVBoxLayout* listLayout=new QVBoxLayout();
    list->setLayout(listLayout);


    for(int i=0;i<indexList.size();i++)
    {
        ResultWidget* widget=new ResultWidget();

        widget->setIndexName(indexList[i]->getEName());
        widget->setShowName(indexList[i]->getShowName());
        widget->setType(indexList[i]->getType());

        //qDebug()<<indexList.at(i)->getEName()<<endl;
        //qDebug()<<widget->getIndexName()<<endl;

        listLayout->addWidget(widget);
        resultList.push_back(widget);
    }
    scrollArea->setWidget(list);
}

void ResultTab::sendNext()
{
    emit next();
}

void ResultTab::sendPrevious()
{
    emit previous();
}

void ResultTab::writeFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,tr("can not write file"),
                             tr("无法写result文件"),
                             QMessageBox::Ok);
        return;
    }

    QXmlStreamWriter xmlWriter(&file);

    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("config");

    for(int i=0;i<resultList.size();i++)
    {
        xmlWriter.writeStartElement("result");

        xmlWriter.writeTextElement("indexName",resultList[i]->getIndexName());
        xmlWriter.writeTextElement("showName",resultList[i]->getShowName());
        xmlWriter.writeTextElement("type",QString::number(resultList[i]->getType()));
        xmlWriter.writeTextElement("showdetail",QString::number(resultList[i]->getShowDetail()));

        xmlWriter.writeEndElement();
    }

    xmlWriter.writeEndDocument();

    file.close();
}

