#include "indexwidget.h"

IndexWidget::IndexWidget(QWidget *parent) : QWidget(parent)
{
    eNameLabel=new QLabel();
    cNameLabel=new QLabel();
    pathLabel=new QLabel();
    typeComboBox=new QComboBox();
    showNameLineEdit=new QLineEdit();
    participleCheckBox=new QCheckBox();

    setTypeComboBox();

    layout=new QHBoxLayout(this);
    layout->addWidget(eNameLabel);
    layout->addWidget(cNameLabel);
    layout->addWidget(pathLabel);
    layout->addWidget(typeComboBox);
    layout->addWidget(showNameLineEdit);
    layout->addWidget(participleCheckBox);
}

void IndexWidget::setENameLabel(const QString &name)
{
    eNameLabel->setText(name);
}

void IndexWidget::setCNameLabel(const QString &name)
{
    cNameLabel->setText(name);
}

void IndexWidget::setPathLabel(const QString &path)
{
    pathLabel->setText(path);
}

void IndexWidget::setTypeComboBox()
{
    typeComboBox->insertItem(0,"org");
    typeComboBox->insertItem(1,"String");
    typeComboBox->insertItem(2,"Integer");
    typeComboBox->insertItem(3,"double");
    typeComboBox->insertItem(4,"date");
}

