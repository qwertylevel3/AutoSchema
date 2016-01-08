#ifndef INDEXWIDGET_H
#define INDEXWIDGET_H

#include <QWidget>
#include<QLineEdit>
#include<QLabel>
#include<QCheckBox>
#include<QComboBox>
#include<QLayout>
#include<QLayoutItem>

class IndexWidget : public QWidget
{
    Q_OBJECT
public:
    explicit IndexWidget(QWidget *parent = 0);

    void setENameLabel(const QString& name);
    void setCNameLabel(const QString& name);
    void setPathLabel(const QString& path);

    void setTypeComboBox();

    QString getEName(){return eNameLabel->text();}
    QString getCName(){return cNameLabel->text();}
    QString getPath(){return pathLabel->text();}
    int getType(){return typeComboBox->currentIndex();}
    QString getShowName(){return showNameLineEdit->text();}
    bool isParticiple(){return participleCheckBox->checkState()==Qt::Checked?true:false;}
signals:

public slots:

protected:
    QLabel* eNameLabel;
    QLabel* cNameLabel;
    QLabel* pathLabel;
    QComboBox* typeComboBox;
    QLineEdit* showNameLineEdit;
    QCheckBox* participleCheckBox;
    QHBoxLayout* layout;
};

#endif // INDEXWIDGET_H
