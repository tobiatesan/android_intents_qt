#include <QApplication>
#include <QQmlApplicationEngine>
#include <myeventfilter.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.installEventFilter(new MyEventFilter());

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
