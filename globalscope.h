#ifndef GLOBALSCOPE_H
#define GLOBALSCOPE_H

#include <QSqlTableModel>
#include <QSqlDriver>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQueryModel>

#include <QString>
#include <QDebug>
#include <QDateTime>
#include <QObject>
#include <QFile>
#include <QDir>
#include <QIcon>
#include <QThread>
#include <QCalendarWidget>

#define TEXT(x) tr(x)
#define DB_DEFAULT_PATH QString("D:\\Uni\\masterwork\\db\\GTCT_DB.db")
#define UI_MODEL ui->tv_mainTableView->model()
#define UI_TABLE ui->tv_mainTableView

struct DeviceRecord {
    int       uniqueId;
    QString   uniqueName;
    QString   carNumber;
    QString   logFileName;
    QDateTime lastOpenDate;
    QDateTime lastCloseDate;
    bool      isNowOpen;
};

#endif // GLOBALSCOPE_H
