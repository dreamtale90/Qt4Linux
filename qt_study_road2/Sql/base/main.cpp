#include <QApplication>
#include <QString>
#include <QSqlDatabase>
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
    qDebug() << QSqlDatabase::drivers();

    if (connect("demo.db")) {
        QSqlQuery query;
        if (!query.exec("CREATE TABLE IF NOT EXISTS student ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "name VARCHAR,"
                        "age INT)")) {
            QMessageBox::critical(0, QObject::tr("Database Error"),
                                  query.lastError().text());
            return 1;
        }
    } else {
        return 1;
    }

    if (connect("demo.db")) {
        QSqlQuery query;
        query.prepare("INSERT INTO student (name, age) VALUES (?, ?)");
        QVariantList names;
        names << "Tom" << "Jack" << "Jane" << "Jerry";
        query.addBindValue(names);
        QVariantList ages;
        ages << 20 << 23 << 22 << 25;
        query.addBindValue(ages);
        if (!query.execBatch()) {
            QMessageBox::critical(0, QObject::tr("Database Error"),
                    query.lastError().text());
        }
        query.finish();
        query.exec("SELECT name, age FROM student");
        while (query.next()) {
            QString name = query.value(0).toString();
            int age = query.value(1).toInt();
            qDebug() << name << ": " << age;
        }
    } else {
        return 1;
    }

    return a.exec();
}
