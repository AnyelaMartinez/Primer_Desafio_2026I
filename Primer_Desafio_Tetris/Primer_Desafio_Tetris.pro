TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        funciones_fichas.cpp \
        funciones_movimiento.cpp \
        funciones_tablero.cpp \
        funciones_verificacion.cpp \
        main.cpp

HEADERS += \
    funciones_tetris.h
