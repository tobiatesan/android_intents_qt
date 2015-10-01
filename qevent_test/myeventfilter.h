#ifndef MYEVENTFILTER_H
#define MYEVENTFILTER_H

#include <QtGui>
#include <QApplication>

#include <QFileOpenEvent>

class MyEventFilter : public QObject {
public:
    MyEventFilter();
    virtual ~MyEventFilter();
protected:
    virtual bool eventFilter(QObject* object,QEvent* event);
};

#endif // MYEVENTFILTER_H
