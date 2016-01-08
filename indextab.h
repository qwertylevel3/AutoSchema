#ifndef INDEXTAB_H
#define INDEXTAB_H

#include <QWidget>
#include<indexwidget.h>
#include<QList>
#include<QCommandLinkButton>
#include<QLayout>
#include<xsdanalyser.h>
#include<date/date.h>
#include<QScrollArea>
#include"chooseitemdialog.h"

class IndexTab : public QWidget
{
    Q_OBJECT
public:
    explicit IndexTab(XsdAnalyser* a, QWidget *parent = 0);

signals:
    void next();
public slots:
    void createIndex();
    void sendNext();
protected:
    XsdAnalyser* analyser;
    QStandardItemModel* model;

    QWidget* list;

    ChooseItemDialog* dialog;

    QList<IndexWidget*> indexList;
    QScrollArea* scrollArea;
    QCommandLinkButton* nextButton;
    QCommandLinkButton* chooseItemButton;
};

#endif // INDEXTAB_H
