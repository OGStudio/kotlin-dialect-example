#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>

#include "ignore.kd.h"
#include "root.h"
#include "VM.h"

int main(int argc, char *argv[]) {
    // Create Qt application
    QQuickStyle::setStyle("Fusion");
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection
    );

    API api;
    FObj fobj;
    // Create and launch components
    RootComponent r;
    r.setup();

    // Configure and load QML
    engine.rootContext()->setContextProperty("api", &api);
    engine.rootContext()->setContextProperty("F", &fobj);
    engine.rootContext()->setContextProperty("vm", &VM::singleton());
    engine.loadFromModule("hellolist", "AppView");

    return app.exec();
}
