#ifndef DAEMON_H
#define DAEMON_H

#include <QCoreApplication>
#include <QTimer>

#include "../congratulations0/dbusconnector.h"
#include "dbmanager.h"
#include "network.h"
#include "listelement.h"
#include "clearmemoryhelpers.h"

#include <chrono>
#include <thread>

#define CALENDAR_DAY 86400000 //кол-во миллисекунд в сутках
#define TIMEOUT 30000 //таймаут между поздравлениями в миллисекундах
#define MAX_TRIES 10 //максимальное количество попыток
#define CAPTCHA_ARGS_NUMBER 2 //количество аргументов для капчи
//#define CAPTCHA_PROCESS "/opt/Qt5.1.1/Tools/QtCreator/bin/build-congratulations_captcha-Desktop_Qt_5_1_1_GCC_64bit-Debug/congratulations_captcha" //приложение для ввода капчи
class Daemon: public QCoreApplication {
    Q_OBJECT

public:
    Daemon(int& argc, char * argv[]);
    ~Daemon();

    void initialize();

public slots:
    void onTimeToUpdate();
    void onTimeToCongratulate();
    void onTimeToReinitialize();
    void onBdaysHaveChanged();

private:
    //для соединения с GUI
    DBusConnector* connector;

    //список тех, кого нужно сегодня поздравить
    QList<FriendEntry*>* todayBdays;

    //таймеры
    QTimer updateTimer;
    QTimer congratulateTimer;
    QTimer reinitializeTimer;

    //менеджеры ДБ - не храним!!! каждый из них может существовать только в единственном экземпляре


    //берет настройки(частота проверки обновлений и промежуток между поздравлениями) из БД и иницализирует таймеры
    //забирает список для поздравления
    void initializeTimers();

    //получить список дней рождения, которых нужно поздравить сегодня
    bool getTodayBdays();

    //разослать поздравления из списка
    void sendCongratulations();

    //проверить, появились ли новые друзья
    //и изменилась информация о старых
    void updateFriendsInfo();

    //обновить информацию о пропущенных ДР друзей.
    //раз в день обновляем за предыдущий
    void updateMissedBdaysInfo();

    void initializeCongratulateTimer();
    QString prepareUrlForCongratulation(bool);

};


#endif // DAEMON_H
