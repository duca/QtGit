import QtQuick 2.12
import QtQuick.Controls 2.12
ListView {
    id: gitLogView

    width: 320
    height: 480

    focus: true
    boundsBehavior: Flickable.StopAtBounds

    delegate: GitLogDelegate {
        id: delegate
        //width: listView.width
        //onPressAndHold: listView.pressAndHold(index)        
    }
    model: GitLogModel
}
