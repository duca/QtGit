import QtQuick 2.0
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Dialog {
    id: repositoryView
    title: qsTr("New Repository")
    standardButtons: Dialog.Ok | Dialog.Cancel
    modal: false

    property bool genReadme: false
    property bool genLicense: false
    property bool genIgnore: false
    property string name: ""
    property string url: ""

    onAccepted: {
        genReadme = (generateReadmeCheck.checkState == Qt.Checked) ? true : false
        genLicense = (generateLicensemeCheck.checkState == Qt.Checked) ? true : false
        genIgnore = (generateGitIgnoreCheck.checkState == Qt.Checked) ? true : false
        name = nameEdit.text
        url = remoteEdit.text
    }

    onRejected: console.log("Cancel clicked")

    contentItem: Rectangle {

        ColumnLayout {
            GridLayout {
                id: grid
                columns: 2
                //            rowSpacing: 10
                //            columnSpacing: 10
                Label {
                    id: nameLabel
                    text: qsTr("Repository Name:")
                }

                TextField {
                    id: nameEdit
                    wrapMode: TextEdit.Wrap
                    focus: true
                    width: 150
                }

                Label {
                    id: remoteLabel
                    text: qsTr("Remote url:")
                }
                TextField {
                    id: remoteEdit
                    wrapMode: TextEdit.Wrap
                    width: 150
                }
            }
            Label {
                text: qsTr("Auto generate the following:")
                font.bold: true
            }
            GridLayout {
                id: otherGrid
                columns: 3

                CheckBox {
                    id: generateReadmeCheck
                    text: qsTr("README.md")
                }

                CheckBox {
                    id: generateLicensemeCheck
                    text: qsTr("LICENSE.md")
                }

                CheckBox {
                    id: generateGitIgnoreCheck
                    text: qsTr(".gitignore")
                }
            }
        }
    }
}
