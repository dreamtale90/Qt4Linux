#include "TableMimeData.h"
#include <QApplication>
#include <QMimeData>
#include <QDrag>
#include <QByteArray>
#include <QAbstractItemModel>
#include <QTableWidgetSelectionRange>
#include <QModelIndex>
#include <QStringList>


TableMimeData::TableMimeData(const QTableWidget *tableWidget,
                             const QTableWidgetSelectionRange &range)
{
    dataTableWidget = tableWidget;
    selectionRange = range;
    dataFormats << "text/csv" << "text/html";
}

QVariant TableMimeData::retrieveData(const QString &format,
                                     QVariant::Type preferredType) const
{
    if (format == "text/csv") {
        return toCsv(selectionText());
    } else if (format == "text/html") {
        return toHtml(selectionText());
    } else {
        return QMimeData::retrieveData(format, preferredType);
    }
}

QString TableMimeData::selectionText() const
{
    QString selectionString;
    QString headerString;
    QAbstractItemModel *itemModel = model();
    QTableWidgetSelectionRange selection = selectedRanges().at(0);
    for (int row = selection.topRow(), firstRow = row;
         row <= selection.bottomRow(); row++) {
        for (int col = selection.leftColumn();
             col <= selection.rightColumn(); col++) {
            if (row == firstRow) {
                headerString.append(horizontalHeaderItem(col)->text()).append("\t");
            }
            QModelIndex index = itemModel->index(row, col);
            selectionString.append(index.data().toString()).append("\t");
        }
        selectionString = selectionString.trimmed();
        selectionString.append("\n");
    }
    return headerString.trimmed() + "\n" + selectionString.trimmed();
}

QString TableMimeData::toHtml(const QString &plainText) const
{
#if QT_VERSION >= 0x050000
    QString result = plainText.toHtmlEscaped();
#else
    QString result = Qt::escape(plainText);
#endif
    result.replace("\t", "<td>");
    result.replace("\n", "\n<tr><td>");
    result.prepend("<table>\n<tr><td>");
    result.append("\n</table>");
    return result;
}

QString TableMimeData::toCsv(const QString &plainText) const
{
    QString result = plainText;
    result.replace("\\", "\\\\");
    result.replace("\"", "\\\"");
    result.replace("\t", "\", \"");
    result.replace("\n", "\"\n\"");
    result.prepend("\"");
    result.append("\"");
    return result;
}

void TableMimeData::fromCsv(const QString &csvText)
{
    QStringList rows = csvText.split("\n");
    QStringList headers = rows.at(0).split(", ");
    for (int h = 0; h < headers.size(); ++h) {
        QString header = headers.at(0);
        headers.replace(h, header.replace('"', ""));
    }
    setHorizontalHeaderLabels(headers);
    for (int r = 1; r < rows.size(); ++r) {
        QStringList row = rows.at(r).split(", ");
        setItem(r - 1, 0, new QTableWidgetItem(row.at(0).trimmed().replace('"', "")));
        setItem(r - 1, 1, new QTableWidgetItem(row.at(1).trimmed().replace('"', "")));
    }
}
