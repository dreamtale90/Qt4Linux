import QtQuick 2.6

Canvas {
    id: root
    width: 120; height: 120
    onPaint: {
        var ctx = getContext("2d")
        ctx.fillStyle = 'green'
        ctx.strokeStyle = "blue"
        ctx.lineWidth = 4

        // 填充矩形
        ctx.fillRect(20, 20, 80, 80)
        // 裁减掉内部矩形
        ctx.clearRect(30,30, 60, 60)
        // 从左上角起，到外层矩形中心绘制一个边框
        ctx.strokeRect(20,20, 40, 40)
    }
}
