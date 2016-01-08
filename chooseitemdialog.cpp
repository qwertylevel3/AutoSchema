#include "chooseitemdialog.h"
#include "ui_chooseitemdialog.h"
#include<date/date.h>
#include<QDebug>

ChooseItemDialog::ChooseItemDialog(XsdAnalyser *a, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseItemDialog)
{
    analyser=a;
    ui->setupUi(this);

    setOriginModel();

    connect(ui->buttonBox,SIGNAL(accepted()),
            this,SLOT(createModel()));
}

ChooseItemDialog::~ChooseItemDialog()
{
    delete ui;
}

void ChooseItemDialog::setOriginModel()
{
    originRoot=analyser->clone();
    originModel=new QStandardItemModel;
    originModel->appendRow(originRoot);
    ui->treeView->setModel(originModel);
}

QStandardItemModel *ChooseItemDialog::getModel()
{
    return model;
}


void ChooseItemDialog::createModel()
{
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
