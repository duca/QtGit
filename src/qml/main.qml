import QtQuick.Dialogs
import QtQuick.Controls
import com.test.LogModel 1.0
import QtQuick
import QtQuick.Layouts

ApplicationWindow {
    id: appWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("QtGit - a Git client using Qt")

    signal loadGitFolder(path: string)

    menuBar: MenuBar {
        Menu {
            id: fileMenu
            title: qsTr("File")

            MenuItem {
                id: shortcuts
                text: qsTr("Keyboard Shortcuts")
            }

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
            title: qsTr("Main flow")
            id: mainFlowMenu

            MenuItem {
                id: commit
                text: qsTr("Commit")
            }

            MenuItem{
                id: merge
                text: qsTr("Merge")
            }

            MenuItem{
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
        }

        Menu {
            title: qsTr("Repo Config")
            id:repoConfig

            MenuItem {
                id: addFolder
                text: qsTr("Add existing folder")
                onTriggered: repoDialog.open()
            }

            MenuItem {
                id: clone
                text: qsTr("Clone")
            }

            MenuItem {
                id: createNew
                text: qsTr("Create new repo")
                // onTriggered: openDialog.open()
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
        Menu
        {
            title: qsTr("Help")
            id: helpMenu

            MenuItem {
                id: about
                text: qsTr("About")
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

    Dialog {
        id: repoDialog
        RowLayout {

            Label {
                text: qsTr ("Repository Path:")
            }
            TextField {
                id: pathInput
                placeholderText: qsTr("")
            }
        }
        standardButtons: Dialog.Ok | Dialog.Cancel
        onAccepted: {
            logView.visible = true
            noRepoLabel.visible = false
            loadGitFolder(pathInput.text)
        }
    }

}

