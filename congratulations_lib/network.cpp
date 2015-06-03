#include "network.h"

//const QString  Network::VK_API_SERVER ;

//bool Network::ChekNetworkConnection() {
//    return true;
//}

NetworkResult Network::Post(const QUrl& url, const QUrlQuery& postData) {
    //qDebug() << url.toString();
    //QString captcha_str;
    //int resultFlag;
    //QString actualUrl = url.toString();
    QNetworkReply* reply;
    //do {
        QNetworkAccessManager* accessManager = new QNetworkAccessManager();
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        if (postData.isEmpty() == true) {
            reply = accessManager->post(request, QByteArray());
        } else {
            QByteArray data = postData.toString(QUrl::FullyEncoded).toUtf8();
            reply = accessManager->post(request, data);
        }

        QEventLoop waitReplyLoop;
        QObject::connect(accessManager, SIGNAL(finished(QNetworkReply*)), &waitReplyLoop, SLOT(quit()));
        QTimer::singleShot(MAX_REQUEST_WAIT, &waitReplyLoop, SLOT(quit()));
        QObject::connect(accessManager, SIGNAL(finished(QNetworkReply*)), accessManager, SLOT(deleteLater()));
        waitReplyLoop.exec();
        //qDebug () << reply->error();
        NetworkResult networkResult;
        if (reply->error() == QNetworkReply::NoError) {
            networkResult.isValid = true;
            networkResult.result = reply->readAll();
        }
        else {
            networkResult.isValid = false;
        }
        //else {
        //    QByteArray error = reply->readAll();
        //    if (captchaNeeded(error)  == true)
        //        resultFlag = Network::CaptchaNeeded;
        //    else
        //        resultFlag = Network::NoError;
        //}
        //captcha_str = Network::debugError(error);
        //if (captcha_str.isEmpty() == true)
        //   resultFlag = true;
        //actualUrl = url.toString() + captcha_str;
    //} while (captcha_str.isEmpty() == false);
    reply->deleteLater();
    return networkResult;
}

NetworkResult Network::Get(const QUrl& url) {
    QNetworkAccessManager* accessManager = new QNetworkAccessManager();
    QNetworkReply* reply = accessManager->get(QNetworkRequest(url));
    QEventLoop waitReplyLoop;
    QObject::connect(accessManager, SIGNAL(finished(QNetworkReply*)), &waitReplyLoop, SLOT(quit()));
    QTimer::singleShot(MAX_REQUEST_WAIT, &waitReplyLoop, SLOT(quit()));
    QObject::connect(accessManager, SIGNAL(finished(QNetworkReply*)), accessManager, SLOT(deleteLater()));
    waitReplyLoop.exec();
    //QJsonObject resultJSONObject;
    //return resultJSONObject;
    NetworkResult networkResult;
    if (reply->error() == QNetworkReply::NoError) {
        networkResult.isValid = true;
        networkResult.result = reply->readAll();
    }
    else
       networkResult.isValid = false;
    qDebug() << reply->readAll();
    //QByteArray answer = reply->readAll();
    reply->deleteLater();
    return networkResult;
}


//int Network::UploadImage(const QString& request) {
//    return 0;
//}

void Network::SavePic(const QString& request, const QString& pic_adress) {
    NetworkResult pic = Network::Get(request);
    qDebug() << pic_adress;
    if (pic.isValid == false)
        return;

    if (pic.result.isEmpty() == false) {
        QFile file(pic_adress);
        file.open(QIODevice::WriteOnly);
        file.write(pic.result);
        file.close();
        //QPixmap pixmap;
        //qDebug() << pixmap.isNull();
        //qDebug() << pic.constData();
        //qDebug() << pic.size();
        //const uchar* data = reinterpret_cast<const uchar *>(pic.constData());
        //for (int i = 0; i < pic.size(); ++i) {
        //    qDebug() << (int) data[i];
        //}
        //pixmap.loadFromData(data, pic.size(), "JPG", Qt::AutoColor);
        //pixmap.save(pic_adress);
    }
    //else {
    //    qDebug() << "smth wrong";
    //}
}

//bool Network::sendCongratulations(const FriendEntry& friendEntry, bool messageDest) {return true;}

