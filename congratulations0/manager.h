#ifndef MANAGER_H
#define MANAGER_H

#include <QList>
#include <QAbstractListModel>
#include <QHash>
#include <QVariant>
#include <QModelIndex>
#include <qmlapplicationviewer.h>
#include <QDeclarativeContext>
#include <QTextStream>

#include "dbmanager.h"
#include "listelement.h"
#include "dbcommunicationstrategy.h"

#include "clearmemoryhelpers.h"

//кастомная ListModel
class Manager : public QAbstractListModel {
    Q_OBJECT

 public:
    Manager(DBManager* manager=nullptr, QObject *parent = 0);
    Manager(std::shared_ptr<DBManager> manager,QObject *parent = 0);

    ~Manager();

    //инициализировать список элементов и зарегистрировать менеджер в контексте Qml приложения
    virtual void initialize(QmlApplicationViewer& viewer, const QString& modelName);

    virtual int rowCount(const QModelIndex &parent) const;

    int getFirstDisplayedElement();

 signals:
    void deleteElement(int);

    
 protected:
    QHash<int, QByteArray> roles;
    std::shared_ptr<DBManager> dbManager;
    QList<AbstractListEntry*>* listEntries; //список отображаемых элементов
    int firstDisplayedElement;              //индекс элемента, который должен отображаться первым

};


#endif // MANAGER_H
