#ifndef XSDANALYSER_H
#define XSDANALYSER_H

#include<QXmlStreamReader>
#include<QStandardItemModel>

class Date;

class XsdAnalyser
{
public:
    XsdAnalyser();
    bool analyse(const QString& fileName);
    QStandardItemModel* getModel(){return model;}
protected:
    bool analyseComplexType(Date* parent);
    bool analyseSimpleType(Date* parent);
    bool analyseElement(Date* parent);
    bool parse(const QString& type,Date* parent);

    void buildTreeModel(Date* root,QStandardItem* itemRoot);

    Date* root;
    Date* p;
    Date* current;
    QStandardItemModel* model;
    QXmlStreamReader reader;

};

#endif // XSDANALYSER_H
