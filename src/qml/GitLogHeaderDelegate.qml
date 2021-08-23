import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Component {
    id: headerDelegate

    Rectangle {
        width: container.width
        height: childrenRect.height
        color: "black"

        required property string section

        Text {
            text: parent.section
            font.bold: true
            font.pixelSize: 18
            color: "black"
        }
    }
}
