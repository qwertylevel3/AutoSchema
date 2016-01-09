#ifndef RESULTTAB_H
#define RESULTTAB_H

#include <QWidget>
#include<xsdanalyser.h>
#include<QCommandLinkButton>
#include<Qlist>
#include"resultwidget.h"
#include<QScrollArea>

class ResultTab : public QWidget
{
    Q_OBJECT
public:
    explicit ResultTab(XsdAnalyser* a,QWidget *parent = 0);

signals:
    void next();
    void previous();
public slots:
    void createResult();
    void sendNext();
    void sendPrevious();
protected:
    XsdAnalyser* analyser;

    QWidget* list;
    QStandardItemModel* model;

    QList<ResultWidget*> resultList;
    QScrollArea* scrollArea;
    QCommandLinkButton* nextButton;
    QCommandLinkButton* previousButton;
};

#endif // RESULTTAB_H
