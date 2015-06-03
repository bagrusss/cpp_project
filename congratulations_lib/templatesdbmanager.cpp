#include "dbmanager.h"
#include "clearmemoryhelpers.h"

void TemplatesDBManager::updateElements(QList<AbstractListEntry*>* list) {
    if (list == nullptr)
        return;

    for (int iter = 0; iter < list->size(); ++iter) {
        TemplateEntry* currentEntry = reinterpret_cast<TemplateEntry*>(list->at(iter));
        if (currentEntry != nullptr) {
            //проверить результат - бросить исключение?
            update("Templates",
                    {{"template_text", currentEntry->text.toStdString()},
                     {"title", currentEntry->title.toStdString()}},
                    currentEntry->id
                   );
        }

    }
}

void TemplatesDBManager::insertElements(QList<AbstractListEntry*>* list) {
    if (list == nullptr)
        return;
    std::vector<std::vector<std::string>> values;
    for (int iter = 0; iter < list->size(); ++iter) {
        TemplateEntry* currentEntry = reinterpret_cast<TemplateEntry*>(list->at(iter));
        //qDebug() << currentEntry->text;
        values.emplace_back(std::vector<std::string>({currentEntry->text.toStdString(),
                                                      currentEntry->title.toStdString()})) ;
    }
    //проверить результат - бросить исключение?
    insert("Templates", {"template_text", "title"}, std::move(values));
}

void TemplatesDBManager::deleteElements(const QList<int>& deletedIds) {
    deleteBy("id",
             "Templates",
             deletedIds.toStdList()
           );
}

void TemplatesDBManager::createTriggers() {
    std::string insertTrigger = "CREATE TRIGGER IF NOT EXISTS on_template_insert AFTER INSERT ON Templates BEGIN UPDATE Templates SET number = (SELECT max(number) + 1 FROM Templates) WHERE number = -1; END;";
    std::string deleteTrigger = "CREATE TRIGGER IF NOT EXISTS on_template_delete AFTER DELETE ON Templates BEGIN UPDATE Templates SET number = number - 1 WHERE number > OLD.number; END;";

    executeQueryWithoutResult(insertTrigger);
    executeQueryWithoutResult(deleteTrigger);
}
