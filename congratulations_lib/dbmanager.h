#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "listelement.h"
#include "network.h"

#include <QHash>
#include <QDebug>
#include <QPixmap>
#include <cmath>
#include <QDate>

#include "sqlite/sqlite3.h"

#define TEST_INTERVAL 1000 //тестовый интервал между обращениями к сети в мс
                           //удалить!

#define SETTINGS_FILE "../config.yaml"
//#define DB_FILE (SettingsDBManager::getDBFile()) //"/opt/Qt5.1.1/Tools/QtCreator/bin/congratulations_lib/Database.sqlite"
//#define IMG_FILE(id) (SettingsDBManager::getIMGPath() + id + ".jpg") //("/opt/Qt5.1.1/Tools/QtCreator/bin/images/" + id + ".jpg")
//#define DAEMON_DB "/opt/Qt5.1.1/Tools/QtCreator/bin/build-daemon0-Desktop_Qt_5_1_1_GCC_64bit-Debug/Database.sqlite"
//#define GUI_DB "/opt/Qt5.1.1/Tools/QtCreator/bin/build-congratulations0-Desktop_Qt_5_1_1_GCC_64bit-Debug/Database.sqlite"
//#define DATE_FORMAT (SettingsDBManager::getDateFormat())//"yyyy-M-d"
//классы для работы с БД
//в БД должны быть следующие сущности:

//Друзья id(vk), имя, дата рождения, фото (взять и загрузить без преобразований), флаг активности (если сброшен - друга не поздравлять)
//Шаблоны id, название, текст
//Настройки id, текст настройки, выбранный id варианта
//Варианты настроек id, текст
//История поздравлений id, id друга, дата поздравления

//Связи
//Друзья-Шаблоны один ко многим
//Настройки - Варианты настроек один ко многим

//для упрощения работы с БД ввести избыточность:
//хранить в таблице друзей флаг пропуска БД. Если выставлен - предыдущий ДР был пропущен

//синглтон не нужен!!
class CONGRATULATIONS_LIBSHARED_EXPORT DBManager
{
public:
    static enum elementTypesEnum {
       insertedElements = 1,
       updatedElements = 2,
       deletedElements = 3
    } elementTypes;


    virtual ~DBManager() {
        DBManager::close();
    }


    //возвращает список всех элементов соответсвующей таблицы
    virtual QList<AbstractListEntry*>* getAllElements(int* state=nullptr) { return nullptr; }

    virtual void updateElements(QList<AbstractListEntry*>*) {}
    virtual void insertElements(QList<AbstractListEntry*>*) {}
    virtual void deleteElements(const QList<int>&) {}

    //virtual QHash<int, QList<AbstractListEntry*>*>* getRecentlyUpdatedElements(const uint& timestamp);
    //создать таблицу, если еще не создана
    bool createTable(const std::string&&,
                     const std::vector<std::pair<std::string, std::string>>&&);

    //insert
    bool insert(const std::string&&,
                const std::vector<std::string>&&,
                const std::vector<std::vector<std::string>>&&);

    bool insertWithSubquery(const std::string&&,
                            const std::vector<std::string>&& ,
                            const std::string&& ,
                            const std::vector<std::string>&&,
                            const std::string&& whereClause = "");
    //update
    bool update(const std::string&&,
                const std::vector<std::pair<std::string, std::string>>&&,
                int id);

    bool updateHelper(const std::string&& tableName,
                      const std::vector<std::pair<std::string, std::string>>&& valueNames,
                      const std::string&& whereClause = "");

    //delete
    bool deleteById(const std::string&& tableName,
                    const std::list<int>&& idNames) {
        return deleteBy("id", std::move(tableName), std::move(idNames));
    }

    bool deleteBy(const std::string&&,
                  const std::string&&,
                  const std::list<int>&&);

    //select
    std::vector<std::vector<std::string>>& select (const std::string&&,
                                                   const std::vector<std::string>&&,
                                                   std::string="");
protected:
    DBManager() {
        DBManager::connect();
    }

    sqlite3* database;

    //подключится к БД
    bool connect();
    //закрыть соединение
    void close();
    std::vector<std::vector<std::string>>& executeQuery (const std::string&);
    bool executeQueryWithoutResult (const std::string&);



    //void attachDB(const std::string& dbPath,
    //              const std::string& dbName = "attached_db");

    //void detachDB(const std::string& dbName = "attached_db");

private:
    DBManager(const DBManager&);
    DBManager& operator=(const DBManager&);

};


class CONGRATULATIONS_LIBSHARED_EXPORT BdaysDBManager: public  DBManager {
public:
    static DBManager* Instance();
    virtual ~BdaysDBManager() = default;

