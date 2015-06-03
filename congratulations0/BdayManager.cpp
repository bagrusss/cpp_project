#include "BdayManager.h"
#define TODAY_BACKGROUND_COLOR "#d32f2f"
#define TODAY_BORDER_COLOR "#c93838"
#define TODAY_TEXT_COLOR "#ffffff"

#define NOT_TODAY_BACKGROUND_COLOR "#eeeeee"
#define NOT_TODAY_BORDER_COLOR "#dddddd"
#define NOT_TODAY_TEXT_COLOR "#383838"


BdayManager::BdayManager(QObject *parent): Manager(BdaysDBManager::Instance(), parent)  {
    //dbManager = std::make_shared<DBManager>(BdaysDBManager::Instance());
    roles[PhotoRole] = "photo";
    roles[ColorRole] = "backgroundColor";
    roles[BorderColorRole] = "borderColor";
    roles[TextColorRole] = "textColor";
    roles[NameRole] = "name";
    roles[DateRole] = "date";
    roles[MissedFlagRole] = "isMissed";
}



QHash<int, QByteArray> BdayManager::roleNames() const {
    return roles;
}



QVariant BdayManager::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || index.row() > listEntries->count()) {
        return QVariant();
     }
    BdayEntry *bdayEntry = reinterpret_cast<BdayEntry*>(listEntries->at(index.row()));
    QVariant result;
    QString color;
    switch(role) {
    case PhotoRole:
        result = QVariant::fromValue(bdayEntry->photo);
        break;
    case ColorRole:
        if (bdayEntry->isToday)
            color = TODAY_BACKGROUND_COLOR;
        else
            color = NOT_TODAY_BACKGROUND_COLOR;
        result = QVariant::fromValue(color);
        break;

    case BorderColorRole:
        if (bdayEntry->isToday)
            color = TODAY_BORDER_COLOR;
        else
            color = NOT_TODAY_BORDER_COLOR;
        result = QVariant::fromValue(color);
        break;

    case TextColorRole:
        if (bdayEntry->isToday)
            color = TODAY_TEXT_COLOR;
        else
           color = NOT_TODAY_TEXT_COLOR;
        result = QVariant::fromValue(color);
        break;

    case NameRole:
        result = QVariant::fromValue(bdayEntry->name);
        break;
    case DateRole:
        result = QVariant::fromValue(bdayEntry->date);
        break;
    case MissedFlagRole:
        result = QVariant::fromValue(bdayEntry->isMissed);
        break;
    }
    return result;
}

void BdayManager::onDbaseInfoGetChanged() {
    beginResetModel();
    clearQList(listEntries);
    listEntries = dbManager->getAllElements(&firstDisplayedElement);
    endResetModel();
    /*//получить время последнего обновления
    uint lastUpdatedTimestamp = dbCommunicationStrategy.getLastTimestamp();

    //получить список новых обновлений
    auto recentlyUpdatedListHash = dbManager->getRecentlyUpdatedElements(lastUpdatedTimestamp);

    if (recentlyUpdatedListHash != nullptr) {
        dbCommunicationStrategy.updateCurrentList(
               listEntries,
               recentlyUpdatedListHash,
               BdayEntry::dateIsLess); //функция сортировки элементов
                                       //влияет на порядок добавления обновлений

        //очистить recentlyUpdatedListHash
        clearQHash(recentlyUpdatedListHash);
    }*/
}

