#ifndef TABLE_MIME_DATA_H
#define TABLE_MIME_DATA_H
#include <QMimeData>
#include <QTableWidget>
#include <QTableWidgetSelectionRange>
#include <QStringList>
#include <QString>
#include <QVariant>

class TableMimeData : public QMimeData
{
    Q_OBJECT
public:
    TableMimeData(const QTableWidget *tableWidget,
                  const QTableWidgetSelectionRange &range);
    const QTableWidget *tableWidget() const
    {
        return dataTableWidget;
    }
    QTableWidgetSelectionRange range() const
    {
        return selectionRange;
    }
    QStringList formats() const
    {
        return dataFormats;
    }
protected:
    QVariant retrieveData(const QString &format,
                          QVariant::Type preferredType) const;
private:
    static QString toHtml(const QString &plainText);
    static QString toCsv(const QString &plainText);
    QString text(int row, int column) const;
    QString selectionText() const;

    const QTableWidget *dataTableWidget;
    QTableWidgetSelectionRange selectionRange;
    QStringList dataFormats;
};
#endif //TABLE_MIME_DATA_H
