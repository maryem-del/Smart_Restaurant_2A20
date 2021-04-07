QT       += core gui
QT       += core gui
QT += widgets multimedia
QT       += core gui sql
QT       +=core gui serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += widgets multimedia
QT += printsupport
QT +=gui
QT += widgets
DEFINES += QT_DEPRECATED_WARNINGS
TARGET = Restau.pro

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    ingredient.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    plat.cpp \
    qcustomplot.cpp \
    secdialog.cpp \
    tableprinter.cpp

HEADERS += \
    connection.h \
    ingredient.h \
    login.h \
    mainwindow.h \
    plat.h \
    qcustomplot.h \
    secdialog.h \
    tableprinter.h

FORMS += \
    login.ui \
    mainwindow.ui \
    secdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    Electric  - 5 Minute Countdown.wav
