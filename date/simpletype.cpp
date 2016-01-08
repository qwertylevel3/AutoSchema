#include "simpletype.h"

SimpleType::SimpleType()
{

}

SimpleType *SimpleType::clone()
{
    SimpleType* d=new SimpleType();
    d->setName(this->getName());
    for(int i=0;i<annotation.size();i++)
    {
        d->addAnnotation(annotation.at(i));
    }
    d->setText(this->text());
    d->setCheckable(this->isCheckable());
    return d;
}

