#-------------------------------------------------
#
# Project created by QtCreator 2016-01-04T15:26:59
#
#-------------------------------------------------

QT       += core gui
QT	 += xml
QT	 += xmlpatterns

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AutoSchema
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chooseitemdialog.cpp \
    xsdanalyser.cpp \
    date/date.cpp \
    date/completxtype.cpp \
    date/simpletype.cpp \
    date/element.cpp \
    indexwidget.cpp \
    indextab.cpp \
    resultwidget.cpp \
    showdetailwidget.cpp \
    resulttab.cpp \
    showdetailtab.cpp \
    inputiddialog.cpp \
    tipmanager.cpp

HEADERS  += mainwindow.h \
    chooseitemdialog.h \
    xsdanalyser.h \
    date/date.h \
    date/completxtype.h \
    date/simpletype.h \
    date/element.h \
    date/alldatetype.h \
    indexwidget.h \
    indextab.h \
    resultwidget.h \
    showdetailwidget.h \
    resulttab.h \
    showdetailtab.h \
    inputiddialog.h \
    singleton.h \
    tipmanager.h

FORMS    += mainwindow.ui \
    chooseitemdialog.ui \
    inputiddialog.ui

RESOURCES += \
    resource.qrc