QList<FriendEntry*>* Network::getFriends(const QString& urlString) {
    //QString urlString = QString::fromStdString(SettingsDBManager::getFriendsUrl());
    //urlString.replace("access-token", QString::fromStdString(SettingsDBManager::getAuthToken()));
    //urlString.replace("user-id", QString::fromStdString(SettingsDBManager::getUserId()));
    qDebug() << urlString;
    NetworkResult answer = Get(QUrl(urlString));

    if (answer.isValid == false)
        return nullptr;

    QJsonDocument document = QJsonDocument::fromJson(answer.result);
    QJsonObject jsonObject = document.object();
    QJsonArray result = (*jsonObject.find("response")).toArray();
    QList<FriendEntry*>* friendsList = new QList<FriendEntry*>();
    for (auto iter = result.begin(); iter != result.end(); ++iter) {
       QJsonObject friendObj = (*iter).toObject();
       //QByteArray pic = Get(friendObj.take("photo").toString());
       //qDebug() << pic;
       //распарсить строку с датой:
       QString date = friendObj.take("bdate").toString();
       if (date.isEmpty() == false && date.section(".", 1, 1).isEmpty() == false) {
           int day = date.section(".", 0, 0).toDouble();
           int month = date.section(".", 1, 1).toDouble();
           friendsList->append(new FriendEntry(friendObj.take("uid").toDouble(),
                                               friendObj.take("first_name").toString() + " " + friendObj.take("last_name").toString(),
                                               day,
                                               month,
                                               friendObj.take("photo").toString()));
       }

    }
    //for (int i = 0; i < friendsList->size(); ++i) {
    //    qDebug() << friendsList->at(i)->day;
    //    qDebug() << friendsList->at(i)->month;
    //}

    return friendsList;
}

NetworkResult Network::sendCongratulations(const FriendEntry& currentFriendEntry,
                                           QString& query,
                                           const QString& captcha
                                  ) {
    //QString query;
    //if (messageDest == true) {
    //    query =  QString::fromStdString(SettingsDBManager::getPostWallUrl());
    //} else {
    //    query = QString::fromStdString(SettingsDBManager::getSendMessageUrl());
    //}
    if (query.isEmpty() == true)
        return NetworkResult();

    QString currentFriendId = QString::fromStdString(std::to_string(currentFriendEntry.id));
    query.replace("user-id", currentFriendId);
    query.replace("template-message", currentFriendEntry.templateText);
    //query.replace("access-token", QString::fromStdString(SettingsDBManager::getAuthToken()));
    //qDebug() << query;
    if (captcha.isEmpty() == false)
        query += captcha;
    return Post(QUrl(query), QUrlQuery());
}

QList<QString>* Network::captchaNeeded(const QByteArray& error) {
    QJsonDocument document = QJsonDocument::fromJson(error);
    QJsonObject jsonObject = document.object();
    QString img = (*(*jsonObject.find("error")).toObject().find("captcha_img")).toString();
    QString sid = (*(*jsonObject.find("error")).toObject().find("captcha_sid")).toString();
    if (img.isEmpty() == false && sid.isEmpty() == false) {
        QList<QString>* result = new QList<QString>();
        result->append(img); //первая строка - картинка
        result->append(sid); //вторая - номер для запроса
        return result;
    }
    else return nullptr;
}

/*QString Network::debugError(const QByteArray& error) {
    QJsonDocument document = QJsonDocument::fromJson(error);
    QJsonObject jsonObject = document.object();
    QString result = (*(*jsonObject.find("error")).toObject().find("captcha_img")).toString();
    QString sid = (*(*jsonObject.find("error")).toObject().find("captcha_sid")).toString();
    if (result.isEmpty() == false) {
        Network::SavePic(result, QString::fromStdString(IMG_FILE(std::string("error"))));
        std::string captcha;
        std::cin >> captcha;
        return "&captcha_key=" + QString::fromStdString(captcha)+"&captcha_sid=" +sid;
    }
    else
        return QString();
    //if (result.isEmpty() == false) {
    //    QProcess* guiProcess = new QProcess();
    //    guiProcess->start(GUI_PROGRAM, result);
    //}
    //result"captcha_img"
}*/
