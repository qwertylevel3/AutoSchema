#ifndef DATE_H
#define DATE_H

#include<QList>
#include<QStandardItem>

class Date:public QStandardItem
{
public:
    Date();
    ~Date();

    QString getName(){return name;}
    QList<QString>& getAnnotation(){return annotation;}
    bool isIndexChecked(){return indexChecked;}
    bool isResultChecked(){return resultChecked;}
    int getTableNo(){return tableNo;}

    void setName(const QString& n){name=n;}
    void addAnnotation(const QString& a){annotation.push_back(a);}
    void addChild(Date* d){appendRow(d);}
    void indexCheck(bool c);
    void resultCheck(bool c);
    void setTableNo(int n){tableNo=n;}
protected:
    QString name;
    QList<QString> annotation;
    bool indexChecked;
    bool resultChecked;
    int tableNo;
};

#endif // DATE_H
