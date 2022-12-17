#ifndef SQLTABLEMODEL_H
#define SQLTABLEMODEL_H

#include "globalscope.h"

class SqlTableModel : public QSqlTableModel {

    Q_OBJECT
public:
    SqlTableModel(QObject *parent, QSqlDatabase db);

    int limit() const;
    void setLimit(int limit);
    bool addNewRecord(DeviceRecord*);

protected:
    QString selectStatement() const;

private:
    int m_limit;
};

#endif // SQLTABLEMODEL_H
