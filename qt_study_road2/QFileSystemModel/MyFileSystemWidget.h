#include <QFileSystemModel>
#include <QTreeView>
#include <QDebug>

class MyFileSystemWidget : public QWidget
{
    Q_OBJECT
public:
    MyFileSystemWidget(QWidget *parent = 0);

private slots:
    void mkdir();
    void rm();

private:
    QFileSystemModel *model;
    QTreeView *treeView;
};
