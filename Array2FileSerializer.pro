TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += network widgets
#CONFIG -= qt

SOURCES += main.cpp \
    dataH5.cpp \
    DataStd.cpp \
    GoogleRequester.cpp \
    MainWindow.cpp

LIBS += /usr/lib/libhdf5.so -lhdf5

INCLUDEPATH+=/usr/include/hdf5.h

HEADERS += \
    dataH5.h \
    DataStd.h \
    GoogleRequester.h \
    MainWindow.h
