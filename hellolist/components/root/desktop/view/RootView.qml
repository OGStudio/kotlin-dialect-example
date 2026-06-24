import QtQuick
import QtQuick.Controls

Rectangle {
    id: rootView
    visible: vm.rootIsVisible

    Text {
        anchors.horizontalCenter: rootView.horizontalCenter
        font.bold: true
        font.pointSize: 24
        text: "TODO list"
        y: 30
    }

    Button {
        anchors.horizontalCenter: rootView.horizontalCenter
        onClicked: api.rootSet(F.didClickAddItem, true)
        text: "Add item"
        y: 100
    }

    ListView {
        anchors.horizontalCenter: rootView.horizontalCenter
        y: 150
        width: parent.width
        height: parent.height - 150
        model: vm.rootItems
        delegate: Text {
            text: modelData
            padding: 8
        }
    }
}
