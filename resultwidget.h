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

    void setIndexName(const QString& name);
    void setShowName(const QString& name);
    void setType(int t){type=t;}
    void setShowDetailComboBox();

    QString getIndexName(){return indexNameLineEdit->text();}
    bool isChecked(){return checkBox->isChecked();}
    QString getShowName(){return showNameLineEdit->text();}
    int getShowDetail(){return showDetailComboBox->currentIndex();}
    int getType(){return type;}
signals:

public slots:
protected:
    QCheckBox *checkBox;
    QLabel* indexNameLabel;
    QLineEdit* indexNameLineEdit;
    QLabel* showNameLabel;
    QLineEdit* showNameLineEdit;
    QLabel* showDetailLabel;
    QComboBox* showDetailComboBox;
    QHBoxLayout* layout;
    int type;
};

#endif // RESULTWIDGET_H
