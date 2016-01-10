#ifndef INPUTIDDIALOG_H
#define INPUTIDDIALOG_H

#include <QDialog>

namespace Ui {
class InputIDDialog;
}

class InputIDDialog : public QDialog
{
    Q_OBJECT
public:
    explicit InputIDDialog(QWidget *parent = 0);
    ~InputIDDialog();
    QString getID();
private:
    Ui::InputIDDialog *ui;
};

#endif // INPUTIDDIALOG_H
