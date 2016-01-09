#include "resultwidget.h"

ResultWidget::ResultWidget(QWidget *parent) :
    QWidget(parent)
{
    checkBox=new QCheckBox();
    indexNameLabel=new QLabel();
    showNameLineEdit=new QLineEdit();
    showDetailComboBox=new QComboBox();

    setShowDetailComboBox();

    layout=new QHBoxLayout();
    layout->addWidget(checkBox);
    layout->addWidget(indexNameLabel);
    layout->addWidget(showNameLineEdit);
    layout->addWidget(showDetailComboBox);
}

void ResultWidget::setShowDetailComboBox()
{
    showDetailComboBox->insertItem(0,"其他项");
    showDetailComboBox->insertItem(1,"标题显示");
    showDetailComboBox->insertItem(2,"联系方式");
    showDetailComboBox->insertItem(3,"块视图");
    showDetailComboBox->insertItem(4,"在线地址");
}

