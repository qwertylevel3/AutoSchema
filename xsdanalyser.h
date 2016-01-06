#ifndef XSDANALYSER_H
#define XSDANALYSER_H

#include<QXmlStreamReader>
#include<QStandardItemModel>

class XsdAnalyser
{
public:
    XsdAnalyser();
    bool analyse(const QString& fileName);
    QStandardItemModel* getModel(){return model;}
protected:
    bool analyseComplexType();
    bool analyseSimpleType();

    QStandardItemModel* model;
    QXmlStreamReader reader;


};

#endif // XSDANALYSER_H
