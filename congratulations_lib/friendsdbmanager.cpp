#include "dbmanager.h"
#include "clearmemoryhelpers.h"

void FriendsDBManager::updateElements(QList<AbstractListEntry*>* list) {
    if (list == nullptr)
        return;
    //нужно добавлять шаблоны!!
    //может стоит создавать таблицу 1 раз, по какому-ниудь условию?
    //DBManager::connect();
    DBManager::createTable("TemplateToFriend", { {"template_id", "int"},
                                                 {"friend_id", "int"}
                                         });

    for (int iter = 0; iter < list->size(); ++iter) {
        FriendEntry* currentEntry = reinterpret_cast<FriendEntry*>(list->at(iter));
        if (currentEntry != nullptr) {
            //изменить флаг удаления
            //изменить шаблоны
            update("Friends",
                    {{"is_deleted", std::to_string(int(currentEntry->isDeleted))}},
                     currentEntry->id
                   );

            deleteBy("friend_id", "TemplateToFriend", std::list<int>({currentEntry->id}));
            if (currentEntry->templateIds.isEmpty() == false) {
                std::string templateNumbersList = std::to_string(currentEntry->templateIds.at(0));
                for (int templateIter = 1; templateIter <  currentEntry->templateIds.size(); ++templateIter)
                    templateNumbersList += ", " + std::to_string(currentEntry->templateIds.at(templateIter));
                //std::string currentEntryId = "'" + std::to_string(currentEntry->id) + "'";
                //qDebug() << QString::fromStdString(currentEntryId);
                insertWithSubquery("TemplateToFriend",
                                       {"friend_id", "template_id"},
                                       "Templates",
                                       {"'" + std::to_string(currentEntry->id) + "'", "id"},
                                       "WHERE number IN ("+ templateNumbersList +")");
            //insert("TemplateToFriend", {"friend_id", "template_id"}, std::move(values));
           }
        }
    }
    //DBManager::close();
}


void FriendsDBManager::insertElements(QList<FriendEntry*>* list) {
    if (list == nullptr)
        return;

    //может стоит создавать таблицу 1 раз, по какому-ниудь условию?
    //DBManager::connect();
    DBManager::createTable("Friends", {   {"name", "text"},
                                          {"day", "int"},
                                          {"month", "int"},
                                          {"is_deleted", "int default 0"},
                                          {"photo", "text"},
                                          {"is_missed", "int default 0"}
                                         });

    std::vector<std::vector<std::string>> values;
    for (int iter = 0; iter < list->size(); ++iter) {
        FriendEntry* currentEntry = reinterpret_cast<FriendEntry*>(list->at(iter));
        //qDebug() << currentEntry->text;
        values.emplace_back(std::vector<std::string>({std::to_string(currentEntry->id),
                                                      currentEntry->name.toStdString(),
                                                      std::to_string(currentEntry->day),
                                                      std::to_string(currentEntry->month),
                                                      currentEntry->photo.toStdString()
                                                     })) ;
    }
    //проверить результат - бросить исключение?
    insert("Friends", {"id", "name", "day",
                       "month", "photo"}, std::move(values));
    //DBManager::close();
}

void FriendsDBManager::deleteElements(const QList<int>& deletedIds) {
    //DBManager::connect();
    deleteById("Friends",
               deletedIds.toStdList()
           );
    //DBManager::close();
}

bool FriendsDBManager::updateFriendsList(QList<FriendEntry*>* friends) {
    //проверить, новый ли друг
    //если да, загрузить фото
    //и поместить в БД
    //1) найти все img, которые либо изменились, либо новые
    //2) загрузить фото
    //проверять по одной и обновлять!

    if (friends == NULL || friends == nullptr)
        return false;

    //qDebug() << friends->size();

    DBManager* manager = FriendsDBManager::Instance();
    std::list<int> ids;
    if (friends->isEmpty() == false) {
         for(int iter = 0; iter < friends->size(); ++iter) {
             //qDebug() << friends->at(iter)->id;
             std::string where_clause = " WHERE id = " + std::to_string(friends->at(iter)->id) + " AND photo = '" + friends->at(iter)->photo.toStdString() +"'";
             std::vector<std::vector<std::string>> result = manager->select("Friends", std::vector<std::string>({"id"}), where_clause);
             if (result.empty() == true) {
                 std::string img = SettingsDBManager::getIMGPath() + std::to_string(friends->at(iter)->id) + ".jpg";
                 Network::SavePic(friends->at(iter)->photo,
                                  QString::fromStdString(img));
             }
             ids.push_back(friends->at(iter)->id);
         }
    }
    manager->deleteBy(" id NOT ", "Friends", std::move(ids)); //баг - любая ошибка сети и друзья удалены.
    reinterpret_cast<FriendsDBManager*>(manager)->insertElements(friends);
    //clearQList(friends);
    return true; //как проверить, было ли обновление??
}

QList<FriendEntry*>* FriendsDBManager::getBdaysByDate(const QDate& date){
    DBManager* manager = FriendsDBManager::Instance();
    //manager.attachDB(GUI_DB);
    std::string where_clause = " WHERE Friends.id NOT IN (SELECT friend_id FROM Congratulations WHERE date = '" + date.toString(SettingsDBManager::getDateFormat()).toStdString() + "') AND Friends.is_deleted = 0 AND Friends.day = '" + std::to_string(date.day()) +
            "' AND Friends.month = '" + std::to_string(date.month()) + "'";
    std::vector<std::vector<std::string>> result = manager->select(
                "Friends",
                std::vector<std::string>({"id"}), where_clause);
    //manager.detachDB();

    if (result.empty() == false) {
        QList<FriendEntry*>* friends = new QList<FriendEntry*>();
        for (int iter = 0; iter < result.size(); ++iter) {
            std::vector<std::vector<std::string>> template_text = manager->select(
                        "Templates JOIN TemplateToFriend ON Templates.id = TemplateToFriend.template_id",
                        std::vector<std::string>({"Templates.template_text"}),
                        "WHERE TemplateToFriend.friend_id = " + result[iter].at(0) + " ORDER BY RANDOM() LIMIT 1");

            if (template_text.empty() == false && template_text.at(0).empty() == false)
                    friends->append(new FriendEntry(std::stoi(result[iter].at(0)),
                                                    QString::fromStdString(template_text[0].at(0))));
        }        
        return friends;
    }
    else return nullptr;
}
