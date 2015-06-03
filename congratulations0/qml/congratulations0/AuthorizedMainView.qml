import QtQuick 1.1

Rectangle {
    width: 480
    height: 640

    MainWindow {
        id: mainWindow;
        anchors.top: parent.top;
    }

    Footer {
        id: footerMenu;
        anchors.bottom: parent.bottom;
        signal iconClicked(string iconName);
        onIconClicked: {
            mainWindow.loaderSource = iconName + "ListView.qml"
        }
    }
}
