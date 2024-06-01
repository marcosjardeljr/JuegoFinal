QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    enemigos.cpp \
    jugador.cpp \
    main.cpp \
    mainwindow.cpp \
    movimientos.cpp \
    pared.cpp

HEADERS += \
    enemigos.h \
    jugador.h \
    mainwindow.h \
    movimientos.h \
    pared.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagenes.qrc

DISTFILES += \
    imagenes/cientifico2.jpg \
    imagenes/cientificos.gif \
    imagenes/enemigo1.png \
    imagenes/fondo1.jpg \
    imagenes/fondo_inicio.png \
    imagenes/granada.png \
    imagenes/obstaculo1.jpg \
    imagenes/obstaculo2.jpg \
    imagenes/proyectil.png \
    imagenes/soldado.png
