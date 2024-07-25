QT += quick

SOURCES += \
        Backend.cpp \
        main.cpp

resources.files = main.qml 
resources.prefix = /$${TARGET}
RESOURCES += resources

TRANSLATIONS += \
    Calculator2_en_IN.ts
CONFIG += lrelease
CONFIG += embed_translations

CONFIG += qmltypes
QML_IMPORT_NAME = io.qt.Calculator2.Backend
QML_IMPORT_MAJOR_VERSION = 1
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Backend.h
