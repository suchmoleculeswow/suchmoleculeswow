#-------------------------------------------------
#
# Project created by QtCreator 2017-12-10T00:56:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = suchmoleculeswow
TEMPLATE = app

DEFINES += BOOST_TEST_DYN_LINK=1
DEFINES += BOOST_TEST_NO_MAIN=1
#DEFINES += ENABLE_SUCH_WOW_TESTS=1

SOURCES += main.cpp\
        mainwindow.cpp \
    datamodel.cpp \
    datamodel_test.cpp

HEADERS  += mainwindow.h \
    datamodel.h

FORMS    += mainwindow.ui

LIBS += -lboost_system -lboost_unit_test_framework
