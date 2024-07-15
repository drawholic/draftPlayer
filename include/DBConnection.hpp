#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <QObject>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTextStream>
#include <QSqlQuery>
#include <QFile>
#include <QSqlError>
#include "Context.hpp"
#include "Authentication.hpp"

class DBConnection : QObject
{
    Q_OBJECT
private:
    QSqlDatabase db;
    QSqlTableModel *songTable;
    QSqlTableModel *userTable;

    void init_tables();
    void init_table(const char *path);
    void insert_song(Song &s);
    void retrieve_song(QUuid uid);

public:
    explicit DBConnection(QObject *parent = nullptr);
    QSqlTableModel *getSongModel() const { return songTable; };
    QSqlTableModel *getUserModel() const { return userTable; };

    User retrieve_user(QUuid uid);
    User retrieve_user(QString username, QString password);
};

#endif