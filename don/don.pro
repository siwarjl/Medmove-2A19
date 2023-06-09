QT       += core gui
QT       += sql
QT += printsupport
QT       += network
QT += core gui serialport
QT       += core gui sql multimedia multimediawidgets charts
QT += charts

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
    agenda.cpp \
    ard.cpp \
    arduino.cpp \
    chatbox.cpp \
    connection.cpp \
    donc.cpp \
    dons.cpp \
    dumessengerconnectiondialog.cpp \
    main.cpp \
    mainwindow.cpp \
    stat_combo.cpp \
    tache.cpp

HEADERS += \
    agenda.h \
    ard.h \
    arduino.h \
    chatbox.h \
    connection.h \
    donc.h \
    dons.h \
    dumessengerconnectiondialog.h \
    mainwindow.h \
    stat_combo.h \
    tache.h

FORMS += \
    agenda.ui \
    chatbox.ui \
    dons.ui \
    dumessengerconnectiondialog.ui \
    mainwindow.ui \
    stat_combo.ui \
    tache.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
