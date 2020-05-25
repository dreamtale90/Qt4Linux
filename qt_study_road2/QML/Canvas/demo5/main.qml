import QtQuick 2.6

Canvas {
    id: root
    width: 280; height: 120
    onPaint: {
        var ctx = getContext("2d")

        // 绘制图像
        ctx.drawImage('assets/earth.png', 10, 10)

        // 保存当前状态
        ctx.save()
        // 平移坐标系
        ctx.translate(100,0)
        ctx.strokeStyle = 'red'
        // 创建裁剪范围
        ctx.beginPath()
        ctx.moveTo(10,10)
        ctx.lineTo(55,10)
        ctx.lineTo(35,55)
        ctx.closePath()
        ctx.clip()  // 根据路径裁剪
        // 绘制图像并应用裁剪
        ctx.drawImage('assets/earth.png', 10, 10)
        // 绘制路径
        ctx.stroke()
        // 恢复状态
        ctx.restore()
    }

    Component.onCompleted: {
        loadImage("assets/earth.png")
    }
}
