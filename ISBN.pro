QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    deletedialog.cpp \
    isbnbook.cpp \
    main.cpp \
    mainwindow.cpp \
    newdialog.cpp \
    searchdialog.cpp \
    searchresults.cpp

HEADERS += \
    deletedialog.h \
    isbnbook.h \
    mainwindow.h \
    newdialog.h \
    searchdialog.h \
    searchresults.h

FORMS += \
    deletedialog.ui \
    mainwindow.ui \
    newdialog.ui \
    searchdialog.ui \
    searchresults.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
