#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <QAbstractListModel>
#include <QString>
#include <QUuid>
#include <QObject>

class Song : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name MEMBER m_name READ getName);
    Q_PROPERTY(QString author MEMBER m_author READ getAuthor);
    Q_PROPERTY(QUuid id MEMBER m_id CONSTANT READ getUuid)

public:
    Song(QString name = QString(), QString author = QString(), QUuid id = QUuid(), QObject *parent = nullptr);
    Song(const Song &s);
    Song &operator=(const Song &other);
    void setName(QString &name) { m_name = name; };
    void setName(QString &&name) { m_name = name; };

    void setAuthor(QString &author) { m_author = author; };
    void setAuthor(QString &&author) { m_author = author; };

    void setUuid(QUuid &&uid) { m_id = uid; };
    void setUuid(QUuid &uid) { m_id = uid; };

    const QString &getName() const { return m_name; }
    const QString &getAuthor() const { return m_author; }
    const QUuid &getUuid() const { return m_id; }

private:
    QString m_name;
    QString m_author;
    QUuid m_id;
};

class SongModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit SongModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void fill_data();
    void addSong(const Song &song);
    int count();

private:
    QList<Song> m_songs;
};

#endif // CONTEXT_HPP
