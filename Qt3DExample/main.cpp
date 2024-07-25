#include <Qt3DQuickExtras/qt3dquickwindow.h>
#include <QGuiApplication>
#include <Qt3DQuick/QQmlAspectEngine>
#include<ObjModelReader.hpp>
#include<ModelController.hpp>
#include<ModelGeometry.hpp>
#include<QQmlAspectEngine>
#include <QQmlContext>
#include<QQmlEngine>

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);
    Qt3DExtras::Quick::Qt3DQuickWindow view;
    qmlRegisterType<ObjModelReader>("test",1,0,"OMR");
    qmlRegisterType<ModelData>("test",1,0,"ModelData");
    qmlRegisterType<ModelGeometry>("test",1,0,"ModelGeometry");
    qRegisterMetaType<const char*>("const char*");
    auto controller = new ModelController();

    view.engine()->qmlEngine()->rootContext()->setContextProperty("_controller", controller);

    view.setSource(QUrl("qrc:/main.qml"));
    view.show();

    return app.exec();
}
