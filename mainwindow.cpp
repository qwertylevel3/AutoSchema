#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QDebug>
#include<QXmlStreamReader>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createActions();
    createMenus();

    setTab(0);

    connect(ui->indexToResultButton,SIGNAL(clicked(bool)),
            this,SLOT(indexToResult()));
    connect(ui->resultToShowDetailButton,SIGNAL(clicked(bool)),
            this,SLOT(resultToShowDetail()));
    connect(ui->resultToIndexButton,SIGNAL(clicked(bool)),
            this,SLOT(resultToindex()));
    connect(ui->showDetailToResultButton,SIGNAL(clicked(bool)),
            this,SLOT(showDetailToResult()));
    connect(ui->completeButton,SIGNAL(clicked(bool)),
            this,SLOT(complete()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    QString fileName=QFileDialog::getOpenFileName(this,
                                                  tr("打开xsd文件"),".",
                                                  tr("xsd files(*.xsd)"));
    if(!fileName.isEmpty())
    {
        parseXsd(fileName);

        ui->treeView->setModel(analyser.getIndexModel());
    }
}

void MainWindow::indexToResult()
{
    analyser.updateIndexDate();
    setTab(1);
    ui->resultTreeView->setModel(analyser.getResultModel());
}

void MainWindow::resultToShowDetail()
{
    analyser.updateResultDate();
    setTab(2);
}

void MainWindow::resultToindex()
{
    analyser.updateResultDate();
    setTab(0);
    ui->treeView->setModel(analyser.getIndexModel());
}

void MainWindow::showDetailToResult()
{
    setTab(1);
}

void MainWindow::complete()
{

}

void MainWindow::createActions()
{
    openAction=new QAction(tr("&Open"),this);
    openAction->setIcon(QIcon(":/resource/open.png"));
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("打开xsd文件"));
    connect(openAction,SIGNAL(triggered(bool)),this,SLOT(open()));

    exitAction=new QAction(tr("&Exit"),this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("退出"));
    connect(exitAction,SIGNAL(triggered(bool)),this,SLOT(close()));
}

void MainWindow::createMenus()
{
    fileMenu=ui->menuBar->addMenu(tr("&File"));
    fileMenu->addAction(openAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);
}

bool MainWindow::parseXsd(const QString &fileName)
{
    analyser.analyse(fileName);
    return true;
}

void MainWindow::setTab(int index)
{
    if(index<0 || index >2)
    {
        return;
    }
    ui->mainTableWidget->setTabEnabled(0,false);
    ui->mainTableWidget->setTabEnabled(1,false);
    ui->mainTableWidget->setTabEnabled(2,false);

    ui->mainTableWidget->setTabEnabled(index,true);
    ui->mainTableWidget->setCurrentIndex(index);


}
