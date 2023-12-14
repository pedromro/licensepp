TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp



SOURCES += \
    $$files(licensing/*.cc)

HEADERS += \
    $$files(licensing/*.h)


QMAKE_LFLAGS += licensepp.lib

INCLUDEPATH +=  $$PWD/../include
DEPENDPATH  +=  $$PWD/../build/Release/lib
LIBS        += -L$$PWD/../build/Release/lib -llicensepp
