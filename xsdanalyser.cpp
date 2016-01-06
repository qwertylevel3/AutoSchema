#include "xsdanalyser.h"
#include<QFile>
#include<QDebug>
#include"date/alldatetype.h"
#include<QStack>

XsdAnalyser::XsdAnalyser()
{
    model=new QStandardItemModel();
    root=new Date(0);
    p=root;
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
                p=p->getParent();
        }
        else
        {
            stack.push(temp);
            parse(temp,p);
        }
    }

    QStandardItem* itemRoot=model->invisibleRootItem();

    buildTreeModel(root,itemRoot);

    file.close();
    return true;
}

bool XsdAnalyser::analyseComplexType(Date *parent)
{
    CompletxType* t=new CompletxType(parent);
    t->setName(reader.attributes().value("name").toString());

    parent->addChild(t);

    p=t;

    return true;
}

bool XsdAnalyser::analyseSimpleType(Date *parent)
{
    SimpleType* t=new SimpleType(parent);
    t->setName(reader.attributes().value("name").toString());

    parent->addChild(t);

    p=t;

    return true;
}

bool XsdAnalyser::analyseElement(Date* parent)
{
    Element* t=new Element(parent);
    t->setName(reader.attributes().value("name").toString());
    t->setId(reader.attributes().value("id").toString());
    t->setType(reader.attributes().value("type").toString());

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

void XsdAnalyser::buildTreeModel(Date *root, QStandardItem *itemRoot)
{
    for(int i=0;i<root->getChild().size();i++)
    {
        Date* t=root->getChild().at(i);
        QStandardItem *item = new QStandardItem(QString(t->getName()));
        item->setCheckable(true);
        itemRoot->appendRow(item);

        buildTreeModel(t,item);
    }
}
