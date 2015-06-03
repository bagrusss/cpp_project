import QtQuick 1.1

Rectangle {
    id: main;
    width: 480;
    height: 640;
    Loader {
        anchors.bottom: parent.bottom
        id: mainloader;
        Component.onCompleted: {
            //console.log(AuthManager.wasAuthenticatedFlag)
            if (AuthManager.wasAuthenticatedFlag == true) {
                mainloader.source = "AuthorizedMainView.qml"
            } else {
                mainloader.source = "VkAuth.qml"
            }
        }
    }
    signal loadAuthorizedView();

    onLoadAuthorizedView: {
        mainloader.source = "AuthorizedMainView.qml"
    }
}
