#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QCoreApplication>

#include "sqltablemodel.h"

class DBManager : public QObject
{
    Q_OBJECT
public:
    DBManager();
    ~DBManager();
    int showRecCounter() const;
    void setShowRecCounter(int showRecCounter);
    QSqlTableModel *getLastRecordsModel();
public slots:
    void addNewRecord(DeviceRecord* rec);
    void processDevicesIDRequest();
signals:
    void sendDevicesID(QStringList);

private:
    int m_showRecCounter;
    QSqlDatabase m_db;
    SqlTableModel* m_currentModel;
    QString DBCurrentPath = DB_DEFAULT_PATH;
};

#endif // DBMANAGER_H
