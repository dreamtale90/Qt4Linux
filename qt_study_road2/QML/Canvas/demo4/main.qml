import QtQuick 2.6

Canvas {
    id: root
    width: 280; height: 120
    onPaint: {
        var ctx = getContext("2d")
        // 背景矩形
        ctx.strokeStyle = "#333"
        ctx.fillRect(0, 0, root.width, root.height);
        // 设置阴影属性
        ctx.shadowColor = "blue";
        ctx.shadowOffsetX = 2;
        ctx.shadowOffsetY = 2;
        ctx.shadowBlur = 10;
        // 设置字体并绘制
        ctx.font = 'bold 80px sans-serif';
        ctx.fillStyle = "#33a9ff";
        ctx.fillText("Earth", 30, 80);
    }
}
