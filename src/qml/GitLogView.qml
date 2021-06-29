import QtQuick 2.12
import QtQuick.Controls 2.12
ListView {
    id: logView
    anchors.fill: parent
    focus: true

    delegate: GitLogDelegate {
        id: delegate
    }
    model: GitLogModel
}
