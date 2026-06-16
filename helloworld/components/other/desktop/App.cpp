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
    QUrl qmlPath(QStringLiteral("qrc:/helloworld/AppView.qml"));
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [qmlPath](QObject *obj, const QUrl *objURL) {
            if (!obj && qmlPath == objURL) {
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
    engine.load(qmlPath);

    return app.exec();
}
