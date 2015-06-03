#include "dbmanager.h"
#define DAYS_IN_MONTH 31
#define MONTH_IN_YEAR 12

DBManager* BdaysDBManager::_self = nullptr;
DBManager* FriendsDBManager::_self = nullptr;
DBManager* SettingsDBManager::_self = nullptr;
DBManager* TemplatesDBManager::_self = nullptr;
YAML::Node SettingsDBManager::config  = YAML::LoadFile(SETTINGS_FILE);

//DBManager methods:
//void DBManager::deleteElements(const QList<int>& deletedElements) {
    //return true;
//}


//QHash<int, QList<AbstractListEntry*>*>* DBManager::getRecentlyUpdatedElements(const uint& timestamp) {
 //   return nullptr;
//
//void DBManager::updateElements(QList<AbstractListEntry*>* changesList) {}

//void DBManager::insertElements(QList<AbstractListEntry*>*  changesList) {}


//BdaysBDManager functions:
QList<AbstractListEntry*>* BdaysDBManager::getAllElements(int* state) {
    if (state == nullptr)
        *state = 0;
    QList<AbstractListEntry*> * bdays = new QList<AbstractListEntry*>;
    //attachDB(DAEMON_DB);
    std::vector<std::vector<std::string>> result = std::move(select("Friends",
                                                                    {"id", "name", "day",
                                                                     "month",
                                                                     "is_missed"},
                                                                     "ORDER BY month, day"));
    QDate currentDate = QDate::currentDate();
    int currentDay = currentDate.day();
    int currentMonth = currentDate.month();
    int dayDiff = DAYS_IN_MONTH;
    int monthDiff = MONTH_IN_YEAR;

    for (int iter = 0; iter < result.size(); ++iter) {
        int day = std::stoi(result[iter].at(2));
        int month = std::stoi(result[iter].at(3));
        if (state != nullptr && state != NULL) {
            if (std::abs(month - currentMonth) < monthDiff) {
                monthDiff = std::abs(month - currentMonth);
                dayDiff = std::abs(day - currentDay);
                *state = iter;
            }
            if (std::abs(month - currentMonth) == monthDiff && std::abs(day - currentDay) < dayDiff) {
                //monthDiff = std::abs(month - currentMonth);
                //qDebug() << day << month;
                dayDiff = std::abs(day - currentDay);
                *state = iter;
            }
        }
        std::string img = SettingsDBManager::getIMGPathForQML() + result[iter].at(0) + ".jpg";
        bdays->append(new BdayEntry(QString::fromStdString(img), //фото
                                    (currentMonth == month && currentDay == day), //флаг др сегодня
                                    QString::fromStdString(result[iter].at(1)), //имя
                                    QString::fromStdString(result[iter].at(2) + " " + result[iter].at(3)), //день рождения
                                    (std::stoi(result[iter].at(4)) == 1) //был ли пропущен
                                    ));

    }
    //bdays->append(new BdayEntry("qrc:///src/6.jpg","#eeeeee","#dddddd","#383838","Катя Новикова","5 марта", true));
    //bdays->append(new BdayEntry("qrc:///src/5.jpg","#eeeeee","#dddddd","#383838","Саша Булгаков","21 марта", false));
    //bdays->append(new BdayEntry("qrc:///src/1.jpg","#d32f2f","#c93838","#ffffff","Анна Анна","сегодня", false));
    //bdays->append(new BdayEntry("qrc:///src/2.jpg","#eeeeee","#dddddd","#383838","Саша Блок","12 мая", false));
    //bdays->append(new BdayEntry("qrc:///src/3.jpg","#eeeeee","#dddddd","#383838","Аня Ахматова","1 июня", false));
    //bdays->append(new BdayEntry("qrc:///src/4.jpg","#eeeeee","#dddddd","#383838","Антон Просто","7 июня", false));
    //detachDB();
    return bdays;
}

DBManager* BdaysDBManager::Instance() {
    if (_self == nullptr) {
        _self =  new BdaysDBManager();
    }
    return _self;
}



