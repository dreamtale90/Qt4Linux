#include <QApplication>
#include <QString>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>
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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //SELECT * FROM student WHERE age > 20 and age < 25
    if (connect("demo.db")) {
        QSqlTableModel model;
        model.setTable("student");
        model.setFilter("age > 20 and age < 25");
        if (model.select()) {
            for (int i = 0; i < model.rowCount(); ++i) {
                QSqlRecord record = model.record(i);
                QString name = record.value("name").toString();
                int age = record.value("age").toInt();
                qDebug() << name << ": " << age;
            }
        }
    } else {
        return 1;
    }

    //INSERT INTO student (name, age) VALUES ('Cheng', 24)
    {
        QSqlTableModel model;
        model.setTable("student");
        int row = 0;
        model.insertRows(row, 1);
        model.setData(model.index(row, 1), "Cheng");
        model.setData(model.index(row, 2), 24);
        model.submitAll();
    }

    //UPDATE student SET age = 26 WHERE age = 25
    {
        QSqlTableModel model;
        model.setTable("student");
        model.setFilter("age = 25");
#if 1
        if (model.select()) {
            if (model.rowCount() == 1) {
                QSqlRecord record = model.record(0);
                record.setValue("age", 26);
                model.setRecord(0, record);
                model.submitAll();
            }
        }
#else
        if (model.select()) {
            if (model.rowCount() == 1) {
                model.setData(model.index(0, 2), 26);
                model.submitAll();
            }
        }
#endif
    }

    //DELETE FROM student WHERE age = 25
    {
        QSqlTableModel model;
        model.setTable("student");
        model.setFilter("age = 25");
        if (model.select()) {
            if (model.rowCount() == 1) {
                model.removeRows(0, 1);
                model.submitAll();
            }
        }
    }
    return a.exec();
}
