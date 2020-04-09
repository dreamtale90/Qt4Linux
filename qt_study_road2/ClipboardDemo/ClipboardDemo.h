#ifndef CLIP_BOARD_DEMO_H
#define CLIP_BOARD_DEMO_H
#include <QWidget>

class ClipboardDemo : public QWidget
{
    Q_OBJECT
public:
    ClipboardDemo(QWidget *parent = 0);
private slots:
    void setClipboardContent();
    void getClipboardContent();
};
#endif //CLIP_BOARD_DEMO_H
