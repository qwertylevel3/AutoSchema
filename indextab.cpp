#include "indextab.h"
#include<date/element.h>
#include<QXmlStreamWriter>
#include<QFile>
#include<QMessageBox>


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

    listWidget=new QWidget();
    listLayout=new QVBoxLayout();
    listWidget->setLayout(listLayout);
    scrollArea->setWidget(listWidget);

    this->setLayout(hLayout);

    connect(chooseItemButton,SIGNAL(clicked(bool)),
            this,SLOT(createIndex()));
    connect(nextButton,SIGNAL(clicked(bool)),
            this,SLOT(sendNext()));
}

void IndexTab::createIndex()
{
    for(int i=0;i<indexList.size();i++)
    {
        listLayout->removeWidget(indexList[i]);
    }

    for (QList<IndexWidget*>::iterator i = indexList.begin();
         i!= indexList.end();i++)
    {
        delete *i;
    }
    indexList.clear();


    listWidget=new QWidget();
    listLayout=new QVBoxLayout();


    listWidget->setLayout(listLayout);



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

    scrollArea->setWidget(listWidget);
}

void IndexTab::sendNext()
{
    emit next();
}

void IndexTab::writeFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,tr("can not write file"),
                             tr("无法写index文件"),
                             QMessageBox::Ok);
        return;
    }

    QXmlStreamWriter xmlWriter(&file);

    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("config");

    for(int i=0;i<indexList.size();i++)
    {
        xmlWriter.writeStartElement("index");

        xmlWriter.writeTextElement("indexName",indexList[i]->getEName());
        xmlWriter.writeTextElement("type",QString::number(indexList[i]->getType()));
        xmlWriter.writeTextElement("showName",indexList[i]->getShowName());
        xmlWriter.writeTextElement("path",indexList[i]->getPath());
        xmlWriter.writeTextElement("analyzed",QString::number(indexList[i]->isParticiple()?1:0));

        xmlWriter.writeEndElement();
    }

    xmlWriter.writeEndDocument();

    file.close();
}

