QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
win32 {
        OTHER_FILES +=
}

SOURCES += \
    adjacency.cpp \
    edge.cpp \
    graph.cpp \
    graphvertex.cpp \
    main.cpp \
    dialog.cpp

HEADERS += \
    TSPalgorithm.h \
    adjacency.h \
    dialog.h \
    edge.h \
    graph.h \
    graphvertex.h

FORMS += \
    adjacency.ui \
    dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
