#ifndef DATE_H
#define DATE_H

#include<QList>


class Date
{
public:
    Date(Date* p);
    ~Date();

    QString getName(){return name;}
    QList<QString>& getAnnotation(){return annotation;}
    QList<Date*>& getChild(){return child;}
    Date* getParent(){return parent;}

    void setName(const QString& n){name=n;}
    void addAnnotation(const QString& a){annotation.push_back(a);}
    void addChild(Date* d){child.push_back(d);}
    void setParent(Date* p){parent=p;}
protected:
    Date* parent;
    QString name;
    QList<QString> annotation;
    QList<Date*> child;
};

#endif // DATE_H
