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
            id: blue1
            width: 48; height: 24
            y: 8
            anchors.horizontalCenter: parent.horizontalCenter
        }
        BlueRectangle {
            id: blue2
            width: 72; height: 24
            anchors.top: blue1.bottom
            anchors.topMargin: 4
            anchors.horizontalCenter: blue1.horizontalCenter
        }
    }
}