//FRiendsDbManager functions
QList<AbstractListEntry*>* FriendsDBManager::getAllElements(int* state) {
    //connect();
    QList<AbstractListEntry*> * friends = new QList<AbstractListEntry*>;
    //attachDB(DAEMON_DB);
    std::vector<std::vector<std::string>> result = std::move(select("Friends",
                                                                    {"id", "name", "day",
                                                                     "month",
                                                                     "is_deleted",
                                                                     "is_missed"}));

    for (std::vector<std::vector<std::string>>::iterator rowIter = result.begin();
         rowIter != result.end();
         ++rowIter) {
        std::string img = SettingsDBManager::getIMGPathForQML() + rowIter->at(0) + ".jpg";
        friends->append(new FriendEntry(  std::stoi(rowIter->at(0)), //id
                                          QString::fromStdString(img), //фото
                                          QString::fromStdString(rowIter->at(1)), //имя
                                          QString::fromStdString(rowIter->at(2) + " " + rowIter->at(3)), //день рождения
                                          (std::stoi(rowIter->at(4)) == 1), //был ли удален
                                          (std::stoi(rowIter->at(5)) == 1) //был ли пропущен
                                          ));
        std::vector<std::vector<std::string>>  templateNumbers = std::move(select("Templates",
                                                                                     {"number"},
                                                                                    "WHERE id IN (select template_id FROM TemplateToFriend WHERE friend_id = " + rowIter->at(0) + ")"));
        if (templateNumbers.empty() == false) {
            FriendEntry* lastFriend = reinterpret_cast<FriendEntry*>(friends->at(friends->size() - 1));
            for (std::vector<std::vector<std::string>>::iterator iter = templateNumbers.begin();
                 iter != templateNumbers.end();
                 ++iter) {
                lastFriend->templateIds.append(std::stoi((*iter)[0]));
            }
        }
    }
    //нужно получить флаг isMissed!!
    //DBManager::close();
    //detachDB();
    return friends;
    //QList<AbstractListEntry*> * friends = new QList<AbstractListEntry*>;
    //friends->append(new FriendEntry("qrc:///src/6.jpg","Катя Новикова", "5 марта",/* "нет шаблона",*/ false , true, QList<int>({1,2,0})));
    //friends->append(new FriendEntry("qrc:///src/5.jpg","Саша Булгаков", "21 марта",/* "шаблон 1",*/false, false, QList<int>({3,2})));
    //friends->append(new FriendEntry("qrc:///src/1.jpg","Анна Анна","сегодня", /*"шаблон 2",*/ false, false, QList<int>({1,0})));
    //friends->append(new FriendEntry("qrc:///src/2.jpg","Саша Блок", "12 мая", /*"шаблон 3",*/false, false, QList<int>()));
    //friends->append(new FriendEntry("qrc:///src/3.jpg","Аня Ахматова","1 июня",/*"нет шаблона",*/ true, false, QList<int>({1,2,3})));
    //friends->append(new FriendEntry("qrc:///src/4.jpg", "Антон Просто","7 июня", /*"нет шаблона",*/ true, true, QList<int>()));
    //return friends;
}



//bool FriendsDBManager::checkIfFriendIsActive(const FriendEntry& friendEntry) {
//    return true;
//}

DBManager* FriendsDBManager::Instance() {
    if (_self == nullptr) {
        _self =  new FriendsDBManager();
    }
    return _self;
}

//TemplatesDBManager functions:
QList<AbstractListEntry*>* TemplatesDBManager::getAllElements(int* state) {
    //нужно проверять результат обращения к БД!!
    //DBManager::connect();
    std::vector<std::pair<std::string, std::string>> columns = {
        {"title", "text"},
        {"template_text", "text"}
    };

    DBManager::createTable("Templates", { {"title", "text"},
                                          {"template_text", "text"},
                                          {"number", "int default -1"}
                                         });
    createTriggers();
    QList<AbstractListEntry*> * templates = new QList<AbstractListEntry*>;

    std::vector<std::vector<std::string>> result = std::move(select("Templates",
                                                                    {"title", "template_text", "id"}));
    for (std::vector<std::vector<std::string>>::iterator rowIter = result.begin();
         rowIter != result.end();
         ++rowIter) {
        templates->append(new TemplateEntry(QString::fromStdString(rowIter->at(0)),
                                            QString::fromStdString(rowIter->at(1)),
                                            std::stoi(rowIter->at(2))));
    }
    //DBManager::close();
    return templates;
}

