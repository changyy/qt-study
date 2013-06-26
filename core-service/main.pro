#QT += network
TEMPLATE = app
TARGET = core-service
DEPENDPATH += .
INCLUDEPATH += . ..

#QT += network webkit xml

#INTERNAL_REQUIRED_LIBS = 

# Input
SOURCES += core-service.c

include(../build.settings)
