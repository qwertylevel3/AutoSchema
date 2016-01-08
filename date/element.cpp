#include "element.h"

Element::Element()
{
    setCheckable(true);
}

Element *Element::clone()
{
    Element* d=new Element();
    d->setName(this->getName());
    for(int i=0;i<annotation.size();i++)
    {
        d->addAnnotation(annotation.at(i));
    }
    d->setText(this->text());
    d->setCheckable(this->isCheckable());
    d->setPath(this->getPath());

    d->setType(this->getType());
    d->setId(this->getId());

    return d;
}

