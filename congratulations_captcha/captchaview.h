#ifndef CAPTCHAVIEW_H
#define CAPTCHAVIEW_H

#include <QObject>
#include <QDeclarativeContext>
#include <iostream>

#include "qmlapplicationviewer/qmlapplicationviewer.h"
#define DEFAULT_IMAGE_PATH "../../../images/error.jpg"

class CaptchaView : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString captchaImage READ getCaptchaImage NOTIFY imageChanged)

public:
    explicit CaptchaView(QObject *parent = 0);
    explicit CaptchaView(const QString& image): captchaImage(image) {}

    QString getCaptchaImage() {
        return captchaImage;
    }
    void initialize(QmlApplicationViewer& viewer,const QString& viewName);

signals:
    void writeResult(QString result);
    void imageChanged(QString image);
    void exitApplication();

public slots:
    void onWriteResult(QString result) {
        std::cout << result.toStdString();
        emit exitApplication();
    }

private:
    QString captchaImage;
};

#endif // CAPTCHAVIEW_H
