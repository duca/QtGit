import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

ItemDelegate {
    id: delegate

    checkable: true

    contentItem: GridLayout {
        columns: 2

        Label {
            text: commitId
            font.bold: true
            elide: Text.ElideRight
            Layout.fillWidth: false
        }

        Label {
            text: description
            elide: Text.ElideRight
            Layout.fillWidth: true
        }

        GridLayout {
            id: grid
            visible: false

            columns: 2
            rowSpacing: 10
            columnSpacing: 10

            Label {
                text: qsTr("Commit:")
                Layout.leftMargin: 60
            }

            Label {
                text: longCommitId
                font.bold: true
                elide: Text.ElideRight
                Layout.fillWidth: true
            }

            Label {
                text: qsTr("UserName:")
                Layout.leftMargin: 60
            }

            Label {
                text: userName
                font.bold: true
                elide: Text.ElideRight
                Layout.fillWidth: true
            }

            Label {
                text: qsTr("Email:")
                Layout.leftMargin: 60
            }

            Label {
                text: userEmail
                font.bold: true
                elide: Text.ElideRight
                Layout.fillWidth: true
            }
        }
    }

    states: [
        State {
            name: "expanded"
            when: delegate.checked

            PropertyChanges {
                target: grid
                visible: true
            }
        }
    ]
}
