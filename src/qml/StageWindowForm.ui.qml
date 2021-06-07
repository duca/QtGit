import QtQuick 2.4
import QtQuick.Controls 2.15
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.12
import QtQuick.Extras 1.4

Item {
    width: 648
    height: 480

    Rectangle {
        color: "#ffffff"
        GridLayout {
            id: gridLayout
            anchors.fill: parent
            columns: 3
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.9}
}
##^##*/

