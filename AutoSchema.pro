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
    xsdanalyser.cpp

HEADERS  += mainwindow.h \
    chooseitemdialog.h \
    xsdanalyser.h

FORMS    += mainwindow.ui \
    chooseitemdialog.ui

RESOURCES += \
    resource.qrc
