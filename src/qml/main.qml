import QtQuick.Dialogs
import QtQuick.Controls 2.12
import com.test.LogModel 1.0
import com.test.MainWindow 1.0
import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Universal 2.12

ApplicationWindow {
    id: appWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("QtGit - a Git client using Qt")

    Universal.theme: Universal.Dark
    Universal.accent: Universal.Teal

    property int currentEntry: -1
    property string errorMessage: ""

    signal openRepoPathDialog
    signal cherryPick(string id)
    signal branchOut(string id)
    signal revertCommit(string id)
    signal createNewRepo(string name, string url, bool genReadme, bool genLicense, bool genIgnore)

    menuBar: MenuBar {
        Menu {
            id: fileMenu
            title: qsTr("File")

            MenuItem {
                id: sshkey
                text: qsTr("SSH Key")
                onTriggered: keyfileDialog.open()
            }

            MenuItem {
                text: qsTr("Quit")
                onTriggered: close()
            }
        }

        Menu {
            title: qsTr("Local")
            id: mainFlowMenu

            MenuItem {
                id: commit
                text: qsTr("Commit")
            }

            MenuItem {
                id: merge
                text: qsTr("Merge")
            }

            MenuItem {
                id: stash
                text: qsTr("Stash")
            }

            MenuItem {
                id: log
                text: qsTr("Log")
            }

            MenuItem {
                id: rebase
                text: qsTr("Rebase")
            }

            MenuItem {
                id: revert
                text: qsTr("Revert")
            }

            MenuItem {
                id: createNew
                text: qsTr("Create new repo")
                // onTriggered: openDialog.open()
            }
        }

        Menu {
            title: qsTr("Remote")
            id: repoConfig

            MenuItem {
                id: addFolder
                text: qsTr("Add existing folder")
                onTriggered: {
                    appWindow.openRepoPathDialog()
                    logView.visible = true
                    noRepoLabel.visible = false
                }
            }

            MenuItem {
                id: clone
                text: qsTr("Clone")
            }

            MenuItem {
                id: setRemote
                text: qsTr("Set Remote")
                //  onTriggered: saveDialog.open()
            }
            MenuItem {
                id: changeRemote
                text: qsTr("Change Remote")
            }

            MenuItem {
                id: submodules
                text: qsTr("Submodules")
            }
        }
        Menu {
            title: qsTr("Help")
            id: helpMenu

            MenuItem {
                id: about
                text: qsTr("About")
            }

            MenuItem {
                id: shortcuts
                text: qsTr("Keyboard Shortcuts")
            }

            MenuItem {
                id: help
                text: qsTr("Github")
            }
        }
    }

    Label {
        id: noRepoLabel
        text: qsTr("No repository configured")
        visible: true
    }

    GitLogView {
        id: logView
        anchors.fill: parent
        model: GitLogModel
        visible: false
    }
    Connections {
        target: logView
        function onPressAndHold(index) {
            currentEntry = index
            logEntryMenu.open()
            console.log("Long press detected")
        }
    }

    Menu {
        id: logEntryMenu
        x: parent.width / 2 - width / 2
        y: parent.height / 2 - height / 2
        modal: true

        Label {
            padding: 10
            font.bold: true
            width: parent.width
            horizontalAlignment: Qt.AlignHCenter
            text: currentEntry >= 0 ? logView.model.get(
                                          currentEntry).commitId : ""
        }
        MenuItem {
            text: qsTr("Branch out")
            onTriggered: appWindow.branchOut(logView.model.get(
                                                 currentEntry).commitId)
        }

        MenuItem {
            text: qsTr("Cherry pick")
            onTriggered: appWindow.cherryPick(logView.model.get(
                                                  currentEntry).commitId)
        }

        MenuItem {
            text: qsTr("Revert")
            onTriggered: appWindow.revertCommit(logView.model.get(
                                                    currentEntry).commitId)
        }
    }

    RepositoryView {
        id: repositoryView
        width: parent.width
        height: parent.height / 2
        onAccepted: {
            appWindow.createNewRepo(repositoryView.name, repositoryView.url,
                                    repositoryView.genReadme,
                                    repositoryView.genLicense,
                                    repositoryView.genIgnore)
        }
    }

    Dialog {
        id: errorDialog
        title: qsTr("Error!")
        width: 120
        modal: true
        standardButtons: Dialog.Ok | Dialog.Cancel
        contentItem: Rectangle {
            Label {
                text: errorMessage
            }
        }
    }

    Connections {
        target: MainWindow
        function onCreateNewRepo(path) {
            console.log("Enable repository view")
            console.log(path)
            repositoryView.open()
        }
    }

    Connections {
        target: MainWindow
        function onReportError(message) {
            errorMessage = message
            errorDialog.open()
        }
    }
}
