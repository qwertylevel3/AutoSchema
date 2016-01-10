#include "indexwidget.h"

IndexWidget::IndexWidget(QWidget *parent) : QWidget(parent)
{
    eNameLabel=new QLabel();
    eNameLabel->setText("英文名称：");
    eNameLineEidt=new QLineEdit();

    cNameLabel=new QLabel();
    cNameLabel->setText("中文名称：");
    cNameLineEdit=new QLineEdit();

    pathLabel=new QLabel();
    pathLabel->setText("路径：");
    pathLineEidt=new QLineEdit();

    typeLabel=new QLabel();
    typeLabel->setText("类型：");
    typeComboBox=new QComboBox();

    showNameLabel=new QLabel();
    showNameLabel->setText("showName：");
    showNameLineEdit=new QLineEdit();

    participleLabel=new QLabel();
    participleLabel->setText("分词：");
    participleCheckBox=new QCheckBox();

    setTypeComboBox();

    layout=new QHBoxLayout(this);
    layout->addWidget(eNameLabel);
    layout->addWidget(eNameLineEidt);
    layout->addWidget(cNameLabel);
    layout->addWidget(cNameLineEdit);
    layout->addWidget(typeLabel);
    layout->addWidget(typeComboBox);
    layout->addWidget(showNameLabel);
    layout->addWidget(showNameLineEdit);
    layout->addWidget(participleLabel);
    layout->addWidget(participleLabel);
    layout->addWidget(participleCheckBox);
    layout->addWidget(pathLabel);
    layout->addWidget(pathLineEidt);
}

void IndexWidget::setENameLabel(const QString &name)
{
    eNameLineEidt->setText(name);
    eNameLineEidt->setReadOnly(true);
}

void IndexWidget::setCNameLabel(const QString &name)
{
    cNameLineEdit->setText(name);
    eNameLineEidt->setReadOnly(true);
}

void IndexWidget::setPathLabel(const QString &path)
{
    pathLineEidt->setText(path);
    eNameLineEidt->setReadOnly(true);
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

