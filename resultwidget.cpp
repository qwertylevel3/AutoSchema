#include "resultwidget.h"

ResultWidget::ResultWidget(QWidget *parent) :
    QWidget(parent)
{
    checkBox=new QCheckBox();
    indexNameLabel=new QLabel();
    indexNameLabel->setText("indexName:");
    indexNameLineEdit=new QLineEdit();
    showNameLabel=new QLabel();
    showNameLabel->setText("showName:");
    showNameLineEdit=new QLineEdit();
    showDetailLabel=new QLabel();
    showDetailLabel->setText("showDetail:");
    showDetailComboBox=new QComboBox();

    setShowDetailComboBox();

    layout=new QHBoxLayout();
    layout->addWidget(checkBox);
    layout->addWidget(indexNameLabel);
    layout->addWidget(indexNameLineEdit);
    layout->addWidget(showNameLabel);
    layout->addWidget(showNameLineEdit);
    layout->addWidget(showDetailLabel);
    layout->addWidget(showDetailComboBox);

    this->setLayout(layout);
}

void ResultWidget::setIndexName(const QString &name)
{
    indexNameLineEdit->setText(name);
    indexNameLineEdit->setReadOnly(true);
}

void ResultWidget::setShowName(const QString &name)
{
    showNameLineEdit->setText(name);
    showNameLineEdit->setReadOnly(true);
}

void ResultWidget::setShowDetailComboBox()
{
    showDetailComboBox->insertItem(0,"0:其他项");
    showDetailComboBox->insertItem(1,"1:标题显示");
    showDetailComboBox->insertItem(2,"2:联系方式");
    showDetailComboBox->insertItem(3,"3:块视图");
    showDetailComboBox->insertItem(4,"4:在线地址");
}

