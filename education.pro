#-------------------------------------------------
#
# Project created by QtCreator 2015-06-14T19:48:02
#
#-------------------------------------------------

QT       += core gui sql
QT += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = education
TEMPLATE = app


SOURCES += main.cpp\
    students.cpp \
    teachers.cpp \
    qcustomplot.cpp \
    management.cpp \
    coursedata.cpp \
    login.cpp \
    studentdata.cpp \
    amend.cpp \
    adddata.cpp

HEADERS  += \
    students.h \
    teachers.h \
    qcustomplot.h \
    management.h \
    coursedata.h \
    login.h \
    studentdata.h \
    amend.h \
    adddata.h

FORMS    += \
    students.ui \
    teachers.ui \
    coursedata.ui \
    login.ui \
    studentdata.ui \
    amend.ui \
    adddata.ui
