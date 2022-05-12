QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += \
    ../Headers/ \
    ../Headers/Algorithms/ \
    ../Headers/GanttChart/ \
    ../Headers/Exceptions

HEADERS += ../Headers/Process.h
HEADERS += ../Headers/Exceptions/ProcessInvalidException.h

SOURCES +=  tst_test1.cpp
SOURCES += ../Sources/Process.cpp
SOURCES += ../Sources/Exceptions/ProcessInvalidException.cpp
