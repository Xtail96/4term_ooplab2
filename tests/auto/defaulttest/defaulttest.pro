
include(../gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS +=     \
    ../../../src/arc.h \
    ../../../src/ellipse.h \
    ../../../src/point.h \
    ../../../src/round.h \
    ../../../src/shape.h \
    tst_round_round.h \
    tst_arc_arc.h \
    tst_ellipse_arc.h \
    tst_ellipse_ellipse.h \
    tst_round_arc.h \
    tst_round_ellipse.h

SOURCES +=     main.cpp \
    ../../../src/arc.cpp \
    ../../../src/ellipse.cpp \
    ../../../src/round.cpp \
    ../../../src/shape.cpp
