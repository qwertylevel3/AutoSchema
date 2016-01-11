#ifndef RESULTTAB_H
#define RESULTTAB_H

#include <QWidget>
#include<xsdanalyser.h>
#include<QCommandLinkButton>
#include<Qlist>
#include"resultwidget.h"
#include<QScrollArea>
#include"indextab.h"

class ResultTab : public QWidget
{
    Q_OBJECT
public:
    explicit ResultTab(QWidget *parent = 0);

signals:
    void next();
    void previous();
public slots:
    void initResult(QList<IndexWidget*>& indexList);
    void sendNext();
    void sendPrevious();
    void writeFile(const QString& fileName);
protected:
    QWidget* list;
    QStandardItemModel* model;

    QList<ResultWidget*> resultList;
    QScrollArea* scrollArea;
    QCommandLinkButton* nextButton;
    QCommandLinkButton* previousButton;
};

#endif // RESULTTAB_H
