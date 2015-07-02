#include "app.h"

Q_DECL_EXPORT int main(int argc, char *argv[]) {
    return App::getInstance(argc, argv)->startGUI();
}
