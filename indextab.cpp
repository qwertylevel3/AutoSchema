#include "indextab.h"
#include<date/element.h>
#include<QXmlStreamWriter>
#include<QFile>
#include<QMessageBox>
#include<QGridLayout>
#include<tipmanager.h>

IndexTab::IndexTab(QWidget *parent) :
    QWidget(parent)
{
    scrollArea=new QScrollArea(this);

    nextButton=new QCommandLinkButton;
    nextButton->setIcon(QIcon(QString(":/resource/next.png")));
    nextButton->setMaximumWidth(120);
    nextButton->setText(tr("下一步"));

    chooseItemButton=new QCommandLinkButton;
    chooseItemButton->setIcon(QIcon(QString(":/resource/add.png")));
    chooseItemButton->setMaximumWidth(120);
    chooseItemButton->setText(tr("添加index项"));

    QVBoxLayout* vLayout=new QVBoxLayout();
    vLayout->addWidget(chooseItemButton);
    vLayout->addStretch();
    vLayout->addWidget(nextButton);

    QHBoxLayout* hLayout=new QHBoxLayout();
    hLayout->addWidget(scrollArea);
    hLayout->addLayout(vLayout);

    listWidget=new QWidget();
    listLayout=new QGridLayout();


    addTitle();

    listWidget->setLayout(listLayout);
    scrollArea->setWidget(listWidget);

    this->setLayout(hLayout);

    connect(chooseItemButton,SIGNAL(clicked(bool)),
            this,SLOT(createIndex()));
    connect(nextButton,SIGNAL(clicked(bool)),
            this,SLOT(sendNext()));

    dialog=new ChooseItemDialog(this);
}

void IndexTab::createIndex()
{
    for(int i=0;i<indexList.size();i++)
    {
        listLayout->removeWidget(indexList[i]->getENameLineEdit());
        listLayout->removeWidget(indexList[i]->getCNameLineEdit());
        listLayout->removeWidget(indexList[i]->getTypeComboBox());
        listLayout->removeWidget(indexList[i]->getShowNameLineEdit());
        listLayout->removeWidget(indexList[i]->getParticipleCheckBox());
        listLayout->removeWidget(indexList[i]->getPathLineEdit());
    }
    listLayout->removeWidget(eNameLabel);
    listLayout->removeWidget(cNameLabel);
    listLayout->removeWidget(pathLabel);
    listLayout->removeWidget(typeLabel);
    listLayout->removeWidget(showNameLabel);
    listLayout->removeWidget(participleLabel);

    for (QList<IndexWidget*>::iterator i = indexList.begin();
         i!= indexList.end();i++)
    {
        delete *i;
    }
    indexList.clear();

    listWidget=new QWidget();
    listLayout=new QGridLayout();
    for(int i=0;i<6;i++)
    {
        listLayout->setColumnMinimumWidth(i,150);
    }

    addTitle();

    dialog->exec();
    model=dialog->getModel();
    if(model)
    {
        for(int i=0;i<model->rowCount();i++)
        {
            Element* item=static_cast<Element*>(model->item(i));
            IndexWidget* indexItem=new IndexWidget();
            indexItem->setENameLabel(item->getName());
            indexItem->setCNameLabel(item->getId());
            indexItem->setPathLabel(item->getPath());
            indexItem->setShowName(item->getId());

            QString annotation;
            for(int j=0;j<item->getAnnotation().size();j++)\
            {
                annotation.append(item->getAnnotation().at(j));
            }

            listLayout->addWidget(indexItem->getENameLineEdit(),i+1,0,1,1);
            indexItem->getENameLineEdit()->setToolTip(TipManager::instance()->getIndex_eName());
            indexItem->getENameLineEdit()->setMouseTracking(true);

            listLayout->addWidget(indexItem->getCNameLineEdit(),i+1,1,1,1);
            listLayout->addWidget(indexItem->getTypeComboBox(),i+1,2,1,1);
            listLayout->addWidget(indexItem->getShowNameLineEdit(),i+1,3,1,1);
            listLayout->addWidget(indexItem->getParticipleCheckBox(),i+1,4,1,1);
            listLayout->addWidget(indexItem->getPathLineEdit(),i+1,5,1,1);

            indexList.push_back(indexItem);
        }
        listWidget->setLayout(listLayout);
        scrollArea->setWidget(listWidget);
    }

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

void IndexTab::sendTip(QString widgetTip)
{
    emit tip(widgetTip);
}

void IndexTab::addTitle()
{
    eNameLabel=new QLineEdit();
    eNameLabel->setText("英文名称");
    eNameLabel->setEnabled(false);

    cNameLabel=new QLineEdit();
    cNameLabel->setText("中文名称");
    cNameLabel->setEnabled(false);

    pathLabel=new QLineEdit();
    pathLabel->setText("路径");
    pathLabel->setEnabled(false);

    typeLabel=new QLineEdit();
    typeLabel->setText("类型");
    typeLabel->setEnabled(false);

    showNameLabel=new QLineEdit();
    showNameLabel->setText("showName");
    showNameLabel->setEnabled(false);

    participleLabel=new QLineEdit();
    participleLabel->setText("分词");
    participleLabel->setEnabled(false);


    listLayout->addWidget(eNameLabel,0,0,1,1);
    listLayout->addWidget(cNameLabel,0,1,1,1);
    listLayout->addWidget(typeLabel,0,2,1,1);
    listLayout->addWidget(showNameLabel,0,3,1,1);
    listLayout->addWidget(participleLabel,0,4,1,1);
    listLayout->addWidget(pathLabel,0,5,1,1);

}

