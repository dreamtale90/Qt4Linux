import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    id: root
    width: 220
    height: 220
    color: "black"

    GreenRectangle {
        x: 10
        y: 10
        width: 100
        height: 100
        BlueRectangle {
            width: 48
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.horizontalCenterOffset: -12
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}
