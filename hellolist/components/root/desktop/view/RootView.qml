import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: rootView
    visible: vm.rootIsVisible
    color: "transparent"

    ColumnLayout {
        anchors.horizontalCenter: rootView.horizontalCenter
        anchors.top: rootView.top
        anchors.topMargin: 30
        spacing: 10

        Text {
            text: "TODO list"
            font.bold: true
            font.pointSize: 24
            Layout.alignment: Qt.AlignHCenter
        }

        Button {
            text: "Add item"
            onClicked: api.rootSet(F.didClickAddItem, true)
            Layout.alignment: Qt.AlignHCenter
        }

        ListView {
            id: listView
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.leftMargin: 16
            Layout.rightMargin: 16
            model: vm.rootItems
            spacing: 8
            delegate: RootViewItem {
                width: listView.width
            }
        }
    }
}
