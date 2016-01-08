#ifndef ELEMENT_H
#define ELEMENT_H

#include"date.h"

class Element : public Date
{
public:
    Element();
    virtual Element *clone();

    void setType(const QString& t){type=t;}
    void setId(const QString& d){id=d;}

    QString getType(){return type;}
    QString getId(){return id;}
protected:
    QString type;
    QString id;
};

#endif // ELEMENT_H
