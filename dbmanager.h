#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>

class DBManager : public QObject
{
    Q_OBJECT
public:
    explicit DBManager(QObject *parent = nullptr);

signals:

};

#endif // DBMANAGER_H
