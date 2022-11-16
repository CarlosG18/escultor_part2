TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    figurageometrica.cpp \
    sculptor.cpp \
    putvoxel.cpp \
    putbox.cpp \
    cutvoxel.cpp \
    cutbox.cpp \
    putsphere.cpp \
    putellipsoid.cpp \
    cutsphere.cpp \
    cutellipsoid.cpp

HEADERS += \
    figurageometrica.h \
    sculptor.h \
    putvoxel.h \
    putbox.h \
    cutvoxel.h \
    cutbox.h \
    putsphere.h \
    putellipsoid.h \
    cutsphere.h \
    cutellipsoid.h
