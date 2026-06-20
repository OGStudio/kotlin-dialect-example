import QtQuick
import QtQuick.Controls
import helloworld

Window {
    height: 480
    id: wnd
    title: qsTr("Hello World")
    visible: true
    width: 640

    MainView {
        anchors.fill: parent
    }
}
