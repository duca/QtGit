import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

ItemDelegate {
    id: delegate

    checkable: true

    contentItem: GridLayout {
        columnSpacing: 0
        rowSpacing: 0
        columns: 2
        width: 40

        Label {
            text: commitId
            font.bold: true
            elide: Text.AlignLeft
            Layout.fillWidth: false
        }

        Label {
            text: description
            elide: Text.ElideRight
            Layout.fillWidth: false
        }

        GridLayout {
            id: grid
            visible: false

            columns: 2
            rowSpacing: 10
            columnSpacing: 10
            Label {
                text: qsTr("Commit:")
            }

            Label {
                text: longCommitId
                font.bold: true
                elide: Text.ElideRight
                Layout.fillWidth: true
            }

            Label {
                text: qsTr("UserName:")
            }

            Label {
                text: userName
                font.bold: true
                elide: Text.ElideRight
                Layout.fillWidth: true
            }

            Label {
                text: qsTr("Email:")
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
