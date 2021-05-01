import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.2
import QtQuick.Controls 2.12
import QtQuick.Templates 2.15
import Qt3D.Extras 2.15

Item {
    id: content

    width: 400
    height: 400

    SplitView {
        id: splitView

        TreeView {
            id: fileTree
        }
    }
}