    //все события за один текущий год
    virtual QList<AbstractListEntry*>* getAllElements(int* state=nullptr);

    //обновить пропуски БД
    //должна вызывать хранимую процедуру
    //возвращает true, если изменения были, иначе - false
    static bool updateBdaysHistory();

    //добавить успешное поздравление в таблицу истории поздравлений
    static void logSuccessfullCongratulation(const FriendEntry&);

private:
    static DBManager* _self;
    BdaysDBManager() = default;

};



class CONGRATULATIONS_LIBSHARED_EXPORT FriendsDBManager: public  DBManager {
public:
    virtual ~FriendsDBManager() = default;
    static DBManager* Instance();

    virtual QList<AbstractListEntry*>* getAllElements(int* state=nullptr);
    virtual void updateElements(QList<AbstractListEntry*>*);
    virtual void insertElements(QList<FriendEntry*>*);
    virtual void deleteElements(const QList<int>&);

    //функция выбора друзей с др по дате
    //возвращает nullptr, если друзей нет
    static QList<FriendEntry*>* getBdaysByDate(const QDate& date);

    //функция добавления изменений в БД (обновить инфу из БД в соответсвии с полученным списком)
    //возвращает true, если изменения произошли
    static bool updateFriendsList(QList<FriendEntry*>*);

    //проверить, активен ли друг
    //static bool checkIfFriendIsActive(const FriendEntry&);



private:
    static DBManager* _self;
    FriendsDBManager() = default;

};

class CONGRATULATIONS_LIBSHARED_EXPORT TemplatesDBManager: public  DBManager {
public:
    virtual ~TemplatesDBManager() = default;
    static DBManager* Instance();
    virtual QList<AbstractListEntry*>* getAllElements(int* state=nullptr);
    virtual void updateElements(QList<AbstractListEntry*>*);
    virtual void insertElements(QList<AbstractListEntry*>*);
    virtual void deleteElements(const QList<int>&);
    void createTriggers();

private:
    static DBManager* _self;
    TemplatesDBManager() = default;

};

class CONGRATULATIONS_LIBSHARED_EXPORT SettingsDBManager: public  DBManager {
public:
    //сбрасывать изменения на диск при закрытии GUI
    //ОК, т.к. меняет только пользователь
    virtual ~SettingsDBManager() {
        saveConfig();
        //std::ofstream fout(SETTINGS_FILE); //что с исключениями???
        //fout << config;
    }

    virtual QList<AbstractListEntry*>* getAllElements(int* state=nullptr);
    virtual void updateElements(QList<AbstractListEntry*>*);

    static void saveConfig() {
        std::ofstream fout(SETTINGS_FILE); //что с исключениями???
        fout << config;
    }

    static void reloadConfig() {
        config  = YAML::LoadFile(SETTINGS_FILE);
    }

    static DBManager* Instance();

    //узнать, куда посылать сообщение
    //true - на стену, false -  личку
    static bool getMessageDestination();

    //интервал ожидания между попытками отправки сообщения
    static int getCongratulateInterval();

    //интервал ожидания между попытками обновить инфуHapp
    static int getUpdateInterval();

    //получить токен авторизации в вк из файла настроек
    static std::string getAuthToken();

    //получить адрес авторизации в вк из файла настроек
    static std::string getAuthUrl();

    //получить шаблон адреса успешной авторизации в вк из файла настроек
    static std::string getTemplateAuthUrl();

    //сохранить токен в файле настроек
    static void addSettings(const std::string& key, const std::string& value);

    //получить адрес запроса списска друзей
    static std::string getFriendsUrl();

    //получить id текущего пользователя
    static std::string getUserId();

    static QDate getLastUpdateDate();
    static void setLastUpdateDate(const QDate&);
    static std::string getSendMessageUrl();

    static std::string getPostWallUrl();
    //
    static std::string getDBFile();
    static std::string getIMGPathForQML();
    static std::string getIMGPath();
    static QString getDateFormat();
    static QString getDaemonProgram();
    static QString getCaptchaProgram();
    static long long getDaemonPid();
    //static YAML::Node& getCurrentConfig() {
    //    if (_self != nullptr)
    //    return reinterpret_cast<SettingsDBManager*>(_self)->config;
    //}

private:
    static DBManager* _self;
    static YAML::Node config;//  = YAML::LoadFile(SETTINGS_FILE);//={YAML::LoadFile(SETTINGS_FILE)};
    //SettingsDBManager() = default;
    SettingsDBManager() = default;

};

#endif // DBMANAGER_H
