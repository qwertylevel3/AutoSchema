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
    QStandardItemModel *getIndexModel();
    QStandardItemModel *getResultModel();
    void updateIndexDate();
    void updateResultDate();
protected:
    void init();
    bool analyseComplexType(Date* parent);
    bool analyseSimpleType(Date* parent);
    bool analyseElement(Date* parent);
    bool parse(const QString& type,Date* parent);
    void setIndexCheckState(Date* r);
    void setIndexShowState(Date* r);
    void setResultCheckState(Date* r);
    void setResultShowState(Date* r);
    void updateIndex(Date* r);
    void updateResult(Date* r);

    Date* p;
    Date* root;
    QStandardItemModel* model;
    QXmlStreamReader reader;
};

#endif // XSDANALYSER_H
