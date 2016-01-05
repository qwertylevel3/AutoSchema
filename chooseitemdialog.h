#ifndef CHOOSEITEMDIALOG_H
#define CHOOSEITEMDIALOG_H

#include <QDialog>

namespace Ui {
class ChooseItemDialog;
}

class ChooseItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseItemDialog(QWidget *parent = 0);
    ~ChooseItemDialog();

private:
    Ui::ChooseItemDialog *ui;
};

#endif // CHOOSEITEMDIALOG_H
