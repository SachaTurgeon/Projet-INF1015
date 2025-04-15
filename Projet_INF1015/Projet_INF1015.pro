QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Pieces.cpp \
    TestJeuxEchecs.cpp \
    main.cpp \
    projetjeuxechecs.cpp

HEADERS += \
    Pieces.h \
    projetjeuxechecs.h

FORMS += \
    projetjeuxechecs.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    pieces-basic-png/black-bishop.png \
    pieces-basic-png/black-bishop.png \
    pieces-basic-png/black-king.png \
    pieces-basic-png/black-king.png \
    pieces-basic-png/black-knight.png \
    pieces-basic-png/black-knight.png \
    pieces-basic-png/black-pawn.png \
    pieces-basic-png/black-pawn.png \
    pieces-basic-png/black-queen.png \
    pieces-basic-png/black-queen.png \
    pieces-basic-png/black-rook.png \
    pieces-basic-png/black-rook.png \
    pieces-basic-png/white-bishop.png \
    pieces-basic-png/white-bishop.png \
    pieces-basic-png/white-king.png \
    pieces-basic-png/white-king.png \
    pieces-basic-png/white-knight.png \
    pieces-basic-png/white-knight.png \
    pieces-basic-png/white-pawn.png \
    pieces-basic-png/white-pawn.png \
    pieces-basic-png/white-queen.png \
    pieces-basic-png/white-queen.png \
    pieces-basic-png/white-rook.png \
    pieces-basic-png/white-rook.png
