#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QXmlSchema>
#include<xsdanalyser.h>

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
private:
    void createActions();
    void createMenus();
    bool parseXsd(const QString& fileName);


    QMenu* fileMenu;

    QAction* openAction;
    QAction* exitAction;

    XsdAnalyser analyser;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
