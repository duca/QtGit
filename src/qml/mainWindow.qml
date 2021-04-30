import QtQuick 2.12
import QtQuick.Controls 2.15
import QtQuick.Window 2.0

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("QtGit - a Git client using Qt")

    menuBar: MenuBar {

        Menu {
            title: qsTr("File")

            Action {
                id: shortcuts
                text: qsTr("Keyboard Shortcuts")
            }
            Action {
                text: qsTr("Quit")
                onTriggered: close()
            }
        }

        Menu {
            title: qsTr("Main flow")

            Action {
                id: commit
                text: qsTr("Commit")
            }

            Action{
                id: merge
                text: qsTr("Merge")
            }

            Action{
                id: stash
                text: qsTr("Stash")
            }

            Action {
                id: log
                text: qsTr("Log")
            }

            Action {
                id: rebase
                text: qsTr("Rebase")
            }

            Action {
                id: revert
                text: qsTr("Revert")
            }
        }

        Menu {
            title: qsTr("Repo Config")

            Action {
                id: addFolder
                text: qsTr("Add existing folder")
                onTriggered: openDialog.open()
            }

            Action {
                id: clone
                text: qsTr("Clone")
            }

            Action {
                id: createNew
                text: qsTr("Create new repo")
                onTriggered: openDialog.open()
            }

            Action {
                id: setRemote
                text: qsTr("Set Remote")
                onTriggered: saveDialog.open()
            }
            Action {
                id: changeRemote
                text: qsTr("Change Remote")
            }

            Action {
                id: submodules
                text: qsTr("Submodules")
            }
        }

        Menu
        {
            title: qsTr("Help")

            Action {
                id: about
                text: qsTr("About")
            }

            Action {
                id: help
                text: qsTr("Help")
            }

        }
    }
}
