import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 200
    height: 80
    color: "linen"

    LineEdit {
        id: input1
        x: 8; y: 8
        width: 96; height: 20
        focus: true
        text: "Text Input 1"
        KeyNavigation.tab: input2
    }

    LineEdit {
        id: input2
        x: 8; y: 36
        width: 96; height: 20
        text: "Text Input 2"
        KeyNavigation.tab: input1
    }
}
