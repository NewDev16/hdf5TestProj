TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

LIBS += /usr/lib/libhdf5.so -lhdf5

INCLUDEPATH+=/usr/include/hdf5.h
