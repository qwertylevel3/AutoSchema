#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QDebug>
#include<QXmlStreamReader>
#include"chooseitemdialog.h"
#include<QTableView>
#include"date/date.h"
#include"indexwidget.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createActions();
    createMenus();


    tabWidget=new QTabWidget(this);
    indexTab=new IndexTab(&analyser);
    resultTab= new ResultTab(&analyser);
    showDetailTab=new ShowDetailTab(&analyser);

    tabWidget->addTab(indexTab,"index");
    tabWidget->addTab(resultTab,"result");
    tabWidget->addTab(showDetailTab,"showDetail");

    this->setCentralWidget(tabWidget);

    setTab(0);

    connect(indexTab,SIGNAL(next()),this,SLOT(indexToResult()));
    connect(resultTab,SIGNAL(next()),this,SLOT(resultToShowDetail()));
    connect(resultTab,SIGNAL(previous()),this,SLOT(resultToindex()));
    connect(showDetailTab,SIGNAL(previous()),this,SLOT(showDetailToResult()));
    connect(showDetailTab,SIGNAL(complete()),this,SLOT(complete()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
//    QString fileName=QFileDialog::getOpenFileName(this,
//                                                  tr("打开xsd文件"),".",
//                                                  tr("xsd files(*.xsd)"));

    //debug...
    QString fileName="./2013-07-31_19_09_32.xsd";

    if(!fileName.isEmpty())
    {
        if(!parseXsd(fileName))
        {
            QMessageBox::warning(this,tr("Error"),
                                 tr("The file parse fail"),
                                 QMessageBox::Ok);
        }
    }
}

void MainWindow::indexToResult()
{
    setTab(1);
    resultTab->initResult(indexTab->getList());
}

void MainWindow::resultToShowDetail()
{
    setTab(2);
}

void MainWindow::resultToindex()
{
    setTab(0);
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
    return analyser.analyse(fileName);
}


void MainWindow::setTab(int index)
{
    if(index<0 || index >2)
    {
        return;
    }
    tabWidget->setTabEnabled(0,false);
    tabWidget->setTabEnabled(1,false);
    tabWidget->setTabEnabled(2,false);

    tabWidget->setTabEnabled(index,true);
    tabWidget->setCurrentIndex(index);

}
