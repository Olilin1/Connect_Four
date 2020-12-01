TEMPLATE = app TARGET = name_of_the_app

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += $$PWD/../shared_files

SOURCES += \
    gamewindow.cpp \
    main.cpp \
    ../shared_files/*.cpp

HEADERS += \
    gamewindow.h \
    gameLibrary.hpp
