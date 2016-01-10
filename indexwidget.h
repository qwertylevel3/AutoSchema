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
    void setShowName(const QString& name);

    void setTypeComboBox();

    QString getEName(){return eNameLineEidt->text();}
    QString getCName(){return cNameLineEdit->text();}
    QString getPath(){return pathLineEidt->text();}
    int getType(){return typeComboBox->currentIndex();}
    QString getShowName(){return showNameLineEdit->text();}
    bool isParticiple(){return participleCheckBox->checkState()==Qt::Checked?true:false;}
signals:

public slots:

protected:
    QLabel* eNameLabel;
    QLineEdit* eNameLineEidt;

    QLabel* cNameLabel;
    QLineEdit* cNameLineEdit;

    QLabel* pathLabel;
    QLineEdit* pathLineEidt;

    QLabel* typeLabel;
    QComboBox* typeComboBox;

    QLabel* showNameLabel;
    QLineEdit* showNameLineEdit;

    QLabel* participleLabel;
    QCheckBox* participleCheckBox;

    QHBoxLayout* layout;
};

#endif // INDEXWIDGET_H
