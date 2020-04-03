#include <QListView>
#include <QStringListModel>
#include <QSortFilterProxyModel>
#include <QComboBox>

class MySortView : public QWidget
{
    Q_OBJECT
public:
    MySortView();

private:
    QListView *view;
    QStringListModel *model;
    QSortFilterProxyModel *modelProxy;
    QComboBox *syntaxBox;

private slots:
    void filterChanged(const QString &text);
};
