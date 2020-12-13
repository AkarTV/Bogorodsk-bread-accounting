QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
# QXlsx code for Application Qt project
QXLSX_PARENTPATH=./         # current QXlsx path is . (. means curret directory)
QXLSX_HEADERPATH=./header/  # current QXlsx header path is ./header/
QXLSX_SOURCEPATH=./source/  # current QXlsx source path is ./source/
include(./QXlsx.pri)

SOURCES += \
    ingredient.cpp \
    main.cpp \
    mainwindow.cpp \
    price_dialog.cpp \
    product.cpp \
    product_list.cpp \
    report_for_day.cpp

HEADERS += \
    ingredient.h \
    ingredient_list.h \
    mainwindow.h \
    price_dialog.h \
    product.h \
    product_list.h \
    report_for_day.h

FORMS += \
    mainwindow.ui \
    price_dialog.ui \
    report_for_day.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
