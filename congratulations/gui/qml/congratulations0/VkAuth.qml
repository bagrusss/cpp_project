import QtQuick 1.1
import QtWebKit 1.0

Rectangle {
    width: 480
    height: 640

    WebView {
        id :authView
        url: AuthManager.authenticationUrl
        height: 640
        width: 480
        preferredHeight: parent.height
        preferredWidth: parent.width
        scale: 0.5
        smooth: false
        signal authorizationComplete()
        onAuthorizationComplete: {
            //сохранить access token в файле настроек
            //послать сообщение о перегрузке страницы
            if (AuthManager.authIsValid(url)) {
                AuthManager.storeAuthToken(url);
                main.loadAuthorizedView();
            }
        }

        Component.onCompleted: {
            authView.urlChanged.connect(authorizationComplete);
        }
    }
}
