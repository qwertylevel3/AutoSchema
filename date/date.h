#ifndef DATE_H
#define DATE_H

#include<QList>
#include<QStandardItem>

class Date:public QStandardItem
{
public:
    Date();
    ~Date();
    //克隆的时候checkstatus统一为false
    virtual Date *clone();

    QString getName(){return name;}
    QList<QString>& getAnnotation(){return annotation;}
    QString getPath(){return path;}

    void setName(const QString& n){name=n;}
    void addAnnotation(const QString& a){annotation.push_back(a);}
    void setPath();
    void setPath(const QString& p){path=p;}
protected:
    QString name;
    QList<QString> annotation;
    QString path;
};

#endif // DATE_H
