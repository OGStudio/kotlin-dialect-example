#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>

#include "ignore.kd.h"
#include "main.h"
#include "VM.h"

int main(int argc, char *argv[]) {
    // Create Qt application
    QQuickStyle::setStyle("Fusion");
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl *objURL) {
            if (!obj && url == objURL) {
                QCoreApplication::exit(-1); 
            }
        },
        Qt::QueuedConnection
    );

    API api;
    FObj fobj;
    // Create and launch components
    MainComponent m;
    m.setup();

    // Configure and load QML
    engine.rootContext()->setContextProperty("api", &api);
    engine.rootContext()->setContextProperty("F", &fobj);
    engine.rootContext()->setContextProperty("vm", &VM::singleton());
    //engine.loadFromModule("helloworld", "AppView");
    engine.load(QUrl(QStringLiteral("qrc:/helloworld/AppView.qml")));

    return app.exec();
}
