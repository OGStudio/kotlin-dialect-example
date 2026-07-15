import QtQuick
import QtQuick.Controls

Rectangle {
    id: mainView
    visible: vm.mainIsVisible

    Text {
        anchors.horizontalCenter: mainView.horizontalCenter
        font.bold: true
        font.pointSize: 24
        text: vm.mainGreetingText
        y: 30
        Accessible.role: Accessible.StaticText
        Accessible.name: vm.mainGreetingText
        objectName: "greeting_text"
    }

    Button {
        anchors.horizontalCenter: mainView.horizontalCenter
        onClicked: api.mainSet(F.didClickChangeText, true)
        text: "Change text"
        y: 100
        Accessible.role: Accessible.Button
        Accessible.name: "change_text_button"
        objectName: "change_text_button"
    }
}
