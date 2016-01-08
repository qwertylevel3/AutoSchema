#include "completxtype.h"

CompletxType::CompletxType()
{

}

CompletxType *CompletxType::clone()
{
    CompletxType* d=new CompletxType();
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

