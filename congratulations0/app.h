#ifndef APP_H
#define APP_H


#include "qmlapplicationviewer.h"
#include "BdayManager.h"
#include "friendsmanager.h"
#include "templatemanager.h"
#include "personaltemplatemanager.h"
#include "settingsmanager.h"
#include "dbusconnector.h"
#include "vkauthviewmanager.h"

#include <QApplication>
#include <QtDeclarative>

// Одиночка
class App: public QApplication
{
public:
    static App*& getInstance(int& argc, char * argv[]);
    ~App();

    /*инициализация моделей для вьюшек
      инициализация ApplicationViewer
      запуск event loop*/
    int startGUI();

private:
    App(int& argc, char * argv[]);
    //для взаимодействия по dbus с процессом демона
    DBusConnector* connector;
    static App* instance;
};

#endif // APP_H
