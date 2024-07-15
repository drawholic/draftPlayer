#include "Authentication.hpp"

User::User(QObject *parent) : QObject(parent)
{
    username = QString();
    password = QString();
    authenticated = false;
};
User::User(const User &other)
{
    username = other.getUsername();
    password = other.getPassword();
    authenticated = other.isAuthenticated();

    emit authenticatedChanged();
};
const QString &User::getUsername() const
{
    return username;
}
const QString &User::getPassword() const
{
    return password;
};

bool User::isAuthenticated() const
{
    return authenticated;
};
void User::setUsername(QString &name)
{
    username = name;
    emit usernameChanged();
};

void User::setUsername(QString &&name)
{
    username = name;
    emit usernameChanged();
};
void User::setAuthenticated(bool v)
{
    authenticated = v;
    emit authenticatedChanged();
}
void User::setPassword(QString &pass)
{
    password = pass;
    emit passwordChanged();
};

void User::setPassword(QString &&pass)
{
    password = pass;
    emit passwordChanged();
};

User &User::operator=(const User &other)
{
    if (this != &other)
    {
        username = other.username;
        password = other.password;
        authenticated = other.authenticated;
        emit authenticatedChanged();
    }
    return *this;
}

Auth::Auth(QObject *parent) : QObject(parent)
{
    u = User();
};

void Auth::setUser(const User &user)
{
    u = user;
};

void Auth::auth(QString &username, QString &password) {

};

User &Auth::getUser()
{
    return u;
}