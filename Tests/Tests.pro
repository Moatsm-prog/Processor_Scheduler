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

HEADERS += ../Headers/Process.h \
    ../Headers/Algorithms/Algorithm.h \
    ../Headers/Algorithms/RoundRobin.h \
    ../Headers/Exceptions/QuantumInvalidException.h \
    ../Headers/TimeEntry.h \
    ../Headers/TimeLine.h
HEADERS += ../Headers/Exceptions/ProcessInvalidException.h

SOURCES +=  tst_test1.cpp \
    ../Sources/Algorithms/Algorithm.cpp \
    ../Sources/Algorithms/RoundRobin.cpp \
    ../Sources/Exceptions/QuantumInvalidException.cpp \
    ../Sources/TimeEntry.cpp \
    ../Sources/TimeLine.cpp
SOURCES += ../Sources/Process.cpp
SOURCES += ../Sources/Exceptions/ProcessInvalidException.cpp
