#include "xsdanalyser.h"
#include<QFile>
#include<QDebug>

XsdAnalyser::XsdAnalyser()
{
    model=new QStandardItemModel();
}

bool XsdAnalyser::analyse(const QString &fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"can not open "<<fileName<<endl;
        return false;
    }

    reader.setDevice(&file);

    reader.readNext();
    while (!reader.atEnd())
    {
        if(reader.isStartElement())
        {
            qDebug()<<reader.name()<<endl;
            if(reader.name()=="complexType")
            {
                if(!analyseComplexType())
                {
                    qDebug()<<"analyse complexType fail"<<endl;
                    return false;
                }
            }
            else if(reader.name()=="simpleType")
            {
                if(!analyseSimpleType())
                {
                    qDebug()<<"analyse simpleType fail"<<endl;
                    return false;
                }
            }
            reader.readNext();
        }
        else
        {
            reader.readNext();
        }
    }
    if (reader.hasError())
    {
        qDebug()<<fileName<<" has error"<<endl;
        return false;
    }

    //test
    QStandardItem *parentItem = model->invisibleRootItem();
    for (int i = 0; i < 4; ++i)
    {
        QStandardItem *item = new QStandardItem(QString("item %0").arg(i));
        parentItem->appendRow(item);
    }
    //test

    file.close();
    return true;
}

bool XsdAnalyser::analyseComplexType()
{
    return true;
}

bool XsdAnalyser::analyseSimpleType()
{
    return true;
}

