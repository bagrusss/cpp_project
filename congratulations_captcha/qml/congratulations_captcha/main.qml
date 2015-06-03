import QtQuick 1.1

Rectangle {
    id: main
    width: 400
    height: 200
    Text {
        id: header
        font {pixelSize: 14; bold: true}
        text: "Для отправки сообщения введите капчу"
        anchors {horizontalCenter: parent.horizontalCenter;
            top: parent.top; topMargin: 15}

    }

    Image {
        id: captchaImage
        source: CaptchaView.captchaImage
        height: 50
        width: 130
        anchors {horizontalCenter: parent.horizontalCenter;
            top: header.bottom; topMargin: 15}
    }
    Rectangle {
        id: textInputWrapper
        anchors { horizontalCenter: parent.horizontalCenter;
            top: captchaImage.bottom; topMargin: 15}
        width: 300
        border {width: 2; color: "#cccccc"}
        height: 30
        TextInput {
            id: captchaText
            onAccepted: {
                CaptchaView.writeResult(captchaText.text);
            }
            anchors { top: parent.top; left: parent.left}
            width: parent.width
         }
    }
}
