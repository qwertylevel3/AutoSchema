#ifndef SHOWDETAILTAB_H
#define SHOWDETAILTAB_H

#include <QWidget>
#include"xsdanalyser.h"

class ShowDetailTab : public QWidget
{
    Q_OBJECT
public:
    explicit ShowDetailTab(XsdAnalyser* a,QWidget *parent = 0);

signals:

public slots:
protected:
    XsdAnalyser* analyser;
};

#endif // SHOWDETAILTAB_H
