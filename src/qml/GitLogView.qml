import QtQuick 2.12
import QtQuick.Controls 2.12

ListView {
    id: logView
    anchors.fill: parent
    focus: true

    signal pressAndHold(int index)

    delegate: GitLogDelegate {
        id: delegate
        width: logView.width
        onPressAndHold: logView.pressAndHold(index)
    }
    model: GitLogModel

    section.property: "type"
    section.criteria: ViewSection.FullString
    section.delegate: GitLogHeaderDelegate {
        id: headerDelegate
    }

    ScrollBar.vertical: ScrollBar {}
}
