#include "xsdanalyser.h"
#include<QFile>
#include<QDebug>
#include"date/alldatetype.h"
#include<QStack>

XsdAnalyser::XsdAnalyser()
{
    init();
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

    init();

    QStack<QString> stack;
    stack.push(QString("element"));

    while(!reader.atEnd())
    {
        reader.readNextStartElement();
        QString temp=reader.name().toString();

        QString top=stack.top();

        if(temp==stack.top())
        {
            stack.pop();
            if(temp=="element"
                    ||temp=="complexType"
                    ||temp=="simpleType")
                p=static_cast<Date*>(p->parent());
        }
        else
        {
            stack.push(temp);
            parse(temp,p);
        }
    }



    file.close();
    return true;
}

void XsdAnalyser::init()
{
    if(model)
    {
        delete model;
    }
    if(root)
    {
        delete root;
    }
    model=new QStandardItemModel();
    root=new Date();
    model->appendRow(root);
    p=root;
}

bool XsdAnalyser::analyseComplexType(Date *parent)
{
    CompletxType* t=new CompletxType();
    t->setName(reader.attributes().value("name").toString());
    t->setText(t->getName());
    parent->addChild(t);

    p=t;

    return true;
}

bool XsdAnalyser::analyseSimpleType(Date *parent)
{
    SimpleType* t=new SimpleType();
    t->setName(reader.attributes().value("name").toString());
    t->setText(t->getName());

    parent->addChild(t);

    p=t;

    return true;
}

bool XsdAnalyser::analyseElement(Date* parent)
{
    Element* t=new Element();
    t->setName(reader.attributes().value("name").toString());
    t->setId(reader.attributes().value("id").toString());
    t->setType(reader.attributes().value("type").toString());
    t->setText(t->getName());
    parent->addChild(t);

    p=t;

    return true;
}

bool XsdAnalyser::parse(const QString &type, Date *parent)
{
    if(type=="complexType")
    {
        if(!analyseComplexType(parent))
        {
            qDebug()<<"analyse complexType fail"<<endl;
            return false;
        }
    }
    else if(type=="simpleType")
    {
        if(!analyseSimpleType(parent))
        {
            qDebug()<<"analyse simpleType fail"<<endl;
            return false;
        }
    }
    else if(type=="element")
    {
        if(!analyseElement(parent))
        {
            qDebug()<<"analyse element fail"<<endl;
            return false;
        }
    }
    return true;
}
