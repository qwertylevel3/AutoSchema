#include "indexwidget.h"

IndexWidget::IndexWidget()
{

    eNameLineEdit=new QLineEdit();
    cNameLineEdit=new QLineEdit();
    pathLineEdit=new QLineEdit();
    typeComboBox=new QComboBox();
    showNameLineEdit=new QLineEdit();
    participleCheckBox=new QCheckBox();

    setTypeComboBox();
}

void IndexWidget::setENameLabel(const QString &name)
{
    eNameLineEdit->setText(name);
    eNameLineEdit->setEnabled(false);
}

void IndexWidget::setCNameLabel(const QString &name)
{
    cNameLineEdit->setText(name);
    eNameLineEdit->setEnabled(false);
}

void IndexWidget::setPathLabel(const QString &path)
{
    pathLineEdit->setText(path);
    eNameLineEdit->setEnabled(false);
}

void IndexWidget::setShowName(const QString &name)
{
   showNameLineEdit->setText(name);
}

void IndexWidget::setTypeComboBox()
{
    typeComboBox->insertItem(0,"0:org");
    typeComboBox->insertItem(1,"1:String");
    typeComboBox->insertItem(2,"2:Integer");
    typeComboBox->insertItem(3,"3:double");
    typeComboBox->insertItem(4,"4:date");
}

