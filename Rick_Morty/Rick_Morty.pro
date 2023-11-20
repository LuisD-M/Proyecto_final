QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    balas.cpp \
    enemy1.cpp \
    heroe.cpp \
    heroe2.cpp \
    main.cpp \
    mainwindow.cpp \
    obstaculo.cpp \
    puntaje.cpp \
    start.cpp \
    vida.cpp

HEADERS += \
    balas.h \
    enemy1.h \
    heroe.h \
    heroe2.h \
    mainwindow.h \
    obstaculo.h \
    puntaje.h \
    start.h \
    vida.h

FORMS += \
    mainwindow.ui \
    start.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    imagenes.qrc
