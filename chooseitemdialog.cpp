#include "chooseitemdialog.h"
#include "ui_chooseitemdialog.h"
#include<date/date.h>
#include<QDebug>

ChooseItemDialog::ChooseItemDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseItemDialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox,SIGNAL(accepted()),
            this,SLOT(createModel()));
    root=0;
    model=0;

    version=0;
}

ChooseItemDialog::~ChooseItemDialog()
{
    delete ui;
}

void ChooseItemDialog::setOriginModel()
{
    originRoot=XsdAnalyser::instance()->clone();

    originModel=new QStandardItemModel;
    originModel->appendRow(originRoot);
    //qDebug()<<originRoot->text()<<endl;
    ui->treeView->setModel(originModel);
    ui->treeView->setHeaderHidden(true);

    //每次clone数据时更新版本
    version=XsdAnalyser::instance()->getVersion();
}

QStandardItemModel *ChooseItemDialog::getModel()
{
    return model;
}

int ChooseItemDialog::exec()
{
    //如果发现版本落后于Analyser（Analyser读入了新xsd文件）,重新克隆数据树
    if(version!=XsdAnalyser::instance()->getVersion())
    {
        setOriginModel();
    }

    return QDialog::exec();
}


void ChooseItemDialog::createModel()
{
    if(root)
    {
        delete root;
    }
    if(model)
    {
        delete model;
    }

    root=new Date();
    model=new QStandardItemModel();


    createModel(originRoot);
}

void ChooseItemDialog::createModel(Date *ori)
{
    for(int i=0;i<ori->rowCount();i++)
    {
        if(!ori->child(i)->isCheckable() ||
                (ori->child(i)->isCheckable() &&
                    ori->child(i)->checkState()==Qt::Checked))
        {
            Date* temp=static_cast<Date*>(ori->child(i))->clone();
            if(ori->child(i)->isCheckable())
            {
                model->appendRow(temp);
            }
            createModel(static_cast<Date*>(ori->child(i)));
        }
    }
}
