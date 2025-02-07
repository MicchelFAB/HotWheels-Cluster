QT = core

CONFIG += c++17 cmdline

# Include Paths (explicit inheritance from root)
INCLUDEPATH += \
    $$PWD/includes \
    /home/michel/qt***/sysroot/usr/include/Ice \
    /home/michel/qt***/sysroot/usr/include/IceUtil


# Application Sources
SOURCES += \
    middleware/CarDataI.cpp \
    middleware/ClientThread.cpp \
    middleware/Joystick.cpp \
    sources/ControlsManager.cpp \
    sources/JoysticksController.cpp \
    sources/EngineController.cpp \
    sources/PeripheralController.cpp \
    sources/main.cpp

HEADERS += \
    middleware/CarDataI.hpp \
    middleware/ClientThread.hpp \
    middleware/Joystick.h \
    includes/ControlsManager.hpp \
    includes/JoysticksController.hpp \
    includes/EngineController.hpp \
    includes/PeripheralController.hpp \
    includes/IPeripheralController.hpp \
    includes/enums.hpp

# Common Libraries
LIBS += -lSDL2 -lrt -lIce

# Conditionally add paths for cross-compilation
contains(QT_ARCH, arm) {
    LIBS += -L$$[QT_SYSROOT]/usr/lib/aarch64-linux-gnu -lSDL2
    INCLUDEPATH += $$[QT_SYSROOT]/usr/include/SDL2
}
