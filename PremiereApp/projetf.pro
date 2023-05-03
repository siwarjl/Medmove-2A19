QT       += core gui printsupport multimedia serialport  multimediawidgets
QT  += svg
QT += network
QT       +=sql \
            quick
QT += printsupport
QT += charts

QT += axcontainer

QT  += core network
QT -= gui
QT       += core gui
QT       += core gui charts
QT       += core gui  serialport
QT       += core gui printsupport network widgets multimediawidgets axcontainer
QT       += core gui sql multimedia multimediawidgets charts
QT       += core gui

QT *= network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += static

CONFIG += c++11 console
CONFIG -= app_bundle
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
    ambulance.cpp \
    ambulancec.cpp \
    ard.cpp \
    arduino.cpp \
    arduino1.cpp \
    arduinoambulance.cpp \
    auth.cpp \
    blocnote.cpp \
    calculatrice.cpp \
    camera.cpp \
    chatbox.cpp \
    client.cpp \
    connection.cpp \
    dialog.cpp \
    dumessengerconnectiondialog.cpp \
    employe.cpp \
    employec.cpp \
    historique.cpp \
    home.cpp \
    image.cpp \
    localisation.cpp \
    main.cpp \
    mainwindow.cpp \
    patient.cpp \
    patientarduinoc.cpp \
    produit.cpp \
    produitang.cpp \
    produitc.cpp \
    qrcode.cpp \
    smtp.cpp \
    stat_combo.cpp \
    stat_combop.cpp \
    statistique.cpp \
    tache.cpp \
    tacheeng.cpp

HEADERS += \
    ambulance.h \
    ambulancec.h \
    ard.h \
    arduino.h \
    arduino1.h \
    arduinoambulance.h \
    auth.h \
    blocnote.h \
    calculatrice.h \
    camera.h \
    chatbox.h \
    client.h \
    connection.h \
    dialog.h \
    dumessengerconnectiondialog.h \
    employe.h \
    employec.h \
    historique.h \
    home.h \
    image.h \
    localisation.h \
    mainwindow.h \
    patient.h \
    patientarduinoc.h \
    produit.h \
    produitang.h \
    produitc.h \
    qrcode.h \
    smtp.h \
    stat_combo.h \
    stat_combop.h \
    statistique.h \
    tache.h \
    tacheeng.h

FORMS += \
    ambulance.ui \
    arduinoambulance.ui \
    auth.ui \
    blocnote.ui \
    calculatrice.ui \
    camera.ui \
    chatbox.ui \
    client.ui \
    dialog.ui \
    dumessengerconnectiondialog.ui \
    employe.ui \
    home.ui \
    localisation.ui \
    mainwindow.ui \
    patientarduino.ui \
    produit.ui \
    produitang.ui \
    stat_combo.ui \
    stat_combop.ui \
    statistique.ui \
    tache.ui \
    tacheeng.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
QMAKE_CXXFLAGS+= -std=gnu++11
