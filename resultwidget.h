#ifndef RESULTWIDGET_H
#define RESULTWIDGET_H

#include <QWidget>
#include"xsdanalyser.h"
#include<QCheckBox>
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
#include<QLayout>



class ResultWidget
{
public:
    ResultWidget();

    void setIndexName(const QString& name);
    void setShowName(const QString& name);
    void setType(int t){type=t;}
    void setShowDetailComboBox();

    QString getIndexName(){return indexNameLineEdit->text();}
    bool isChecked(){return checkBox->isChecked();}
    QString getShowName(){return showNameLineEdit->text();}
    int getShowDetail(){return showDetailComboBox->currentIndex();}
    int getType(){return type;}

    QCheckBox* getCheckBox(){return checkBox;}
    QLineEdit* getIndexNameLineEdit(){return indexNameLineEdit;}
    QLineEdit* getShowNameLineEdit(){return showNameLineEdit;}
    QComboBox* getShowDetailComboBox(){return showDetailComboBox;}
protected:
    QCheckBox *checkBox;
    QLineEdit* indexNameLineEdit;
    QLineEdit* showNameLineEdit;
    QComboBox* showDetailComboBox;
    int type;
};

#endif // RESULTWIDGET_H
