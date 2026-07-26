import QtQuick
import QtQuick.Controls
import hellolist

Window {
    height: 480
    id: wnd
    title: qsTr("Hello List")
    visible: true
    width: 640

    RootView {
        anchors.fill: parent
    }
}
