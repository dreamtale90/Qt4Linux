#include <QApplication>
#include <QString>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTableView>
#include <QAbstractItemView>
#include <QHeaderView>
#include <QSqlRelation>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

bool connect(const QString &dbName)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setHostName("host");
//    db.setDatabaseName("dbname");
//    db.setUserName("username");
//    db.setPassword("password");
    db.setDatabaseName(dbName);
    if (!db.open()) {
        QMessageBox::critical(0, QObject::tr("Database Error"),
                              db.lastError().text());
        return false;
    }
    return true;
}

enum ColumnIndex
{
    ColumnID_ID = 0,
    ColumnID_Name = 1,
    ColumnID_Age = 2,
    ColumnID_City = 3
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << QSqlDatabase::drivers();

    if (connect("demo.db")) {
        QSqlQuery query;
        if (!query.exec("PRAGMA foreign_keys = ON;")) {
            QMessageBox::critical(0, QObject::tr("Database Error"),
                    query.lastError().text());
            return 1;
        }
    } else {
        return 1;
    }

    //QSqlTableModel *model = new QSqlTableModel(&a);
    QSqlRelationalTableModel *model = new QSqlRelationalTableModel(&a);
    model->setTable("student");
    model->setSort(ColumnID_Name, Qt::AscendingOrder);
    model->setHeaderData(ColumnID_Name, Qt::Horizontal, "Name");
    model->setHeaderData(ColumnID_Age, Qt::Horizontal, "Age");
    model->setHeaderData(ColumnID_City, Qt::Horizontal, "City");
    model->setRelation(ColumnID_City, QSqlRelation("city", "id", "name"));
    model->select();

    QTableView *view = new QTableView();
    view->setModel(model);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->resizeColumnsToContents();

    QHeaderView *header = view->horizontalHeader();
    header->setStretchLastSection(true);

    view->show();
    return a.exec();
}
