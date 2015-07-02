            #include "manager.h"

Manager::Manager(DBManager* manager, QObject *parent):
        QAbstractListModel(parent), dbManager(manager), listEntries(nullptr) {}

Manager::Manager(std::shared_ptr<DBManager> manager,QObject *parent = 0):QAbstractListModel(parent), dbManager(manager), listEntries(nullptr) {}

Manager::~Manager() {
    if (listEntries != nullptr) {
        //clearQList(listEntries);
    }
}

void Manager::initialize(QmlApplicationViewer& viewer, const QString& modelName) {
    //зарегистрировать модель для работы с QML
    viewer.rootContext()->setContextProperty(modelName, this);
    QObject::connect(this, SIGNAL(deleteElement(int)), this, SLOT(onDeleteElement(int)));
    //нициализировать список модели
    if (listEntries == nullptr)
        listEntries = dbManager->getAllElements(&firstDisplayedElement);
}

int Manager::rowCount(const QModelIndex &parent) const {
    if (listEntries != nullptr)
        return listEntries->size();
    else
        return 0;
}

int  Manager::getFirstDisplayedElement() {
    return firstDisplayedElement;
}



