#ifndef RESULTTAB_H
#define RESULTTAB_H

#include <QWidget>
#include<xsdanalyser.h>

class ResultTab : public QWidget
{
    Q_OBJECT
public:
    explicit ResultTab(XsdAnalyser* a,QWidget *parent = 0);

signals:

public slots:
protected:
    XsdAnalyser* analyser;
};

#endif // RESULTTAB_H
