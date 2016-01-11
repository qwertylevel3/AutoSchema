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
    explicit IndexTab(QWidget *parent = 0);
    QList<IndexWidget*>& getList(){return indexList;}
signals:
    void next();
public slots:
    void createIndex();
    void sendNext();
    void writeFile(const QString& fileName);
protected:
    void addTitle();
    QStandardItemModel* model;

    QLineEdit* eNameLabel;
    QLineEdit* cNameLabel;
    QLineEdit* pathLabel;
    QLineEdit* typeLabel;
    QLineEdit* showNameLabel;
    QLineEdit* participleLabel;

    QWidget* listWidget;

    ChooseItemDialog* dialog;
    QGridLayout* listLayout;

    QList<IndexWidget*> indexList;
    QScrollArea* scrollArea;
    QCommandLinkButton* nextButton;
    QCommandLinkButton* chooseItemButton;
};

#endif // INDEXTAB_H
