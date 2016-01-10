#ifndef SHOWDETAILWIDGET_H
#define SHOWDETAILWIDGET_H

#include <QWidget>
#include"xsdanalyser.h"
#include<QLabel>
#include<QLayout>
#include<QCommandLinkButton>
#include<QLineEdit>
#include<QTabWidget>
#include<QScrollArea>
#include"chooseitemdialog.h"
#include<QList>

class ShowDetailItemWidget:public QWidget
{
    Q_OBJECT
public:
    ShowDetailItemWidget(QWidget *parent = 0);

    void setNameLabel(const QString& name){nameLabel->setText(name);}
    void setPathLabel(const QString& path){pathLabel->setText(path);}

    QString getName(){return nameLabel->text();}
    QString getPath(){return pathLabel->text();}
protected:
    QLabel* nameLabel;
    QLabel* pathLabel;
};

class ShowDetailTableWidget:public QWidget
{
    Q_OBJECT
public:
    ShowDetailTableWidget(QWidget *parent = 0);
public slots:
    void createTable();
protected:
    QList<ShowDetailItemWidget*> list;

    QWidget* itemListWidget;
    QScrollArea* scrollArea;
    QCommandLinkButton* chooseItemButton;
};


#endif // SHOWDETAILWIDGET_H
