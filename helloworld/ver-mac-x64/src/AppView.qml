import QtQuick
import QtQuick.Controls

Window {
    height: 480
    id: wnd
    title: qsTr("Hello World")
    visible: true
    width: 640

    Rectangle {
        height: wnd.height
        id: mainView
        visible: vm.mainIsVisible
        width: wnd.width

        Text {
            anchors.horizontalCenter: mainView.horizontalCenter
            font.bold: true
            font.pointSize: 24
            text: vm.mainGreetingText
            y: 30
        }

        Button {
            anchors.horizontalCenter: mainView.horizontalCenter
            onClicked: api.mainSet(F.didClickChangeText, true)
            text: "Change text"
            y: 100
        }
    }
}
