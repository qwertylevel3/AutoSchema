#include "inputiddialog.h"
#include "ui_inputiddialog.h"

InputIDDialog::InputIDDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputIDDialog)
{
    ui->setupUi(this);
}

InputIDDialog::~InputIDDialog()
{
    delete ui;
}

QString InputIDDialog::getID()
{
    return ui->lineEdit->text();
}
