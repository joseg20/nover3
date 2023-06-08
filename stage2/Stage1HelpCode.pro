TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        door.cpp \
        magnetic_sensor.cpp \
        main.cpp \
        sensor.cpp \
        central.cpp \
        siren.cpp \
        window.cpp

HEADERS += \
    door.h \
    magnetic_sensor.h \
    sensor.h \
    central.h \
    siren.h \
    window. h

DISTFILES += \
    config.txt
