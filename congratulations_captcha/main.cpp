#include <QApplication>
#include "qmlapplicationviewer.h"
#include "captchaview.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));
    QmlApplicationViewer viewer;

    QString imagePath;//
    if (argc > 1)
        imagePath = argv[1];
    else
        imagePath = DEFAULT_IMAGE_PATH;
    CaptchaView captchaView(imagePath);
    captchaView.initialize(viewer, "CaptchaView");
    QObject::connect(&captchaView, SIGNAL(exitApplication()), app.data(), SLOT(quit()));
    viewer.addImportPath(QLatin1String("modules"));
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/congratulations_captcha/main.qml"));
    viewer.showExpanded();

    return app->exec();
}
