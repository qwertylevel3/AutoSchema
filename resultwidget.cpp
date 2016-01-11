#include "resultwidget.h"

ResultWidget::ResultWidget()
{
    checkBox=new QCheckBox();
    indexNameLineEdit=new QLineEdit();
    showNameLineEdit=new QLineEdit();
    showDetailComboBox=new QComboBox();

    setShowDetailComboBox();
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

