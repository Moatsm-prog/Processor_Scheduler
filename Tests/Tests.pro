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
    ../Headers/Algorithms/FCFS.h \
    ../Headers/Algorithms/NonPreemptive.h \
    ../Headers/Algorithms/Preemptive.h \
    ../Headers/Algorithms/Priority_NonPreemptive.h \
    ../Headers/Algorithms/Priority_Preemptive.h \
    ../Headers/Algorithms/RoundRobin.h \
    ../Headers/Algorithms/SJF_NonPreemptive.h \
    ../Headers/Algorithms/SJF_Preemptive.h \
    ../Headers/Exceptions/QuantumInvalidException.h \
    ../Headers/TimeEntry.h \
    ../Headers/TimeLine.h
HEADERS += ../Headers/Exceptions/ProcessInvalidException.h

SOURCES +=  tst_test1.cpp \
    ../Sources/Algorithms/Algorithm.cpp \
    ../Sources/Algorithms/FCFS.cpp \
    ../Sources/Algorithms/NonPreemptive.cpp \
    ../Sources/Algorithms/Preemptive.cpp \
    ../Sources/Algorithms/Priority_NonPreemptive.cpp \
    ../Sources/Algorithms/Priority_Preemptive.cpp \
    ../Sources/Algorithms/RoundRobin.cpp \
    ../Sources/Algorithms/SJF_NonPreemptive.cpp \
    ../Sources/Algorithms/SJF_Preemptive.cpp \
    ../Sources/Exceptions/QuantumInvalidException.cpp \
    ../Sources/TimeEntry.cpp \
    ../Sources/TimeLine.cpp
SOURCES += ../Sources/Process.cpp
SOURCES += ../Sources/Exceptions/ProcessInvalidException.cpp
