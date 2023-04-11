QT       += core gui
QT       += sql
QT += printsupport
QT       += network
QT += core gui serialport
QT       += core gui sql multimedia multimediawidgets charts
QT += charts
QT += axcontainer
QT       += core gui printsupport network widgets multimediawidgets axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    auth.cpp \
    connection.cpp \
    employe.cpp \
    employec.cpp \
    localisation.cpp \
    main.cpp \
    mainwindow.cpp \
    stat_combo.cpp \
    tache.cpp

HEADERS += \
    auth.h \
    connection.h \
    employe.h \
    employec.h \
    localisation.h \
    mainwindow.h \
    stat_combo.h \
    tache.h

FORMS += \
    auth.ui \
    employe.ui \
    localisation.ui \
    mainwindow.ui \
    stat_combo.ui \
    tache.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

DISTFILES += \
    ../../Images/325133762_1179173306066426_1465857555037161676_n (1).png
