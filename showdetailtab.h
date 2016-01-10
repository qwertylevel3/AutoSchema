#ifndef SHOWDETAILTAB_H
#define SHOWDETAILTAB_H

#include <QWidget>
#include"xsdanalyser.h"
#include"showdetailwidget.h"


class ShowDetailTab : public QWidget
{
    Q_OBJECT
public:
    explicit ShowDetailTab(XsdAnalyser* a,QWidget *parent = 0);
signals:
    void previous();
    void complete();
public slots:
    void addTable();
    void deleteTable();
    void sendPrevious();
    void sendComplete();
    void writeFile(const QString& fileName);
protected:
    XsdAnalyser* analyser;
    QLineEdit* tableNameLineEdit;
    QCommandLinkButton* addTableLinkButton;
    QCommandLinkButton* deleteTableLinkButton;
    QCommandLinkButton* previousLinkButton;
    QCommandLinkButton* completeLinkButton;
    QTabWidget* tabWidget;
};


#endif // SHOWDETAILTAB_H
