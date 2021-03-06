#ifndef XSDANALYSER_H
#define XSDANALYSER_H

#include<QXmlStreamReader>
#include<QStandardItemModel>
#include<singleton.h>

class Date;

class XsdAnalyser:public Singleton<XsdAnalyser>
{
public:
    XsdAnalyser();
    //分析某个xsd文件
    bool analyse(const QString& fileName);

    //clone一个数据树
    Date *clone();

    //根据checkstatus创建选择的element的list
    QStandardItemModel *getTable();

    int getVersion(){return version;}
protected:
    void init();

    //统一设置每个数据项的路径属性
    void setDatePath(Date* r);

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

    //版本号，用于和chooseItemDialog同步
    int version;
};

#endif // XSDANALYSER_H
