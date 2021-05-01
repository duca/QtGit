import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.2
import QtQuick.Controls 2.12

Item {
    width: 1024
    height: 768
    anchors.top: parent

    TabView {
        id: tabView
        Layout.minimumWidth: 1024

        Tab {
            title: qsTr("Stage")
            source: "qml/Stage.qml"
        }
        Tab {
            title: qsTr("Repository Mgmt")
            source: "qml/Repository.qml"
        }
    }
}
