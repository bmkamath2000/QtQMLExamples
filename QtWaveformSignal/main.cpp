#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSurfaceFormat>
#include <QQuickView>
#include "backendcontroller.h"
#include "qwaveformhistorypanel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    BackendController backend;

    QQuickView view;
    QSurfaceFormat format = view.format();
    format.setSamples(16);
    view.setFormat(format);

    engine.rootContext()->setContextProperty("backend", &backend);
    qmlRegisterType<BackendController>("com.example.backend", 1, 0, "BackendController");
    qmlRegisterType<QWaveformHistoryPanel>("com.example.backend", 1, 0, "QWaveformHistoryPanel");
    const QUrl url(u"qrc:/QtWaveformSignal/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
