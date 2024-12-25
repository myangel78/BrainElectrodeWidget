QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += src/Widget
INCLUDEPATH += src/Graphics
INCLUDEPATH += src




# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS +=

HEADERS += \
    src/Global.h \
    src/Graphics/ElectrodeItem.h \
    src/Graphics/HeadOutlineItem.h \
    src/Graphics/TopoGraphicsView.h \
    src/Graphics/TopoGraphicsWidget.h \
    src/MainWindow.h \
    src/Widget/BrainFigure.h \
    src/Widget/Electrode.h \
    src/Widget/TopoWidget.h

SOURCES += \
    src/Graphics/ElectrodeItem.cpp \
    src/Graphics/HeadOutlineItem.cpp \
    src/Graphics/TopoGraphicsView.cpp \
    src/Graphics/TopoGraphicsWidget.cpp \
    src/MainWindow.cpp \
    src/Widget/BrainFigure.cpp \
    src/Widget/Electrode.cpp \
    src/Widget/TopoWidget.cpp \
    src/main.cpp
