// LineEdit.qml

import QtQuick 2.0

FocusScope {
    width: 96;
    height: input.height + 8
    //color: "lightsteelblue"
    //border.color: "gray"

    property alias text: input.text
    property alias input: input

    Rectangle {
        anchors.fill:parent
        color:"lightsteelblue"
        border.color: "gray"
    }

    TextInput {
        id: input
        anchors.fill: parent
        anchors.margins: 4
        focus: true
    }
}
