QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acollisionobserver.cpp \
    adungeonview.cpp \
    bulletsmanager.cpp \
    collidercontroller.cpp \
    colliderview.cpp \
    dungeoncontroller.cpp \
    collision.cpp \
    dungeongenerator.cpp \
    abadblobview.cpp \
    abulletview.cpp \
    acharacterview.cpp \
    acollider.cpp \
    acombatmanagerview.cpp \
    acontroller.cpp \
    amodel.cpp \
    aphysicalobjectmodel.cpp \
    aview.cpp \
    badblobcontroller.cpp \
    badblobmodel.cpp \
    badblobview2d.cpp \
    badblobview3d.cpp \
    bulletcontroller.cpp \
    bulletmodel.cpp \
    bulletview2d.cpp \
    bulletview3d.cpp \
    charactercontroller.cpp \
    charactermodel.cpp \
    characterview2d.cpp \
    characterview3d.cpp \
    collider2dcircle.cpp \
    collider2dsquare.cpp \
    dungeonview3d.cpp \
    gamemanager.cpp \
    dungeonmodel.cpp \
    dungeonview2d.cpp \
    gldisplaywidget.cpp \
    line.cpp \
    main.cpp \
    mainwindow.cpp \
    obstaclemodel.cpp \
    utils.cpp

HEADERS += \
    acollisionobserver.h \
    adungeonview.h \
    bulletsmanager.h \
    collidercontroller.h \
    colliderview.h \
    dungeoncontroller.h \
    collision.h \
    dungeongenerator.h \
    dungeonview3d.h \
    gamemanager.h \
    dungeonmodel.h \
    dungeonview2d.h \
    gldisplaywidget.h \
    line.h \
    mainwindow.h \
    abadblobview.h \
    abulletview.h \
    acharacterview.h \
    acollider.h \
    acombatmanagerview.h \
    acontroller.h \
    amodel.h \
    aphysicalobjectmodel.h \
    aview.h \
    badblobcontroller.h \
    badblobmodel.h \
    badblobview2d.h \
    badblobview3d.h \
    bulletcontroller.h \
    bulletmodel.h \
    bulletview2d.h \
    bulletview3d.h \
    charactercontroller.h \
    charactermodel.h \
    characterview2d.h \
    characterview3d.h \
    collider2dcircle.h \
    collider2dsquare.h \
    obstaclemodel.h \
    utils.h

FORMS += \
    mainwindow.ui

LIBS = -lglu32 -lOpengl32

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
