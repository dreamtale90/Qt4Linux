import QtQuick 2.6

Column {
    spacing: 2
    Repeater {
        model: 10
        Rectangle {
            width: 100
            height: 20
            radius: 3
            color: "lightBlue"
            Text {
                anchors.centerIn: parent
                text: index
            }
        }
    }
}
