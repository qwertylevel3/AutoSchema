#ifndef CHOOSEITEMDIALOG_H
#define CHOOSEITEMDIALOG_H

#include <QDialog>
#include<QStandardItemModel>
#include"xsdanalyser.h"

namespace Ui {
class ChooseItemDialog;
}

class ChooseItemDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ChooseItemDialog(XsdAnalyser* a, QWidget *parent = 0);
    ~ChooseItemDialog();
    //获得新数据
    QStandardItemModel *getModel();
    void setAnalyser(XsdAnalyser* a){analyser=a;}
private slots:
    //根据选择生成新数据
    void createModel();
private:
    //帮助函数,供createModel()调用
    void createModel(Date* ori);
    //生成数据树副本
    void setOriginModel();

    XsdAnalyser* analyser;

    //根据选择生成的数据
    Date* root;
    QStandardItemModel* model;

    //原数据树副本
    Date* originRoot;
    QStandardItemModel* originModel;

    Ui::ChooseItemDialog *ui;
};

#endif // CHOOSEITEMDIALOG_H
