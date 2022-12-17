QT       += core gui httpserver sql

INCLUDEPATH += D:/Soft/Qt/Tools/OpenSSL/Win_x86/include
LIBS += D:/Soft/Qt/Tools/OpenSSL/Win_x86/bin/libcrypto-1_1.dll
LIBS += D:/Soft/Qt/Tools/OpenSSL/Win_x86/bin/libssl-1_1.dll
LIBS += D:/Soft/Qt/Tools/OpenSSL/Win_x86/bin/libcrypto-1_1.dll

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aesmanager.cpp \
    dbmanager.cpp \
    insertrecord.cpp \
    main.cpp \
    mainwindow.cpp \
    sqltablemodel.cpp

HEADERS += \
    ../CnF_Tracker/globalscope.h \
    aesmanager.h \
    dbmanager.h \
    globalscope.h \
    insertrecord.h \
    mainwindow.h \
    sqltablemodel.h

FORMS += \
    insertrecord.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
