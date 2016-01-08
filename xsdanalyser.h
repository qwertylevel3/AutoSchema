#ifndef XSDANALYSER_H
#define XSDANALYSER_H

#include<QXmlStreamReader>
#include<QStandardItemModel>

class Date;

class XsdAnalyser
{
public:
    XsdAnalyser();
    //分析某个xsd文件
    bool analyse(const QString& fileName);

    //clone一个数据树
    Date *clone();

    //根据checkstatus创建选择的element的list
    QStandardItemModel *getTable();
protected:
    void init();

    //帮助函数，供getTable调用
    void createTable(Date *r);

    //帮助函数，供clone调用
    void clone(Date* origin,Date* r);

    //type为数据类型，parent为父指针
    bool parse(const QString& type, Date* parent);

    //根据type类型不同解析不同数据类型，由parse调用
    bool analyseComplexType(Date* parent);
    bool analyseSimpleType(Date* parent);
    bool analyseElement(Date* parent);
    bool analyseAnnotation(Date* parent);


    Date* current;
    //数据根
    Date* root;
    //数据model
    QStandardItemModel* model;

    QXmlStreamReader reader;
    QStandardItemModel* table;

};

#endif // XSDANALYSER_H
