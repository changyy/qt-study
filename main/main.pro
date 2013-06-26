TEMPLATE = app
TARGET = main
DEPENDPATH += .
INCLUDEPATH += . ..

#QT += network webkit xml

#INTERNAL_REQUIRED_LIBS = 

# Input
SOURCES += main.c
#LIBS += -L../prebuild-libs/ lwget
#RESOURCES += $${PWD}/../res/main.qrc
include($${PWD}/build.settings)
