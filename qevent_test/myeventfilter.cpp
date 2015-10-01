#include "myeventfilter.h"

MyEventFilter::MyEventFilter() : QObject () {}
MyEventFilter::~MyEventFilter() {}
bool MyEventFilter::eventFilter(QObject* object,QEvent* e) {
    qDebug() << "Received" << e->type();
    if (e->type() == QEvent::FileOpen) {
            QFile file(static_cast<QFileOpenEvent *>(e)->file());
            qDebug() << "File to open:" << file.fileName();
            return true;
    } else {
            return QObject::eventFilter(object,e);
    }
}

