QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dungeongenerator.cpp \
    abadblobview.cpp \
    abulletview.cpp \
    acharacterview.cpp \
    acollider.cpp \
    acombatmanagermodel.cpp \
    acombatmanagerview.cpp \
    acontroller.cpp \
    adamagedealermodel.cpp \
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
    collider3dbox.cpp \
    collider3dsphere.cpp \
    main.cpp \
    mainwindow.cpp \
    shootingabilitycontroller.cpp \
    shootingabilitymodel.cpp \
    shootingabilityview.cpp

HEADERS += \
    dungeongenerator.h \
    mainwindow.h \
    abadblobview.h \
    abulletview.h \
    acharacterview.h \
    acollider.h \
    acombatmanagermodel.h \
    acombatmanagerview.h \
    acontroller.h \
    adamagedealermodel.h \
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
    collider3dbox.h \
    collider3dsphere.h \
    shootingabilitycontroller.h \
    shootingabilitymodel.h \
    shootingabilityview.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
