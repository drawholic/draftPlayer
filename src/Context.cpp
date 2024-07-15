#include "Context.hpp"

Song::Song(QString name, QString author, QUuid id, QObject *parent)
    : QObject(parent), m_name(name), m_author(author), m_id(id) {}

Song::Song(const Song &other)
    : QObject(other.parent()), m_name(other.m_name), m_author(other.m_author), m_id(other.m_id)
{
}
SongModel::SongModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

Song &Song::operator=(const Song &other)
{
    if (this != &other)
    {
        m_name = other.m_name;
        m_author = other.m_author;
        m_id = other.m_id;
    }
    return *this;
}

int SongModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_songs.count();
}

QVariant SongModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_songs.count())
        return QVariant();

    const Song &song = m_songs.at(index.row());

    switch (role)
    {
    case Qt::DisplayRole + 1:
        return song.getName();
    case Qt::DisplayRole + 2:
        return song.getAuthor();
    case Qt::DisplayRole + 3:
        return song.getUuid();

    default:
        return QVariant();
    }
}

QHash<int, QByteArray> SongModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::DisplayRole + 1] = "name";
    roles[Qt::DisplayRole + 2] = "author";
    roles[Qt::DisplayRole + 3] = "id";

    return roles;
}

void SongModel::addSong(const Song &song)
{
    beginInsertRows(QModelIndex(), m_songs.count(), m_songs.count());
    m_songs.append(song);
    endInsertRows();
}
int SongModel::count()
{
    return m_songs.count();
}