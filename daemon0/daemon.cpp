#include "daemon.h"

Daemon::Daemon(int& argc, char * argv[]):
    QCoreApplication(argc, argv),
    connector(new DBusConnector(DAEMON_SERVICE_NAME,
                                DBUS_OBJECT_NAME,
                                GUI_SERVICE_NAME,
                                DBUS_OBJECT_NAME)),
    todayBdays(nullptr)
{
    //а если телефон включили в 23.50??
    //следующее обновление будет слишком поздно - можно не успеть всех поздравить
    reinitializeTimer.setInterval(CALENDAR_DAY);
    connect(&reinitializeTimer, SIGNAL(timeout()), this, SLOT(onTimeToReinitialize()));
    reinitializeTimer.start();
}

Daemon::~Daemon() {
    if (connector != nullptr)
        delete connector;
    if (todayBdays != nullptr) {
        clearQList(todayBdays);
    }
}

void Daemon::initializeTimers() {
    int updateInterval = SettingsDBManager::getUpdateInterval();
    qDebug() << updateInterval;
    updateTimer.setInterval(updateInterval);
    if (updateTimer.isActive() == false) {
        connect(&updateTimer, SIGNAL(timeout()), this, SLOT(onTimeToUpdate()));
        updateTimer.start();
    }
    initializeCongratulateTimer();
}

void Daemon::initializeCongratulateTimer() {
    //если сегодня никого не надо поздравлять, таймер запускать тоже нет смысла
    //но нужно активировать таймер, если пользователь добавил друга с ДР сегодня - не реализовано
    if (getTodayBdays() == true) {
        //получить интервал между обновлениями
        int congratulateInterval = SettingsDBManager::getCongratulateInterval();
        qDebug() << congratulateInterval;
        if (congratulateTimer.isActive() == false) {
            congratulateTimer.setInterval(congratulateInterval);
            connect(&congratulateTimer, SIGNAL(timeout()), this, SLOT(onTimeToCongratulate()));
        }

    }
}

//возвращает true, если список для поздравления не пустой
bool Daemon::getTodayBdays() {
    todayBdays = FriendsDBManager::getBdaysByDate(QDate::currentDate());
    if (todayBdays != nullptr)
        return true;
    else
        return false;
}
QString Daemon::prepareUrlForCongratulation(bool messageDest //true == wall, false == message
                                            ) {
    QString query;
    if (messageDest == true) {
        query =  QString::fromStdString(SettingsDBManager::getPostWallUrl());
    } else {
        query = QString::fromStdString(SettingsDBManager::getSendMessageUrl());
    }
    query.replace("access-token", QString::fromStdString(SettingsDBManager::getAuthToken()));
    return query;
}

