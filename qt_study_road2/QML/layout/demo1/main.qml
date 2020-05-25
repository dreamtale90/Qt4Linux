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
            width: 12
            anchors.fill: parent
            anchors.margins: 8
        }
    }
}
