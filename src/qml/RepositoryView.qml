import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Item {
    id: repositoryView
    visible: false

    RowLayout {
        id: row

        GridLayout {
            id: grid
            columns: 2
            rowSpacing: 10
            columnSpacing: 10
            Label {
                id: nameLabel
                text: qsTr("Repository Name")
                font.bold: true
            }

            TextEdit {
                id: nameEdit
            }

            Label {
                id: remoteLabel
                text: qsTr("Repository Name")
                font.bold: true
            }
            TextEdit {
                id: remoteEdit
            }
        }

        Label {
            text: qsTr("Auto generate the following:")

            CheckBox {
                id: generateReadmeCheck
                text: qsTr("README.md")
            }

            CheckBox {
                id: generateGitIgnoreCheck
                text: qsTr(".gitignore")
            }

            CheckBox {
                id: generateLicensemeCheck
                text: qsTr("LICENSE.md")
            }
        }
    }
}
