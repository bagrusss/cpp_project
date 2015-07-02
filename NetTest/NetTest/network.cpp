#include "network.h"

//const QString  Network::VK_API_SERVER ;

bool Network::ChekNetworkConnection() {
    return true;
}

QJsonDocument Network::Post(const QHash<QString, QString>& postArgs) {
    QEventLoop eventLoop;
    shared_ptr<QNetworkAccessManager> manager(new QNetworkAccessManager);
    QUrlQuery url(VK_API_SERVER);
    foreach(QString param, postArgs.keys()) {
        url.addQueryItem(param,postArgs[param]);
    }
    QNetworkRequest request(QUrl(url.toString()));//костыль
    QObject::connect(manager.get(), SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    shared_ptr<QNetworkReply> reply = (shared_ptr<QNetworkReply>)manager->post(request,"");
    eventLoop.exec();
    /*if (reply->error()=QNetworkReply::NoError)
        return ;*/
    return QJsonDocument::fromBinaryData(((QString)reply->readAll()).toUtf8());
}

QJsonObject Network::Get(const QHash<QString, QString>& getArgs) {
    QJsonObject resultJSONObject;
    return resultJSONObject;
}


int Network::UploadImage(const QString& request) {
    return 0;
}

QBitmap Network::DownloadBitmap(const QString& request) {
    QBitmap result;
    return result;
}