DBManager* TemplatesDBManager::Instance() {
    if (_self == nullptr) {
        _self =  new TemplatesDBManager();
    }
    return _self;
}


QList<AbstractListEntry*>* SettingsDBManager::getAllElements(int* state) {
    if (!config["settings-groups"])
        return nullptr; //ошибка конфига!
    YAML::Node settingsSet = config["settings-groups"];

    if (!config["time-dictionary"])
        return nullptr; //ошибка конфига!

    YAML::Node timeInf = config["time-dictionary"];

    QList<AbstractListEntry*> * settings = new QList<AbstractListEntry*>;

    for (YAML::iterator groupIter = settingsSet.begin();
         groupIter != settingsSet.end();
         ++groupIter) {
        YAML::Node settingsGroup = groupIter->second;
        std::string title(settingsGroup["group-title"]["title"].as<std::string>());
        settings->append(new SettingsEntry(QString::fromStdString(title)));

       // qDebug() << QString::fromStdString(groupIter->first.as<std::string>());

        for (YAML::iterator settingsIter = settingsGroup.begin();
             settingsIter != settingsGroup.end();
             ++settingsIter) {
            YAML::Node settingsInf = settingsIter->second;

            if (settingsInf["type"].as<std::string>() == "radio-button"){
                ListSettingsEntry* settingsEntry = new ListSettingsEntry();
                settingsEntry->name = settingsIter->first.as<std::string>();
                createSettingsEntry(settingsInf,
                                    timeInf,
                                    *settingsEntry);
                settings->append(settingsEntry);
            }
            if (settingsInf["type"].as<std::string>() == "switcher") {
                OffOnSettingsEntry* settingsEntry = new OffOnSettingsEntry();
                settingsEntry->name = settingsIter->first.as<std::string>();
                createSettingsEntry(settingsInf,
                                    *settingsEntry);
                settings->append(settingsEntry);
            }
        }
    }
    return settings;
}

void SettingsDBManager::updateElements(QList<AbstractListEntry*>* updatedElementsList){
    if (updatedElementsList == nullptr)
        return;
    for (int iter = 0; iter < updatedElementsList->size(); ++iter) {
        SettingsEntry * settingsEntry = reinterpret_cast<SettingsEntry*>(
                                            updatedElementsList->at(iter)
                                            );

        ListSettingsEntry* listSettingsEntry = nullptr;
        OffOnSettingsEntry* offOnSettingsEntry = nullptr;

        if (settingsEntry->state == LIST_ENTRY_STATE)  {
            listSettingsEntry = reinterpret_cast<ListSettingsEntry *>(settingsEntry);
            saveChangedSettings(config["settings-groups"], *listSettingsEntry);
        }
        else {
            offOnSettingsEntry = reinterpret_cast<OffOnSettingsEntry *>(settingsEntry);
            saveChangedSettings(config["settings-groups"], *offOnSettingsEntry);
        }
    }
}

bool SettingsDBManager::getMessageDestination() {
    YAML::Node messageDestNode = config["settings-groups"]["general-settings"]["how"];
    return (messageDestNode["selected-value-index"].as<int>() == 1);

}

int getTimeBySeletedNode(const YAML::Node& whenDoSmthNode,
                         const YAML::Node& timeInfo) {
    int selectedOptionIndex = whenDoSmthNode["selected-value-index"].as<int>();
    std::string selectedValue = whenDoSmthNode["values"][selectedOptionIndex].as<std::string>();
    return timeInfo[selectedValue]["number"].as<int>();
}

//интервал ожидания между попытками отправки сообщения
int SettingsDBManager::getCongratulateInterval() {
    YAML::Node whenCongratulateNode = config["settings-groups"]["general-settings"]["when-congratulate"];
    return getTimeBySeletedNode(whenCongratulateNode,
                                config["time-dictionary"]);

}

//интервал ожидания между попытками обновить инфу
int SettingsDBManager::getUpdateInterval() {
    YAML::Node whenUpdateNode = config["settings-groups"]["general-settings"]["when-update"];
    return getTimeBySeletedNode(whenUpdateNode,
                                config["time-dictionary"]);
}


