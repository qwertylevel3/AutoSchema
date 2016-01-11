#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QXmlSchema>
#include<xsdanalyser.h>
#include<QTabWidget>
#include"indextab.h"
#include"resulttab.h"
#include"showdetailtab.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void open();

    void indexToResult();
    void resultToShowDetail();
    void resultToindex();
    void showDetailToResult();

    void complete();
private:
    void createActions();
    void createMenus();

    bool parseXsd(const QString& fileName);

    //设置那个tab页可见
    void setTab(int index);

    QMenu* fileMenu;

    QAction* openAction;
    QAction* exitAction;

    //3个tab页
    QTabWidget* tabWidget;
    IndexTab* indexTab;
    ResultTab* resultTab;
    ShowDetailTab* showDetailTab;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
