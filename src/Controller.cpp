#include "Controller.hpp"
#include "utilities.hpp"
#include <QSqlRecord>

void ControllerSignalsBase::handleLoginButton(QString username, QString password)
{
    qDebug() << "Username: " << username << ", password: " << password;
};

void Controller::handleLoginButton(QString username, QString password)
{
    User user = connection->retrieve_user(username, password);
    if (user.isAuthenticated())
    {
        auth.setUser(user);
    }
    else
    {
        qDebug() << "login failure: invalid username or password";
    }
}

Controller::Controller(int argc, char *argv[], QObject *parent) : ControllerSignalsBase(parent)
{
    app = new QGuiApplication(argc, argv);
    engine = new QQmlApplicationEngine();

    connection = new DBConnection();

    engine->rootContext()->setContextProperty("songModel", &songModel);
    engine->rootContext()->setContextProperty("User", &auth.getUser());

    engine->load(QUrl(path));

    if (engine->rootObjects().isEmpty())
    {
        qDebug() << "Failure on loading file: " << path;
        return;
    };

    rootObject = engine->rootObjects().first();

    if (rootObject)
    {
        QObject *likedSongs = findChildByName(rootObject, "likedSongsButton");
        qDebug() << "root object exists";
        if (likedSongs)
        {
            QObject::connect(likedSongs, SIGNAL(updateSongsList()), this, SLOT(handleUpdateSongsList()));
            qDebug() << "liked songs exists";
        }
        else
        {
            qDebug() << "failure on finding likedSongs object";
            return;
        }
        QObject *loginButton = findChildByName(rootObject, "loginButton");
        if (loginButton)
        {
            qDebug() << "loginButton found";
            QObject::connect(loginButton, SIGNAL(loginClicked(QString, QString)), this, SLOT(handleLoginButton(QString, QString)));
        }

        QObject::connect(&auth.getUser(), &User::authenticatedChanged, this, &Controller::updateLoaderComponent);
    }
    else
    {
        qDebug() << "Failure on finding root object";
        return;
    }

    QObject::connect(engine, &QQmlApplicationEngine::quit,
                     app, &QGuiApplication::quit);
};

Controller::~Controller()
{
    delete app;
    delete rootObject;
}

int Controller::start()
{
    return app->exec();
}

void Controller::handleUpdateSongsList()
{
    if (songModel.count() > 0)
    {
        return;
    }
    int count = connection->getSongModel()->rowCount();
    Song s;
    QSqlRecord r;

    for (int i = 0; i < count; i++)
    {
        r = connection->getSongModel()->record(i);

        s.setAuthor(r.value("author").toString());
        s.setName(r.value("name").toString());
        s.setUuid(r.value("id").toUuid());

        songModel.addSong(s);
    };
};

void Controller::updateLoaderComponent()

{
    qDebug() << "update loader component called";

    QObject *loginLoader = findChildByName(rootObject, "loginLoader");
    if (loginLoader)
    {
        loginLoader->setProperty("sourceComponent", auth.getUser().isAuthenticated() ? QVariant::fromValue(findChildByName(rootObject, "mainComponent")) : QVariant::fromValue(findChildByName(rootObject, "loginComponent")));
    }
}

QObject *Controller::findChildByName(QObject *parent, const QString &name)
{
    if (!parent)
    {
        return nullptr;
    }

    if (parent->objectName() == name)
    {
        return parent;
    }

    foreach (QObject *child, parent->children())
    {
        QObject *result = findChildByName(child, name);
        if (result)
        {
            return result;
        }
    }

    return nullptr;
}
