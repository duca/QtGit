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

        GridLayout {
            id: headerGrid
            visible: true
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
        }

        GridLayout {
            id: grid
            visible: false

            columns: 2
            rowSpacing: 10
            columnSpacing: 10
            Label {
                text: qsTr("Commit:")
                font.bold: true
            }

            Label {
                text: longCommitId
                elide: Text.ElideRight
                Layout.fillWidth: true
            }

            Label {
                text: qsTr("Description:")
                font.bold: true
            }

            Label {
                text: description
                elide: Text.ElideRight
                Layout.fillWidth: true
            }

            Label {
                text: qsTr("UserName:")
                font.bold: true
            }

            Label {
                text: userName
                elide: Text.ElideRight
                Layout.fillWidth: true
            }

            Label {
                text: qsTr("Email:")
                font.bold: true
            }

            Label {
                text: userEmail
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

            PropertyChanges {
                target: headerGrid
                visible: false
            }
        }
    ]
}
