#ifndef NETWORK_H
#define NETWORK_H

#include <QJsonObject>
#include <QtNetwork>
#include <map>
#include <QHash>
#include <QBitmap>

#include <QCoreApplication>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>

#include <QJsonDocument>
#include <memory>

#define VK_API_SERVER "https://api.vk.com/"

using namespace std;

class  Network {
//интерфейс для работы с сетью
//(использует демон)

public:
    Network();
    //static const QString VK_API_SERVER ;//= "http://";
    //check network connection
    static bool ChekNetworkConnection();

    //используется для отправки Post and Get запросов
    static QJsonDocument Post(const QHash<QString, QString>&);
    static QJsonObject Get(const QHash<QString, QString>&);

    //uploads file to vk server and returns error code;
    static int UploadImage(const QString&);

    //downloads image from vk server and save as file
    static QBitmap DownloadBitmap(const QString&);
};

#endif // NETWORK_H
