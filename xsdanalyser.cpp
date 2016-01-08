#include "xsdanalyser.h"
#include<QFile>
#include<QDebug>
#include"date/alldatetype.h"
#include<QStack>
#include<QQueue>
#include<QMessageBox>

XsdAnalyser::XsdAnalyser()
{
    model=0;
    root=0;
    table=0;

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

    //读取schema项
    reader.readNextStartElement();

    //当前指针
    current=root;

    while(!reader.atEnd() && !stack.empty())
    {
        reader.readNextStartElement();
        QString temp=reader.name().toString();

        if(temp==stack.top())
        {
            stack.pop();
            if(temp=="element"
                    ||temp=="complexType"
                    ||temp=="simpleType")
            {
                current=static_cast<Date*>(current->parent());
            }
            //如果是最后一个element（根）
            if(stack.isEmpty())
            {
                root->setName(reader.attributes().value("name").toString());
            }
        }
        else
        {
            if(temp!="annotation")
            {
                stack.push(temp);
            }
            if(!parse(temp,current))
            {
                file.close();
                return false;
            }
        }
    }

    setDatePath(root);

    QMessageBox meg;
    meg.setText(QString("解析完成"));
    meg.exec();

    file.close();
    return true;
}


Date *XsdAnalyser::clone()
{
    Date* newRoot=new Date();
    clone(root,newRoot);
    return newRoot;
}

QStandardItemModel *XsdAnalyser::getTable()
{
    if(table)
    {
        delete table;
    }
    createTable(root);

    return table;
}

void XsdAnalyser::init()
{
    if(root)
    {
        delete root;
    }
    if(model)
    {
        delete model;
    }

    model=new QStandardItemModel();
    root=new Date();
    model->appendRow(root);
}

void XsdAnalyser::setDatePath(Date *r)
{
    r->setPath();
    for(int i=0;i<r->rowCount();i++)
    {
        setDatePath(static_cast<Date*>(r->child(i)));
    }
}

void XsdAnalyser::clone(Date *origin, Date *r)
{
    for(int i=0;i<origin->rowCount();i++)
    {
        Date* temp=static_cast<Date*>(origin->child(i))->clone();
        r->appendRow(temp);
        clone(static_cast<Date*>(origin->child(i)),temp);
    }
}

void XsdAnalyser::createTable(Date *r)
{
    if(r->isCheckable() && r->checkState()==Qt::Checked)
    {
        Element* element=new Element();
        element->setName(r->getName());
        element->setText(element->getName());
        table->appendRow(element);
    }
    for(int i=0;i<r->rowCount();i++)
    {
        createTable(static_cast<Date*>(r->child(i)));
    }
}

bool XsdAnalyser::analyseComplexType(Date *parent)
{
    CompletxType* t=new CompletxType();
    t->setName(reader.attributes().value("name").toString());
    t->setText(t->getName());

    parent->appendRow(t);

    current=t;

    return true;
}

bool XsdAnalyser::analyseSimpleType(Date *parent)
{
    SimpleType* t=new SimpleType();
    t->setName(reader.attributes().value("name").toString());
    t->setText(t->getName());

    parent->appendRow(t);

    current=t;

    return true;
}

bool XsdAnalyser::analyseElement(Date* parent)
{
    Element* t=new Element();
    t->setName(reader.attributes().value("name").toString());
    t->setId(reader.attributes().value("id").toString());
    t->setType(reader.attributes().value("type").toString());
    t->setText(t->getName());

    parent->appendRow(t);

    current=t;

    return true;
}

bool XsdAnalyser::analyseAnnotation(Date *parent)
{
    reader.readNextStartElement();
    while(reader.name().toString()=="documentation")
    {
        QString documentation=reader.readElementText();
        parent->addAnnotation(documentation);
        reader.readNextStartElement();
    }


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
    else if(type=="annotation")
    {
        if(!analyseAnnotation(parent))
        {
            qDebug()<<"analyse annotation fail"<<endl;
            return false;
        }
    }
    return true;
}

