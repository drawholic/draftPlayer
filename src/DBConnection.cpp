#include "DBConnection.hpp"

DBConnection::DBConnection(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    if (!db.isValid())
    {
        qDebug() << "Failure: database is not valid";
    }

    db.setDatabaseName("db.db");
    if (!db.open())
    {
        perror("during opening db");
        exit(-1);
    }
    init_tables();

    songTable = new QSqlTableModel;
    songTable->setTable("song");
    songTable->select();

    userTable = new QSqlTableModel;
    userTable->setTable("user");
    userTable->select();
};

void DBConnection::insert_song(Song &s)
{
    QSqlQuery query;
    query.prepare("INSERT INTO song (name, author) VALUES (:name, :author) ");
    query.bindValue(":name", s.getName());
    query.bindValue(":author", s.getAuthor());

    query.exec();
};

void DBConnection::init_tables()
{
    init_table("../src/sql_queries/init_users.sql");
    init_table("../src/sql_queries/init_songs.sql");
}

void DBConnection::init_table(const char *path)
{

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "failure reading init_tables.sql";
        return;
    };

    QTextStream in(&file);
    QString fileBody = in.readAll();
    file.close();

    QSqlQuery query;
    if (!query.exec(fileBody))
    {
        qDebug() << "failure on executing init tables query: " << query.lastError();
    };
};

User DBConnection::retrieve_user(QString username, QString password)
{
    QSqlQuery query;
    User user;
    QString queryString = "SELECT * FROM user WHERE username = :name AND password = :password;";

    query.prepare(queryString);
    query.bindValue(":name", username);
    query.bindValue(":password", password);

    if (!query.exec())
    {
        qDebug() << "failure on retrieving user: " << query.lastError().text();
        return user;
    }
    if (query.next())
    {
        user.setUsername(query.value("username").toString());
        user.setPassword(query.value("password").toString());
        user.setAuthenticated(true);
    }
    else
    {
        qDebug() << "no user found";
    }

    return user;
}