#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <QObject>
#include <Qt>
#include "DBConnection.hpp"
#include "Authentication.hpp"
#include "Playback.hpp"
#include "Context.hpp"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

class ControllerDatabaseBase
{
};

class ControllerSignalsBase : public QObject
{
    Q_OBJECT
public:
    ControllerSignalsBase(QObject *parent = nullptr) : QObject(parent) {};

public slots:
    virtual void handleLoginButton(QString username, QString password);
};

class Controller : public ControllerSignalsBase, public ControllerDatabaseBase
{
    Q_OBJECT
private:
    QQmlApplicationEngine *engine;
    QGuiApplication *app;
    QObject *rootObject;
    DBConnection *connection;
    Auth auth;
    SongModel songModel;

    QObject *findChildByName(QObject *parent, const QString &name);

public:
    Controller(int argc, char *argv[], QObject *parent = nullptr);
    ~Controller();
    int start();

public slots:
    void handleUpdateSongsList();
    void handleLoginButton(QString username, QString password) override;
    void updateLoaderComponent();
};

#endif