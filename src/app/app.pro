include(../build.pri)
TEMPLATE = app
TARGET = cd3
QT += script
SOURCES += main.cpp \
    saxloader.cpp
LIBS +=  -lboost_program_options-mt \
    -lboost_signals-mt \
    -lboost_thread-mt \
	-lcd3core \
	-lpycd3
HEADERS += saxloader.h
