TARGET = QPyConsole

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    mainwindow.h \
    pywrapper.h \
    qpconsole.h

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    pywrapper.cpp \
    qpconsole.cpp

INCLUDEPATH += C:/Python/Python38-32/include

CONFIG( debug, debug|release ) {
    # debug
    win32-g++ {
        LIBS += -LC:/Python/Python38-32/libs -lpython38_d
    } else:win32-msvc* {
        LIBS += -LC:/Python/Python38-32/libs -lpython38_d
    }
} else {
    # release
    win32-g++ {
        LIBS += -LC:/Python/Python38-32/libs -lpython38
    } else:win32-msvc* {
        LIBS += -LC:/Python/Python38-32/libs -lpython38
    }
}
