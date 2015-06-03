#ifndef NETWORK_H
#define NETWORK_H

#include <QJsonObject>
#include <QtNetwork>
#include <map>
#include <QHash>
#include <QBitmap>
#include <QEventLoop>

#include "congratulations_lib_global.h"
#include "listelement.h"
//#include "dbmanager.h" //ЧТо-то много зависимостей. Может передавать инфу через демон?

#define MAX_REQUEST_WAIT 10000
//#define GUI_PROGRAM "/opt/Qt5.1.1/Tools/QtCreator/bin/build-congratulations0-Desktop_Qt_5_1_1_GCC_64bit-Debug/congratulations0"

struct NetworkResult {
    bool isValid;
    QByteArray result;
    NetworkResult(): isValid(false) {}

};

class CONGRATULATIONS_LIBSHARED_EXPORT Network {
//интерфейс для работы с сетью
//(использует демон)
public:
    Network();
    //отправить поздравления для конкретного друга
    static NetworkResult sendCongratulations(const FriendEntry& friendEntry,
                                             QString& query,
                                             const QString& captcha = "");

    //получить всех друзей
    static QList<FriendEntry*>* getFriends(const QString&);

    //downloads image from vk server and save as file
    static void SavePic(const QString& , const QString& );

    static QList<QString>* captchaNeeded(const QByteArray& error);
//реализует работу с сетью
private:
    //static const QString VK_API_SERVER ;//= "http://";
    //check network connection
    //static bool ChekNetworkConnection();

    //используется для отправки Post and Get запросов
    static NetworkResult Post(const QUrl& url, const QUrlQuery& postData);
    static NetworkResult Get(const QUrl& url);

    //uploads file to vk server and returns error code;
    //static int UploadImage(const QString&);

    //static QString debugError(const QByteArray&);


};

#endif // NETWORK_H
