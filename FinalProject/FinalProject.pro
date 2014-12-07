#-------------------------------------------------
#
# Project created by QtCreator 2014-11-17T11:27:28
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = FinalProject
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    parser.cpp \
    AVLTree.cpp \
    indexer.cpp \
    stemmer.cpp \
    query.cpp \
    pages.cpp \
    driver.cpp

HEADERS += \
    parser.h \
    AVLTree.h \
    indexer.h \
    query.h \
    pages.h \
    driver.h