void Daemon::sendCongratulations() {
    if (todayBdays == nullptr || todayBdays->isEmpty() == true)
        return;

    for (int iter = todayBdays->size() - 1; iter >= 0; -- iter) {
        FriendEntry currentFriendEntry = *(todayBdays->at(iter));
        //проверить, активен ли друг - не надо. пусть все обновления после перезагрузки
        //bool friendIsActiveFlag = FriendsDBManager::checkIfFriendIsActive(currentFriendEntry);
        //if (friendIsActiveFlag == false) {
        //    delete todayBdays->at(iter);
        //    todayBdays->removeAt(iter);
        //}

        //проверить, куда отправлять сообщение (стена = true, личка = false)
        bool messageDest = SettingsDBManager::getMessageDestination();
        QString query = prepareUrlForCongratulation(messageDest);
        NetworkResult result = Network::sendCongratulations(currentFriendEntry, query);

        if (result.isValid == true) {
            QList<QString>* captchaInf = Network::captchaNeeded(result.result);
            if (captchaInf == nullptr) {
                BdaysDBManager::logSuccessfullCongratulation(currentFriendEntry);
                delete todayBdays->at(iter);
                todayBdays->removeAt(iter);
            }
            else if (captchaInf->size() == CAPTCHA_ARGS_NUMBER) {//иначе произошла неизвестная ошибка, будем пробовать позже
                //загрузить картинку
                //спросить капчу у пользователя
                //послать на сервер ответ
                //если пришла ошибка - повторить
                //Network::SavePic(captchaInf->at(0), QString::fromStdString(IMG_FILE(std::string("error"))));
                //QProcess *captchaProc = new QProcess();
                //QString
                //captchaProc->start(CAPTCHA_PROCESS);
                int trialCounter = 0;
                while (trialCounter < MAX_TRIES) {
                    qDebug() << "Loading captcha: " << captchaInf->at(0);
                    std::string img = SettingsDBManager::getIMGPath() + "error.jpg";
                    Network::SavePic(captchaInf->at(0), QString::fromStdString(img));
                    QProcess captchaProc;
                    captchaProc.start(SettingsDBManager::getCaptchaProgram());
                    captchaProc.waitForReadyRead();
                    if (captchaProc.atEnd() == true) {
                        qDebug() << "Captcha process stopped";
                        break;
                    }
                    QByteArray captchaCode = captchaProc.readAllStandardOutput();
                    //if (captchaCode.isEmpty() == false) {
                    QString code(captchaCode);
                    QString query = prepareUrlForCongratulation(messageDest);
                    result = Network::sendCongratulations(currentFriendEntry,
                                                          query,
                                                          "&captcha_key=" + code +"&captcha_sid=" + captchaInf->at(1));
                    if (result.isValid == false)
                        break;
                    else {
                        qDebug() << "Result with captcha is valid";
                        delete captchaInf;
                        captchaInf = Network::captchaNeeded(result.result);
                        if (captchaInf == nullptr) {
                           qDebug() << "Result with captcha has no errors";
                           BdaysDBManager::logSuccessfullCongratulation(currentFriendEntry);
                           delete todayBdays->at(iter);
                           todayBdays->removeAt(iter);
                           captchaProc.kill();
                           break;
                       }
                    }
                    ++trialCounter;
                    captchaProc.kill();
                }
                //captchaProc->terminate();
                //delete captchaProc;
                //cpatchaProc->deleteLater();

            }

        }
        std::this_thread::sleep_for(std::chrono::milliseconds(TIMEOUT));
    }
    //если всех поздравили - отановить таймер
    if (todayBdays->isEmpty()) {
        congratulateTimer.stop();
    }
}


void Daemon::updateFriendsInfo() {
    QString urlString = QString::fromStdString(SettingsDBManager::getFriendsUrl());
    urlString.replace("access-token", QString::fromStdString(SettingsDBManager::getAuthToken()));
    urlString.replace("user-id", QString::fromStdString(SettingsDBManager::getUserId()));
    QList<FriendEntry*>* friends = Network::getFriends(urlString);
    if (friends != nullptr && friends != NULL) {
        //нужно проверять наличие новых друзей с ДР сегодня и добавлять их в список для поздравления
        //для корректной работы нужно ловить уведомлений об изменении шаблонов пользователем
        bool friendsHadChanged = FriendsDBManager::updateFriendsList(friends);
        if (friendsHadChanged == true) {
            //qDebug() << "FriendsHasChanged";
            connector->connectAndAnnounce("Friends");
            connector->connectAndAnnounce("Bdays");
        }
        clearQList(friends);
    }

}
//нужно обнавлять раз в сутки
void Daemon::updateMissedBdaysInfo() {
    bool hadChanges = BdaysDBManager::updateBdaysHistory();
    if (hadChanges == true)
        connector->connectAndAnnounce("Bdays");
}

void Daemon::onTimeToUpdate() {
    qDebug() << "Its time to update";
    updateFriendsInfo();
}

void Daemon::onTimeToCongratulate() {
    qDebug() << "Its time to send";
    sendCongratulations();
}

void Daemon::onTimeToReinitialize() {
    qDebug() << "Its time to reinitialize";
    initialize();
}

void Daemon::onBdaysHaveChanged() {
    qDebug() << "Daemon: Bdays have changed";
    //очистить предыдущий список поздравлений
    if (todayBdays != nullptr)
        clearQList(todayBdays);
    //получить новый списко поздралений
    todayBdays = FriendsDBManager::getBdaysByDate(QDate::currentDate());
    //выставить таймеры
    initializeCongratulateTimer();
    //сразу же попытаться поздравить
    sendCongratulations();

}

 void Daemon::initialize() {
     //ловить сигнал изменения шаблонов
     //если сигнал пришел - перегружаем список todaybdays и внепланово поздравляем
     QObject::connect(connector, SIGNAL(bdaysInfoHasChanged()), this, SLOT(onBdaysHaveChanged()));
     qDebug() << "conneted";
     updateMissedBdaysInfo();
     updateFriendsInfo();
     initializeTimers();
     sendCongratulations();
 }



