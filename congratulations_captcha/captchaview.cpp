#include "captchaview.h"

CaptchaView::CaptchaView(QObject *parent) :
    QObject(parent)
{

}

void CaptchaView::initialize(QmlApplicationViewer& viewer,const QString& viewName) {
    viewer.rootContext()->setContextProperty(viewName, this);
    QObject::connect(this, SIGNAL(writeResult(QString)),this, SLOT(onWriteResult(QString)));
}
