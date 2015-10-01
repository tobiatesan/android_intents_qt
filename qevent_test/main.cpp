#include <QApplication>
#include <QQmlApplicationEngine>
#include <jni.h>
#include <QDebug>

class URIHandler : public QObject {
public:
    void openUri(QString uri) {
        qDebug() << "Open URI" << uri;
    }
} handler;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL
  Java_com_foo_Bar_openUri(JNIEnv *env,
                                                    jobject obj,
                                                    jstring uri)
{
    jboolean isCopy;
    isCopy = false;
    const char* utf = env->GetStringUTFChars(uri, &isCopy);
    handler.openUri(QString(utf));
    env->ReleaseStringUTFChars(uri, utf);

}

#ifdef __cplusplus
}
#endif
