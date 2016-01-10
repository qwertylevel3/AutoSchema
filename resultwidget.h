#ifndef RESULTWIDGET_H
#define RESULTWIDGET_H

#include <QWidget>
#include"xsdanalyser.h"
#include<QCheckBox>
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
#include<QLayout>

class ResultWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ResultWidget(QWidget *parent = 0);

    void setIndexName(const QString& name){indexNameLabel->setText(name);}
    void setShowName(const QString& name){showNameLabel->setText(name);}

    void setShowDetailComboBox();

    QString getIndexName(){return indexNameLabel->text();}
    bool isChecked(){return checkBox->isChecked();}
    QString getShowName(){return showNameLabel->text();}
    int getShowDetail(){return showDetailComboBox->currentIndex();}
signals:

public slots:
protected:
    QCheckBox *checkBox;
    QLabel* indexNameLabel;
    QLabel* showNameLabel;
    QComboBox* showDetailComboBox;
    QHBoxLayout* layout;
};

#endif // RESULTWIDGET_H
