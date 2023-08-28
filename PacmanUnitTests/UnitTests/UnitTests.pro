QT += testlib
QT -= gui

# For GCov
QMAKE_CXXFLAGS += --coverage
QMAKE_LFLAGS += --coverage

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS +=  ../../RS030-pacman/qt/ghost.h \
            ../../RS030-pacman/qt/button.h \
            ../../RS030-pacman/qt/dot.h \
            ../../RS030-pacman/qt/game.h \
            ../../RS030-pacman/qt/health.h \
            ../../RS030-pacman/qt/pacman.h \
            ../../RS030-pacman/qt/pacmangame.h \
            ../../RS030-pacman/qt/score.h \
            ../../RS030-pacman/qt/wall.h \
            ../../RS030-pacman/qt/extern_variables.h

SOURCES +=  tst_unittests.cpp \
            ../../RS030-pacman/qt/ghost.cpp \
            ../../RS030-pacman/qt/button.cpp \
            ../../RS030-pacman/qt/dot.cpp \
            ../../RS030-pacman/qt/game.cpp \
            ../../RS030-pacman/qt/health.cpp \
            ../../RS030-pacman/qt/pacman.cpp \
            ../../RS030-pacman/qt/pacmangame.cpp \
            ../../RS030-pacman/qt/score.cpp \
            ../../RS030-pacman/qt/wall.cpp \
            ../../RS030-pacman/qt/extern_variables.cpp

