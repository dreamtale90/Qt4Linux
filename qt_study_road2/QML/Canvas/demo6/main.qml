import QtQuick 2.6

Canvas {
    id: root
    width: 240; height: 120
    onPaint: {
        var ctx = getContext("2d")
        ctx.strokeStyle = "blue"
        ctx.lineWidth = 4

        ctx.translate(120, 60)
        ctx.strokeRect(-20, -20, 40, 40)

        // draw path now rotated
        ctx.strokeStyle = "green"
        ctx.rotate(Math.PI / 4)
        ctx.strokeRect(-20, -20, 40, 40)
        ctx.restore()
    }
}
