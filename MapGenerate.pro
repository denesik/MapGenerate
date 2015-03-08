TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    voronoi/geometry.cpp \
    voronoi/Voronoi.cpp \
    lodepng/lodepng.cpp \
    Triangle.cpp \
    Rasterization.cpp

HEADERS += \
    voronoi/geometry.h \
    voronoi/Lloyd.h \
    voronoi/Voronoi.h \
    lodepng/lodepng.h \
    Triangle.h \
    Rasterization.h

