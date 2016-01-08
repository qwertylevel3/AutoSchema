#include "date.h"

Date::Date()
{
    setCheckable(false);
    setPath();
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
    return d;
}

void Date::setPath()
{
    while(this->parent())
    {
        QString temp=static_cast<Date*>(this->parent())->getName();
        temp=QString("/")+temp;
        path=temp+path;
    }
}
