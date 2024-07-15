#ifndef AUTHENTICATION_HPP
#define AUTHENTICATION_HPP

#include <QObject>
#include <QString>

class User : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username MEMBER username READ getUsername NOTIFY usernameChanged);
    Q_PROPERTY(QString password MEMBER password READ getPassword NOTIFY passwordChanged);
    Q_PROPERTY(bool isAuthenticated MEMBER authenticated READ isAuthenticated NOTIFY authenticatedChanged);

public:
    User(QObject *parent = nullptr);
    User(const User &other);
    ~User() {};

    const QString &getUsername() const;
    const QString &getPassword() const;

    bool isAuthenticated() const;

    User &operator=(const User &other);

    void setUsername(QString &name);
    void setUsername(QString &&name);

    void setPassword(QString &pass);
    void setPassword(QString &&pass);

    void setAuthenticated(bool v);

signals:
    void authenticatedChanged();
    void usernameChanged();
    void passwordChanged();

private:
    QString username;
    QString password;
    bool authenticated;
};

class Auth : public QObject
{
    Q_OBJECT
public:
    explicit Auth(QObject *parent = nullptr);
    ~Auth() {};
    void setUser(const User &user);
    void auth(QString &username, QString &password);
    User &getUser();

private:
    User u;
};

#endif