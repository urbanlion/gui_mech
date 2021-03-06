QT += core widgets gui

CONFIG += c++11 console
CONFIG += app_bundle

TEMPLATE = app
INCLUDEPATH += /opt/ros/noetic/include


DEPENDPATH += /opt/ros/noetic/include


LIBS += -L/opt/ros/noetic/lib -L/usr/local/lib \
    -lroscpp -lrospack -lpthread -lrosconsole \
    -lrosconsole_log4cxx -lrosconsole_backend_interface \
    -lxmlrpcpp -lroscpp_serialization -lrostime \
    -lcpp_common  -lroslib -lpthread
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
    gnode.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    gnode.hpp \
    mainwindow.hpp \
    order.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/image_conf.qrc
