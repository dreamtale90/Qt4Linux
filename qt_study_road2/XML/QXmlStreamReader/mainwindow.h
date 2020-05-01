#include <QMainWindow>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QXmlStreamReader>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool readFile(const QString &fileName);
private:
    void readBookindexElement();
    void readEntryElement(QTreeWidgetItem *parent);
    void readPageElement(QTreeWidgetItem *parent);
    void skipUnknownElement();

    QTreeWidget *treeWidget;
    QXmlStreamReader reader;
};
