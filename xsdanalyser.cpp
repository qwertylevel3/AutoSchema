#include "xsdanalyser.h"
#include<QFile>
#include<QDebug>
#include"date/alldatetype.h"
#include<QStack>
#include<QQueue>

XsdAnalyser::XsdAnalyser()
{
    model=0;
    root=0;

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

QStandardItemModel *XsdAnalyser::getIndexModel()
{
    setIndexCheckState(root);
    setIndexShowState(root);
    return model;
}

QStandardItemModel *XsdAnalyser::getResultModel()
{
    setResultCheckState(root);
    setResultShowState(root);
    return model;
}

void XsdAnalyser::updateIndexDate()
{
    updateIndex(root);
}

void XsdAnalyser::updateResultDate()
{
    updateResult(root);
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

void XsdAnalyser::setIndexCheckState(Date *r)
{
    if(r->isIndexChecked() && r->isCheckable())
    {
        r->setCheckState(Qt::Checked);

    }
    else if(r->isCheckable())
    {
        r->setCheckState(Qt::Unchecked);
    }

    for(int i=0;i<r->rowCount();i++)
    {
        setIndexCheckState(static_cast<Date*>(r->child(i)));
    }
}

void XsdAnalyser::setIndexShowState(Date *r)
{
    r->setEnabled(true);
    for(int i=0;i<r->rowCount();i++)
    {
        setIndexShowState(static_cast<Date*>(r->child(i)));
    }
}

void XsdAnalyser::setResultCheckState(Date *r)
{
    if(r->isResultChecked() && r->isCheckable())
    {
        r->setCheckState(Qt::Checked);
    }
    else if(r->isCheckable())
    {
        r->setCheckState(Qt::Unchecked);
    }

    for(int i=0;i<r->rowCount();i++)
    {
        setResultCheckState(static_cast<Date*>(r->child(i)));
    }
}

void XsdAnalyser::setResultShowState(Date *r)
{
    if(r->isIndexChecked())
    {
        r->setEnabled(true);
    }
    else if(r->isCheckable())
    {
        r->setEnabled(false);
    }
    for(int i=0;i<r->rowCount();i++)
    {
        setResultShowState(static_cast<Date*>(r->child(i)));
    }
}

//从index页离开时更新
void XsdAnalyser::updateIndex(Date *r)
{
    if(r->checkState()==Qt::Checked && r->isCheckable())
    {
        r->indexCheck(true);
    }
    else if(r->isCheckable())
    {
        r->indexCheck(false);
    }
    for(int i=0;i<r->rowCount();i++)
    {

        updateIndex(static_cast<Date*>(r->child(i)));
    }
}
//从result页离开时更新
void XsdAnalyser::updateResult(Date *r)
{
    if(r->checkState()==Qt::Checked
            && r->isEnabled()
            && r->isCheckable())
    {
        r->resultCheck(true);
    }
    else
    {
        r->resultCheck(false);
    }
    for(int i=0;i<r->rowCount();i++)
    {
        updateResult(static_cast<Date*>(r->child(i)));
    }
}

