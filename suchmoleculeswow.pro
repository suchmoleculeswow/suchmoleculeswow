#-------------------------------------------------
#
# Project created by QtCreator 2017-12-10T00:56:14
#
#-------------------------------------------------

QT       += core gui widgets
CONFIG   += c++14

QMAKE_CXXFLAGS += -Werror -Wextra


TARGET   = suchmoleculeswow
TEMPLATE = app

DEFINES += BOOST_LOG_DYN_LINK=1
DEFINES += BOOST_TEST_DYN_LINK=1
DEFINES += BOOST_TEST_NO_MAIN=1
#DEFINES += ENABLE_SUCH_WOW_TESTS=1

SOURCES += \
    main.cpp\
    # controllers
    src/controllers/datacontroller.cpp \
    # loaders
    src/loaders/csvloader.cpp \
    src/loaders/csvloader.h \
    src/loaders/dataloader.cpp \
    src/loaders/loaderfactory.cpp \
    # models
    src/models/datamodel.cpp \
    # ui
    src/gui/mainwindow.cpp \
    # tests
    test/csvloader_test.cpp \
    test/datamodel_test.cpp \
    test/loaderfactory_test.cpp

HEADERS  += \
    # controllers
    include/controllers/datacontroller.h \
    include/controllers/datacontroller.inl \
    # loaders
    include/loaders/dataloader.h \
    include/loaders/loaderfactory.h \
    # models
    include/models/datamodel.h \
    # ui
    src/gui/mainwindow.h

FORMS       += src/gui/mainwindow.ui

INCLUDEPATH += $$PWD/include

LIBS        += -lboost_system -lboost_unit_test_framework  -lboost_filesystem -lboost_log
