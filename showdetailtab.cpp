#include "showdetailtab.h"
#include<QMessageBox>
#include<QFile>
#include<QXmlStreamWriter>


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
    QString tableName=tableNameLineEdit->text();
    if(tableName.isEmpty())
    {
        QMessageBox::warning(this,tr("error"),tr("表名不能为空"),
                             QMessageBox::Ok);
        return ;
    }
    ShowDetailTableWidget* tableWidget=new ShowDetailTableWidget(analyser);
    tabWidget->addTab(tableWidget,tableName);
}

void ShowDetailTab::deleteTable()
{
    int r=QMessageBox::warning(this,tr("delete"),tr("当前表将会被删除"),
                               QMessageBox::Ok|QMessageBox::Cancel);
    if(r==QMessageBox::Ok)
    {
        tabWidget->removeTab(tabWidget->currentIndex());
    }
}

void ShowDetailTab::sendPrevious()
{
    emit previous();
}

void ShowDetailTab::sendComplete()
{
    emit complete();
}

void ShowDetailTab::writeFile(const QString &fileName)
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
    xmlWriter.writeStartElement("show");

    for(int i=0;i<tabWidget->count();i++)
    {
        xmlWriter.writeStartElement("table");

        xmlWriter.writeTextElement("id",QString::number(i));
        xmlWriter.writeTextElement("tablename",tabWidget->tabText(i));

        xmlWriter.writeEndElement();
    }

    for(int i=0;i<tabWidget->count();i++)
    {
        ShowDetailTableWidget* table=static_cast<ShowDetailTableWidget*>(tabWidget->widget(i));

        for(int j=0;j<table->getList().size();j++)
        {
            xmlWriter.writeStartElement("detail");

            xmlWriter.writeTextElement("showid",QString::number(j));
            xmlWriter.writeTextElement("tableid",QString::number(i));
            xmlWriter.writeTextElement("name",table->getList()[j]->getName());
            xmlWriter.writeTextElement("path",table->getList()[j]->getPath());

            xmlWriter.writeEndElement();
        }

    }

    xmlWriter.writeEndDocument();

    file.close();
}


