#include "date.h"

Date::Date()
{
    setCheckable(false);
}

Date::~Date()
{
}

Date *Date::clone()
{
    Date* d=new Date();
    d->setName(this->getName());
    for(int i=0;i<annotation.size();i++)
    {
        d->addAnnotation(annotation.at(i));
    }
    d->setText(this->text());
    d->setCheckable(this->isCheckable());
    d->setPath(this->getPath());

    return d;
}

void Date::setPath()
{
    Date* p=this;
    while(p->parent())
    {
        QString temp=static_cast<Date*>(p->parent())->getName();

        temp=QString("/")+temp;
        path=temp+path;
        p=static_cast<Date*>(p->parent());
    }

    path.append("/");
    path.append(this->getName());
}
