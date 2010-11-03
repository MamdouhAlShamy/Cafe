#-------------------------------------------------
#
# Project created by QtCreator 2010-10-31T22:46:04
#
#-------------------------------------------------

QT       += core gui sql

TARGET = cafe
TEMPLATE = app


SOURCES += main.cpp\
    welcomedialog.cpp \
    itemlist.cpp \
    itemcontainer.cpp \
    billing.cpp \
    detaileditemview.cpp \
    flickcharm.cpp

HEADERS  += \
    welcomedialog.h \
    itemlist.h \
    itemcontainer.h \
    billing.h \
    detaileditemview.h \
    flickcharm.h


 myFiles.sources = ./DB.db \
                    ./images
 DEPLOYMENT += myFiles


CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xecb85925
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}

OTHER_FILES += Readme.txt \


FORMS += \
    welcomedialog.ui \
    itemlist.ui \
    itemcontainer.ui \
    billing.ui \
    detaileditemview.ui
