import QtQuick 1.1

Rectangle {
    id: main
    width: 400
    height: 400
    Text {
        id: header
        font {pixelSize: 14; bool: true}
        text: "Для отправки сообщения ввелите капчу"
        anchors {horisontalCenter: parent.horizontalCenter;
            top: parent.top; topMatgin: 10}

    }

    Image {
        id: captchaImage
        source: CaptchaView.captchaImage
        height: 50
        width: 130
        anchors {horisontalCenter: parent.horizontalCenter;
            top: header.top; topMatgin: 10}
    }

    TextInput {
        id: captchaText
        anchors { horisontalCenter: parent.horizontalCenter;
            top: captchaImage.top; topMatgin: 10}
        width: 300
        onAccepted: {
            CaptchaView.writeResult(captchaText.text);
        }

    }
}
