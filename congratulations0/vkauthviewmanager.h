#ifndef VKAUTHVIEWMANAGER_H
#define VKAUTHVIEWMANAGER_H

#include <QString>
#include <QObject>
#include <QUrl>
#include <QDeclarativeContext>
#include <QProcess>

#include "dbmanager.h"
#include <qmlapplicationviewer.h>

//#define DAEMON_PROGRAM SettingsDBManager::getDaemonProgram()

class VkAuthViewManager: QObject
{
    Q_OBJECT
    Q_PROPERTY(bool wasAuthenticatedFlag READ getAuthFlag)
    Q_PROPERTY(QString authenticationUrl READ getAuthUrl)

public:
    explicit VkAuthViewManager(QObject* parent=0);//: QObject(parent) {}
    void initialize(QmlApplicationViewer&, const QString&);
    bool getAuthFlag();
    QString getAuthUrl();

signals:
    void storeAuthToken(const QString& redirectedUrl);
    bool authIsValid(const QString& redirectedUrl);

public slots:
    void onAuthComplete(const QString& redirectedUrl);
    bool onAuthIsValid(const QString& redirectedUrl);

private:
    bool wasAuthenticatedFlag;
    QString authenticationUrl;

};

#endif // VKAUTHVIEWMANAGER_H
