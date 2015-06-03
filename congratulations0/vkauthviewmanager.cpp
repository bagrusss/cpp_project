#include "vkauthviewmanager.h"
#include <signal.h>
#include <QDebug>

VkAuthViewManager::VkAuthViewManager(QObject* parent):
    QObject(parent),
    wasAuthenticatedFlag(SettingsDBManager::getAuthToken().empty() == false),
    authenticationUrl(QString::fromStdString(SettingsDBManager::getAuthUrl())) {

}

void VkAuthViewManager::initialize(QmlApplicationViewer& viewer, const QString& modelName) {
    //зарегистрировать модель для работы с QML
    viewer.rootContext()->setContextProperty(modelName, this);
    QObject::connect(this, SIGNAL(storeAuthToken(const QString&)), this, SLOT(onAuthComplete(const QString&)));
    QObject::connect(this, SIGNAL(authIsValid(const QString&)), this, SLOT(onAuthIsValid(const QString&)));
}

bool VkAuthViewManager::getAuthFlag() {
    //qDebug() << wasAuthenticatedFlag;
    return wasAuthenticatedFlag;
}
QString VkAuthViewManager::getAuthUrl() {
    return authenticationUrl;
}

void VkAuthViewManager::onAuthComplete(const QString& redirectedUrl) {
    //redirectedUrl.replace("#", "?");
    QUrl url(redirectedUrl);
    //qDebug() << url.toString();
    QString tempTokenStr = url.fragment();
    tempTokenStr.replace("&", "=");
    //tempTokenStr = tempTokenStr.section("=", 1, 1);
    //qDebug() << tempTokenStr.section("=", 1, 1);
    //qDebug() << tempTokenStr.section("=", 5, 5);
    SettingsDBManager::addSettings("access-token", tempTokenStr.section("=", 1, 1).toStdString());
    SettingsDBManager::addSettings("user-id", tempTokenStr.section("=", 5, 5).toStdString());
    SettingsDBManager::saveConfig();
    //запустить в отдельном процессе демон

    qint64 pid = SettingsDBManager::getDaemonPid();    //костыль для тестирования!
    if (pid != -1) {
        kill(pid, SIGKILL);
    }
    QProcess::startDetached(SettingsDBManager::getDaemonProgram(), QStringList(), QString(), &pid);
    //qDebug() << pid;
    SettingsDBManager::addSettings("daemon-pid", std::to_string(pid));
}

bool VkAuthViewManager::onAuthIsValid(const QString& redirectedUrl) {
    QString templateAuthString(QString::fromStdString(SettingsDBManager::getTemplateAuthUrl()));
    if (redirectedUrl.indexOf(templateAuthString) == -1)
        return false;
    else
        return true;
}
