import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: rootViewItem
    required property var model
    height: contentLayout.implicitHeight + 40
    radius: 12
    color: "white"
    border.color: "#EEEEEE"
    border.width: 1

    RowLayout {
        id: contentLayout
        anchors.fill: parent
        anchors.margins: 20
        spacing: 8

        Text {
            text: model.id.toString().padStart(2, "0")
            font.pointSize: 12
            color: "gray"
            Layout.preferredWidth: 28
        }

        Text {
            text: model.title
            font.pointSize: 16
            font.weight: Font.Medium
            Layout.fillWidth: true
        }
    }
}
