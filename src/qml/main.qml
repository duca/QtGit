import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.0
import QtQuick.Layouts 1.12
import com.test.LogModel 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("QtGit - a Git client using Qt")

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

            MenuItem {
                id: addFolder
                text: qsTr("Add existing folder")
                //   onTriggered: openDialog.open()
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

    GitLogView {
        id: logView
        anchors.fill: parent
        model: GitLogModel
         Layout.minimumWidth: 800
         Layout.minimumHeight: 480
         Layout.preferredWidth: 768
         Layout.preferredHeight: 480
         visible: true
     }
 }
