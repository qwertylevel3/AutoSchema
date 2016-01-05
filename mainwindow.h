#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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


    QMenu* fileMenu;

    QAction* openAction;
    QAction* exitAction;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
