#ifndef INDEXWIDGET_H
#define INDEXWIDGET_H

#include <QWidget>
#include<QLineEdit>
#include<QLabel>
#include<QCheckBox>
#include<QComboBox>
#include<QLayout>
#include<QLayoutItem>

class IndexWidget
{
public:
    explicit IndexWidget();

    void setENameLabel(const QString& name);
    void setCNameLabel(const QString& name);
    void setPathLabel(const QString& path);
    void setShowName(const QString& name);

    void setTypeComboBox();

    QString getEName(){return eNameLineEdit->text();}
    QString getCName(){return cNameLineEdit->text();}
    QString getPath(){return pathLineEdit->text();}
    int getType(){return typeComboBox->currentIndex();}
    QString getShowName(){return showNameLineEdit->text();}
    bool isParticiple(){return participleCheckBox->checkState()==Qt::Checked?true:false;}

    QLineEdit* getENameLineEdit(){return eNameLineEdit;}
    QLineEdit* getCNameLineEdit(){return cNameLineEdit;}
    QLineEdit* getPathLineEdit(){return pathLineEdit;}
    QComboBox* getTypeComboBox(){return typeComboBox;}
    QLineEdit* getShowNameLineEdit(){return showNameLineEdit;}
    QCheckBox* getParticipleCheckBox(){return participleCheckBox;}
protected:
    QLineEdit* eNameLineEdit;

    QLineEdit* cNameLineEdit;

    QLineEdit* pathLineEdit;

    QComboBox* typeComboBox;

    QLineEdit* showNameLineEdit;

    QCheckBox* participleCheckBox;
};

#endif // INDEXWIDGET_H
