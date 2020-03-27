#include <QStringListModel>
#include <QListView>
#include <QDebug>

class MyListView : public QWidget
{
    Q_OBJECT
public:
    MyListView(QWidget *parent = 0);

private slots:
    void insertData();
    void deleteData();
    void showData();

private:
    QStringListModel *model;
    QListView *listView;
};
