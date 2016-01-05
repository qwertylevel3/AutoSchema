#include "chooseitemdialog.h"
#include "ui_chooseitemdialog.h"

ChooseItemDialog::ChooseItemDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseItemDialog)
{
    ui->setupUi(this);
}

ChooseItemDialog::~ChooseItemDialog()
{
    delete ui;
}
