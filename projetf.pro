QT       += core gui printsupport multimedia serialport  multimediawidgets
QT  += svg
QT += network
QT       +=sql \
            quick



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += static


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
    blocnote.cpp \
    calculatrice.cpp \
    camera.cpp \
    connection.cpp \
    home.cpp \
    main.cpp \
    mainwindow.cpp \
    produit.cpp \
    produitang.cpp \
    produitc.cpp \
    qrcode.cpp \
    statistique.cpp \
    tache.cpp \
    tacheeng.cpp

HEADERS += \
    blocnote.h \
    calculatrice.h \
    camera.h \
    connection.h \
    home.h \
    mainwindow.h \
    produit.h \
    produitang.h \
    produitc.h \
    qrcode.h \
    statistique.h \
    tache.h \
    tacheeng.h

FORMS += \
    blocnote.ui \
    calculatrice.ui \
    camera.ui \
    home.ui \
    mainwindow.ui \
    produit.ui \
    produitang.ui \
    statistique.ui \
    tache.ui \
    tacheeng.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc
