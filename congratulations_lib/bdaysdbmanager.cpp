#include "dbmanager.h"
#include "clearmemoryhelpers.h"

//получить дату последнего обновления
//кто выставляет эту дату??
//получить список всех непоздравленных
//если он не пуст, обновить инфу в БД
//если прошло полгода с ДР, снять флаг пропущенного
bool BdaysDBManager::updateBdaysHistory() {
    bool wasUpdatedFlag = false;
    QDate lastUpdatedDate = SettingsDBManager::getLastUpdateDate();
    qDebug() <<  lastUpdatedDate.toString();
    QDate currentDate = QDate::currentDate();
    DBManager* manager = BdaysDBManager::Instance();
    manager->createTable("Congratulations", { {"friend_id", "int"},
                                              {"date", "text"},
                                         });
    if (lastUpdatedDate.isValid()) {
        wasUpdatedFlag = true;
        std::string whereClause = "WHERE day < "+ std::to_string(currentDate.day()) +
                              " AND day >= "+ std::to_string(lastUpdatedDate.day()) +
                              " AND month <= "+ std::to_string(currentDate.month()) +
                              " AND month >= "+ std::to_string(lastUpdatedDate.month()) +
                " AND id NOT IN (select friend_id FROM Congratulations WHERE date >= '" + lastUpdatedDate.toString(SettingsDBManager::getDateFormat()).toStdString() +
                "' and date < '" + currentDate.toString(SettingsDBManager::getDateFormat()).toStdString() + "');";
         manager->updateHelper("Friends",
                              std::vector<std::pair<std::string, std::string>>({{"is_missed", "1"}}),
                              std::move(whereClause));
        //условие того, что с ДР прошло пол года
        whereClause = "WHERE abs(month - " + std::to_string(currentDate.month()) + ") >= 6;";
        manager->updateHelper("Friends",
                             std::vector<std::pair<std::string, std::string>>({{"is_missed", "0"}}),
                             std::move(whereClause));
    }
    SettingsDBManager::setLastUpdateDate(currentDate);
    return wasUpdatedFlag;
}

 void BdaysDBManager::logSuccessfullCongratulation(const FriendEntry& currentFriendEntry) {
      QDate currentDate = QDate::currentDate();
      DBManager* manager = BdaysDBManager::Instance();
      manager->insert("Congratulations",
                     {"friend_id", "date"},
                     std::vector<std::vector<std::string>>({{std::to_string(currentFriendEntry.id), currentDate.toString(SettingsDBManager::getDateFormat()).toStdString() }}));

 }
