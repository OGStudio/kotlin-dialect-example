import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: rootView
    visible: vm.rootIsVisible
    color: "#FAFAFA"

    // Use a Column for the static header items to size naturally
    Column {
        id: header
        anchors.top: parent.top
        anchors.topMargin: 30
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10
        width: parent.width

        Text {
            text: "TODO list"
            font.bold: true
            font.pointSize: 24
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            text: "Add item"
            onClicked: api.rootSet(F.didClickAddItem, true)
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    // Anchor the ListView to cleanly fill the remaining space of the screen
    ListView {
        id: listView
        anchors.top: header.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: 20
        anchors.bottomMargin: 16
        anchors.leftMargin: 16
        anchors.rightMargin: 16
        model: vm.rootItems
        spacing: 8
        clip: true // Prevents items from overflowing visually when scrolled
        delegate: RootViewItem {
            width: listView.width
        }
    }
}