DBManager* SettingsDBManager::Instance() {
    if (_self == NULL) {
        _self = new SettingsDBManager();
    }
    return _self;
}

std::string SettingsDBManager::getAuthToken() {
    std::string authToken;
    if (config["access-token"])
        authToken = config["access-token"].as<std::string>();
    return authToken;
}

std::string SettingsDBManager::getUserId() {
    //перезагрузить из файла
    std::string userId;
    if (config["user-id"])
        userId = config["user-id"].as<std::string>();
    return userId;
}

std::string SettingsDBManager::getAuthUrl() {
    //перезагрузить из файла
    std::string authUrl;
    if (config["auth-url"])
        authUrl = config["auth-url"].as<std::string>();
    return authUrl;
}

void SettingsDBManager::addSettings(const std::string& key, const std::string&value) {
    config[key] = value;
    //записать в файл сразу же!
    saveConfig();

}

std::string SettingsDBManager::getTemplateAuthUrl() {
    std::string templateAuthUrl;
    if (config["template-auth-url"])
        templateAuthUrl = config["template-auth-url"].as<std::string>();
    return templateAuthUrl;
}

std::string SettingsDBManager::getFriendsUrl() {
    std::string friendsUrl;
    if (config["friends-url"])
        friendsUrl = config["friends-url"].as<std::string>();
    return friendsUrl;
}

std::string SettingsDBManager::getSendMessageUrl() {
    std::string sendMessageUrl;
    if (config["send-message-url"])
        sendMessageUrl = config["send-message-url"].as<std::string>();
    return sendMessageUrl;
}

std::string SettingsDBManager::getPostWallUrl() {
    std::string postWallUrl;
    if (config["post-wall-url"])
        postWallUrl = config["post-wall-url"].as<std::string>();
    return postWallUrl;
}

std::string SettingsDBManager::getDBFile() {
    std::string dbFile;
    if (config["db-file"])
        dbFile = config["db-file"].as<std::string>();
    return dbFile;
}

std::string SettingsDBManager::getIMGPath() {
    std::string imgPath;
    if (config["img-path"])
        imgPath = config["img-path"].as<std::string>();
    return imgPath;
}
std::string SettingsDBManager::getIMGPathForQML() {
    std::string imgPath;
    if (config["img-path-for-qml"])
        imgPath = config["img-path-for-qml"].as<std::string>();
    return imgPath;
}

QString SettingsDBManager::getDateFormat() {
    std::string dateFormat;
    if (config["date-format"])
         dateFormat = config["date-format"].as<std::string>();
    return  QString::fromStdString(dateFormat);
}

QString SettingsDBManager::getDaemonProgram() {
    std::string daemonProgram;
    if (config["daemon-program"])
         daemonProgram = config["daemon-program"].as<std::string>();
    return  QString::fromStdString(daemonProgram);
}

QString SettingsDBManager::getCaptchaProgram() {
    std::string captchaProgram;
    if (config["captcha-program"])
         captchaProgram = config["captcha-program"].as<std::string>();
    return  QString::fromStdString(captchaProgram);
}
long long SettingsDBManager::getDaemonPid() {
    long long daemonPid = -1;
    if (config["daemon-pid"])
        daemonPid = config["daemon-pid"].as<long long>();
    return daemonPid;
}

QDate SettingsDBManager::getLastUpdateDate() {
    QDate lastDate;
    std::string lastDateStr;
    if (config["last-updated-date"])
        lastDateStr = config["last-updated-date"].as<std::string>();
    if (lastDateStr.empty() == false) {
        QString lastDateQStr = QString::fromStdString(lastDateStr);
        lastDate.setDate(lastDateQStr.section("-", 0, 0).toInt(),
                         lastDateQStr.section("-", 1, 1).toInt(),
                         lastDateQStr.section("-", 2, 2).toInt());
    }

}

void SettingsDBManager::setLastUpdateDate(const QDate& currentDate) {
    config["last-updated-date"] = currentDate.toString(SettingsDBManager::getDateFormat()).toStdString();
}

